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

/* static int	brodonteat(t_philo *philo)
{
	int	now;

	now = get_tstamp() - philo->data->starttime;
	if (philo->meals)
		if ()
} */

static int	eat(t_philo *philo)
{
	// take forks

	// printf("tstamp: %i, lastmeal+t_death: %i", get_tstamp(), philo->lastmeal + philo->data->t_death);
	if ((!philo->meals && (get_tstamp() - philo->data->starttime) > philo->data->t_death)
		|| (philo->meals && (get_tstamp() - philo->data->starttime) > philo->lastmeal + philo->data->t_death))
	{
		pthread_mutex_lock(&philo->data->stop);
		philo->data->dead = philo->id;
		pthread_mutex_unlock(&philo->data->stop);
		return (EXIT_FAILURE);
	}
	if (pthread_mutex_lock(&philo->data->forks[philo->lforkid]))
		return (EXIT_FAILURE);
	print_tstamp(philo, TAKE_FORK);
	if (pthread_mutex_lock(&philo->data->forks[philo->rforkid]))
		return (EXIT_FAILURE);
	print_tstamp(philo, TAKE_FORK);

	// eat
	philo->lastmeal = get_tstamp() - philo->data->starttime;
	print_tstamp(philo, EAT);
	ft_msleep(philo->data->t_eat);
	philo->meals++;
	// print_tstamp(philo, FINISH);

	// leave forks
	pthread_mutex_unlock(&philo->data->forks[philo->rforkid]);
	pthread_mutex_unlock(&philo->data->forks[philo->lforkid]);

	return (EXIT_SUCCESS);
}

void	*routine(void *data)
{
	int			i;
	t_philo		*philo;

	i = 0;
	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->data->start);
	pthread_mutex_unlock(&philo->data->start);
	if (philo->id % 2 == 1)
		usleep(50);
	while (i++ < philo->data->loops || !philo->data->loops)
	{
		if (eat(philo) == EXIT_FAILURE)
		{
			if (!philo->data->dead)
				philo->data->dead = philo->id;
			return (NULL);
		}
		ft_msleep(philo->data->t_sleep);
	}
	return (NULL);
}
