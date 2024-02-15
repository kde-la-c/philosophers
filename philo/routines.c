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
	// take forks
	while (inst->data->st_fork[inst->lfork] || inst->data->st_fork[inst->rfork])
		usleep(0);
	pthread_mutex_lock(&inst->data->forks[inst->lfork]);
	inst->data->st_fork[inst->lfork] = 1;
	print_tstamp(inst, TAKE_FORK);
	pthread_mutex_lock(&inst->data->forks[inst->rfork]);
	inst->data->st_fork[inst->rfork] = 1;
	print_tstamp(inst, TAKE_FORK);

	// eat
	print_tstamp(inst, EAT);
	inst->lastmeal = get_tstamp() - inst->data->starttime;
	ft_msleep(inst->data->t_eat);
	inst->ate++;

	// leave forks
	pthread_mutex_unlock(&inst->data->forks[inst->rfork]);
	inst->data->st_fork[inst->rfork] = 0;
	pthread_mutex_unlock(&inst->data->forks[inst->lfork]);
	inst->data->st_fork[inst->lfork] = 0;
	ft_msleep(5);
}

void	*check_lifeline(void *arg)
{
	t_main	*data;

	data = (t_main *)arg;
	while (!data->death)
	{
		ft_msleep(5);
	}
	pthread_mutex_lock(&data->print);
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
	instance.lfork = instance.id;
	if (instance.id == instance.data->nb_philos)
		instance.rfork = 1;
	else
		instance.rfork = instance.id + 1;
	pthread_mutex_lock(&instance.data->start);
	pthread_mutex_unlock(&instance.data->start);
	while (i++ < instance.data->loops || !instance.data->loops)
	{
		if (instance.id % 2 == 1)
		{
			eat(&instance);
			// print_tstamp(&instance, SLEEP);
			// ft_msleep(instance.data->t_sleep);
		}
		else
		{
			usleep(300);
			eat(&instance);
			// print_tstamp(&instance, SLEEP);
			// ft_msleep(instance.data->t_sleep);
		}
	}
	instance.data->meals += instance.ate;
	return (NULL);
}
