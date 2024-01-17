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

// void	eat(t_inst *data)
// {
	
// }

// void	sleep(t_inst *data)
// {

// }

void	*routine(void *data)
{
	static int	id = 0;
	t_inst		instance;

	id += 1;
	instance.data = (t_main *)data;
	instance.id = id;
	pthread_mutex_lock(&instance.data->start);
	pthread_mutex_unlock(&instance.data->start);
	pthread_mutex_lock(&instance.data->forks[0]);
	ft_msleep(500);
	print_tsatamp(instance.data->starttime, instance.id, "philo living");
	pthread_mutex_unlock(&instance.data->forks[0]);
	return (NULL);
}
