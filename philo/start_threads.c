/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:28:55 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/12/15 14:28:58 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutexes(t_main *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL))
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_mutex_init(&data->start, NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&data->stop, NULL))
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&data->print, NULL))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	everyonesatisfied(t_main *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		if (data->philos[i]->meals != data->loops)
			return (EXIT_FAILURE);
	return (printf("All meals taken\n"), EXIT_SUCCESS);
}

static int	areyouguysok(t_main *data)
{
	while (everyonesatisfied(data) == EXIT_FAILURE)
	{
		pthread_mutex_lock(&data->stop);
		if (data->dead > 0)
		{
			print_tstamp(data->philos[data->dead - 1], DIE);
			pthread_mutex_unlock(&data->stop);
			return (EXIT_FAILURE);
		}
		else if (data->dead == -1)
		{
			pthread_mutex_unlock(&data->stop);
			return (EXIT_FAILURE);
		}
		else
			pthread_mutex_unlock(&data->stop);
		usleep(100);
	}
	return (EXIT_SUCCESS);
}

int	philosophers(t_main *data)
{
	int		i;

	if (init_mutexes(data) == EXIT_FAILURE)
		return (perror("init_mutexes"), EXIT_FAILURE);
	pthread_mutex_lock(&data->start);
	i = -1;
	while (++i < data->nb_philos)
		if (pthread_create(data->philos[i]->thd, NULL, routine,
				(void *)data->philos[i]))
			return (perror("pthread_create_philos"), EXIT_FAILURE);
	data->starttime = get_tstamp();
	pthread_mutex_unlock(&data->start);
	i = areyouguysok(data);
	join_threads(data);
	dest_mutexes(data);
	return (i + (i && data->dead));
}
