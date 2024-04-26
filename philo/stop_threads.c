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
		if (pthread_mutex_destroy(&(data->forks[i])) == ERR_FAILURE)
			return (ERR_FAILURE);
		i++;
	}
	if (pthread_mutex_destroy(&data->stop) == ERR_FAILURE)
		return (ERR_FAILURE);
	if (pthread_mutex_destroy(&data->print) == ERR_FAILURE)
		return (ERR_FAILURE);
	return (SUCCESS);
}

int	join_threads(t_main *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		if (pthread_detach(*data->philos[i]->thd))
			return (ERR_FAILURE);
		i++;
	}
	return (SUCCESS);
}
