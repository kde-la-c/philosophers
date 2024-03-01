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

static void	eat(t_philo *philo)
{
	// take forks
	// while (philo->data->st_fork[philo->lforkid]
	// 	|| philo->data->st_fork[philo->rforkid])
	// 	usleep(100);
	pthread_mutex_lock(&philo->data->forks[philo->lforkid]);
	// philo->data->st_fork[philo->lforkid] = 1;
	print_tstamp(philo, TAKE_FORK);
	pthread_mutex_lock(&philo->data->forks[philo->rforkid]);
	// philo->data->st_fork[philo->rforkid] = 1;
	print_tstamp(philo, TAKE_FORK);

	// eat
	print_tstamp(philo, EAT);
	philo->lastmeal = get_tstamp() - philo->data->starttime;
	ft_msleep(philo->data->t_eat);
	philo->meals++;

	// leave forks
	pthread_mutex_unlock(&philo->data->forks[philo->rforkid]);
	// philo->data->st_fork[philo->rforkid] = 0;
	pthread_mutex_unlock(&philo->data->forks[philo->lforkid]);
	// philo->data->st_fork[philo->lforkid] = 0;
}

void	*routine(void *data)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = (t_philo *)data;
	// pthread_mutex_lock(&philo->data->start);
	// pthread_mutex_unlock(&philo->data->start);
	if (philo->id % 2 == 1)
		usleep(50);
	while (i++ < philo->data->loops || !philo->data->loops)
	{
		eat(philo);
		ft_msleep(philo->data->t_sleep);
	}
	return (NULL);
}
