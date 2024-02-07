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

// n philos
// philo 1 : fork1 & fork2
// philo 2 : fork2 & fork3
// philo n : forkn & fork1

void	eat(t_inst *inst)
{
	int	fork1;
	int	fork2;

	fork1 = inst->id;
	if (inst->id == inst->data->nb_philos)
		fork2 = 1;
	else
		fork2 = inst->id + 1;
	
}

void	*routine(void *data)
{
	static int	id = 0;
	t_inst		instance;

	id += 1;
	instance.data = (t_main *)data;
	instance.id = id;
	pthread_mutex_lock(&instance.data->start);
	pthread_mutex_unlock(&instance.data->start);
	//TODO try splitting philos in 2 or 3 food services (for odd, even and the extra)
	//TODO infinite boucle pour alterner le sommeil et la bouffe selon les tours
	if (instance.id / 2 == 1)
	{
		eat(&instance);
	}
	else
	{
		ft_msleep(50);
		eat(&instance);
	}
	return (NULL);
}
