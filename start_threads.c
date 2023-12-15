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

/**
 * TODO find a more coherent way to handle arguments, memory and errors
 * What's the best practice ?
*/
static t_inst	*init_structure(t_main *data)
{
	void	*ptr;
	t_inst	ret;

	data->philos = (pthread_t *)malloc(sizeof(pthread_t) * data->nb_philos);
	if (!data->philos)
		return (NULL);
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* data->nb_philos);
	if (!data->forks)
		return (free(data->philos), NULL);
	data->st_fork = (int *)malloc(sizeof(int) * data->nb_philos);
	if (!data->st_fork)
		return (free(data->philos), free(data->forks), NULL);
	ret.data = data;
	ptr = &ret;
	return ((t_inst *)ptr);
}

int	philosophers(t_main *data)
{
	t_inst	*instance;

	instance = init_structure(data);
	if (!instance)
		return (EXIT_FAILURE);
	
	return (EXIT_SUCCESS);
}
