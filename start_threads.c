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

static int	init_structure(t_inst *inst, t_main *data)
{
	data->philos = (pthread_t *)malloc(sizeof(pthread_t) * data->nb_philos);
	if (!data->philos)
		return (free_struct(data), EXIT_FAILURE);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->nb_philos);
	if (!data->forks)
		return (free_struct(data), EXIT_FAILURE);
	data->st_fork = (int *)malloc(sizeof(int) * data->nb_philos);
	if (!data->st_fork)
		return (free_struct(data), EXIT_FAILURE);
	inst->data = data;
	return (EXIT_SUCCESS);
}

static int	init_mutexes(t_main *data)
{
	int	i;
	
	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_init(&(data->forks[i]), NULL) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_mutex_init(&data->start, NULL) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&data->stop, NULL) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pthread_mutex_init(&data->print, NULL) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	philosophers(t_main *data)
{
	t_inst	instance;

	if (init_structure(&instance, data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (init_mutexes(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
