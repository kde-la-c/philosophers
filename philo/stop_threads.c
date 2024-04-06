/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:10:13 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/12/19 19:10:16 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_struct(t_main *data, int i)
{
	if (data->forks)
		free(data->forks);
	if (data->st_fork)
		free(data->st_fork);
	if (data->philos && i)
	{
		while (--i >= 0)
		{
			if (data->philos[i]->thd)
				free(data->philos[i]->thd);
			free(data->philos[i]);
		}
		free(data->philos);
	}
}

int	dest_mutexes(t_main	*data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_mutex_destroy(&(data->forks[i])) == EXIT_FAILURE)
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_mutex_destroy(&data->start) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pthread_mutex_destroy(&data->stop) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (pthread_mutex_destroy(&data->print) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	join_threads(t_main *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_detach(*data->philos[i]->thd))
		// if (pthread_join(*data->philos[i]->thd, NULL))
			return (perror("pthread_join"), EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
