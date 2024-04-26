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
			return (ERR_MTX_INIT);
		i++;
	}
	if (pthread_mutex_init(&data->start, NULL))
		return (ERR_MTX_INIT);
	if (pthread_mutex_init(&data->stop, NULL))
		return (ERR_MTX_INIT);
	if (pthread_mutex_init(&data->print, NULL))
		return (ERR_MTX_INIT);
	return (SUCCESS);
}

static int	everyonesatisfied(t_main *data)
{
	int	i;

	i = -1;
	while (++i < data->nb_philos)
		if (data->philos[i]->meals < data->loops || !data->loops)
			return (ERR_FAILURE);
	return (pthread_mutex_lock(&data->print), SUCCESS);
}

static int	areyouguysok(t_main *data)
{
	while (everyonesatisfied(data))
	{
		pthread_mutex_lock(&data->stop);
		if (data->dead > 0)
		{
			print_tstamp(data->philos[data->dead - 1], DIE);
			pthread_mutex_unlock(&data->stop);
			return (MSG_DEATH);
		}
		else
			pthread_mutex_unlock(&data->stop);
		usleep(100);
	}
	return (SUCCESS);
}

int	philosophers(t_main *data)
{
	int		i;

	if (init_mutexes(data))
		return (ERR_MTX_INIT);
	pthread_mutex_lock(&data->start);
	i = -1;
	while (++i < data->nb_philos)
		if (pthread_create(data->philos[i]->thd, NULL, &routine,
				(void *)data->philos[i]))
			return (ERR_THD_INIT);
	data->starttime = get_tstamp();
	pthread_mutex_unlock(&data->start);
	i = areyouguysok(data);
	join_threads(data);
	dest_mutexes(data);
	return (i);
}
