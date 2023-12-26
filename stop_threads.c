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

void	free_struct(t_main *data)
{
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
	if (data->st_fork)
		free(data->st_fork);
	if (data)
		free(data);
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
