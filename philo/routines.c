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

void	eat(t_philo *philo)
{
	// take forks
	while (philo->data->st_fork[philo->lfork] || philo->data->st_fork[philo->rfork])
		usleep(100);
	pthread_mutex_lock(&philo->data->forks[philo->lfork]);
	philo->data->st_fork[philo->lfork] = 1;
	print_tstamp(philo, 0);
	pthread_mutex_lock(&philo->data->forks[philo->rfork]);
	philo->data->st_fork[philo->rfork] = 1;
	print_tstamp(philo, 0);

	// eat
	print_tstamp(philo, 1);
	philo->lastmeal = get_tstamp() - philo->data->starttime;
	ft_msleep(philo->data->t_eat);
	philo->ate++;

	// leave forks
	pthread_mutex_unlock(&philo->data->forks[philo->rfork]);
	philo->data->st_fork[philo->rfork] = 0;
	pthread_mutex_unlock(&philo->data->forks[philo->lfork]);
	philo->data->st_fork[philo->lfork] = 0;
}

void	*routine(void *data)
{
	int			i;
	static int	id = 0;
	t_philo		philo;

	i = 0;
	id += 1;
	philo.data = (t_main *)data;
	philo.id = id;
	philo.ate = 0;
	philo.lfork = philo.id;
	if (philo.id == philo.data->nb_philos)
		philo.rfork = 1;
	else
		philo.rfork = philo.id + 1;
	pthread_mutex_lock(&philo.data->start);
	pthread_mutex_unlock(&philo.data->start);
	if (philo.id % 2 == 1)
		usleep(100);
	while (i++ < philo.data->loops || !philo.data->loops)
	{
		eat(&philo);
		ft_msleep(philo.data->t_sleep);
	}
	philo.data->meals += philo.ate;
	return (NULL);
}
