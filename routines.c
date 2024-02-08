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
	// take forks
	while (inst->data->st_fork[fork1] || inst->data->st_fork[fork2])
		usleep(1);
	pthread_mutex_lock(&inst->data->forks[fork1]);
	inst->data->st_fork[fork1] = 1;
	print_tstamp(inst, "picked a fork");
	pthread_mutex_lock(&inst->data->forks[fork2]);
	inst->data->st_fork[fork2] = 1;
	print_tstamp(inst, "picked a fork");

	// eat
	print_tstamp(inst, "is eating");
	ft_msleep(inst->data->t_eat);
	inst->ate++;

	// leave forks
	pthread_mutex_unlock(&inst->data->forks[fork2]);
	inst->data->st_fork[fork1] = 0;
	pthread_mutex_unlock(&inst->data->forks[fork1]);
	inst->data->st_fork[fork2] = 0;
	// print_tstamp(inst, "released forks");
}

void	*check_lifeline(void *arg)
{
	t_main	*data;

	data = (t_main *)arg;
	while (!data->death)
	{
		ft_msleep(5);
	}
	killall(data);
	return (NULL);
}

void	*routine(void *data)
{
	int			i;
	static int	id = 0;
	t_inst		instance;

	i = 0;
	id += 1;
	instance.data = (t_main *)data;
	instance.id = id;
	instance.ate = 0;
	pthread_mutex_lock(&instance.data->start);
	pthread_mutex_unlock(&instance.data->start);
	//TODO infinite boucle pour alterner le sommeil et la bouffe selon les tours
	while (i++ < instance.data->loops || !instance.data->loops)
	{
		if (instance.id / 2 == 1)
		{
			eat(&instance);
		}
		else
		{
			ft_msleep(instance.data->t_eat / 2);
			eat(&instance);
		}
	}
	return (NULL);
}
