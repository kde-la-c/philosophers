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

static int	take_forks(t_philo *phi, t_mtx *fork1, t_mtx *fork2)
{
	pthread_mutex_lock(fork1);
	// if (pthread_mutex_lock(fork1))
	// 	return (perror("lock1"), ERR_FAILURE);
	print_tstamp(phi, TAKE_FORK);
	if (phi->data->nb_philos == 1)
		return (ERR_FAILURE);
	pthread_mutex_lock(fork2);
	// if (pthread_mutex_lock(fork2))
	// 	return (perror("lock2"), ERR_FAILURE);
	print_tstamp(phi, TAKE_FORK);
	return (SUCCESS);
}

static int	eat(t_philo *phi)
{
	int ret;
	// take forks
	if (phi->id % 2)
		ret = take_forks(phi, phi->lfork, phi->rfork);
	else
		ret = take_forks(phi, phi->rfork, phi->lfork);
	
	// eat
	if (ret)
	{
		ft_msleep(phi, phi->data->t_death);
		return (ERR_FAILURE);
	}
	phi->lastmeal = now(phi->data);
	// printf("%i meals - ", phi->meals);
	print_tstamp(phi, EAT);
	ft_msleep(phi, phi->data->t_eat);
	phi->meals++;
	// print_tstamp(phi, FINISH);

	// leave forks
	pthread_mutex_unlock(&phi->data->forks[phi->rforkid]);
	pthread_mutex_unlock(&phi->data->forks[phi->lforkid]);

	return (SUCCESS);
}

void	*routine(void *data)
{
	int			i;
	int			j;
	t_philo		*philo;

	i = 0;
	philo = (t_philo *)data;
	pthread_mutex_lock(&philo->data->start);
	pthread_mutex_unlock(&philo->data->start);
	if (philo->id % 2 == 1)
		usleep(50);
	while (i++ < philo->data->loops || !philo->data->loops)
	{
		j = eat(philo);
		if (j == ERR_FAILURE)
		{
			// dprintf(2, "return\n");
			return (NULL);
		}
		// dprintf(2, "bucle\n");
		ft_msleep(philo, philo->data->t_sleep);
		// dprintf(2, "after\n");
	}
	// dprintf(2, "return\n");
	return (NULL);
}
