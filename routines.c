/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:12:27 by kde-la-c          #+#    #+#             */
/*   Updated: 2024/01/12 12:12:29 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *instance)
{
	static int	id = 0;
	t_main		*data;

	id += 1;
	data = (t_main *)instance;
	pthread_mutex_lock(&data->start);
	pthread_mutex_unlock(&data->start);
	pthread_mutex_lock(&data->forks[0]);
	usleep(500000);
	print_tsatamp(data->starttime);
	pthread_mutex_unlock(&data->forks[0]);
	return (NULL);
}
