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

static int	init_structure(t_philo *philo, t_main *data)
{
	data->thds = (pthread_t *)malloc(sizeof(pthread_t) * data->nb_philos);
	if (!data->thds)
		return (free_struct(data), EXIT_FAILURE);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->nb_philos);
	if (!data->forks)
		return (free_struct(data), EXIT_FAILURE);
	data->st_fork = (int *)malloc(sizeof(int) * data->nb_philos);
	if (!data->st_fork)
		return (free_struct(data), EXIT_FAILURE);
	philo->data = data;
	return (EXIT_SUCCESS);
}

static int	init_mutexes(t_main *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) == EXIT_FAILURE)
			return (perror("mutex_init"), EXIT_FAILURE);
		i++;
	}
	if (pthread_mutex_init(&data->start, NULL) == EXIT_FAILURE)
		return (perror("mutex_init"), EXIT_FAILURE);
	if (pthread_mutex_init(&data->stop, NULL) == EXIT_FAILURE)
		return (perror("mutex_init"), EXIT_FAILURE);
	if (pthread_mutex_init(&data->print, NULL) == EXIT_FAILURE)
		return (perror("mutex_init"), EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_tstamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	philosophers(t_main *data)
{
	int		i;
	t_philo	philo;

	//TODO init instances here
	if (init_structure(&philo, data) == EXIT_FAILURE)
		return (perror("init_structure"), EXIT_FAILURE);
	if (init_mutexes(data) == EXIT_FAILURE)
		return (perror("init_mutexes"), EXIT_FAILURE);
	pthread_mutex_lock(&data->start);
	i = 0;
	while (++i <= data->nb_philos)
	{
		//TODO poner aqui el delay
		if (pthread_create(&(data->thds[i - 1]), NULL, routine, (void *)data))
			return (perror("pthread_create_philos"), EXIT_FAILURE);
	}
	data->starttime = get_tstamp();
	pthread_mutex_unlock(&data->start);
	join_threads(data);
	dest_mutexes(data);
	printf("%i meals taken\n", data->meals);
	return (EXIT_SUCCESS);
}
