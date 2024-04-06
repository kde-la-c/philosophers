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
	if (pthread_mutex_lock(fork1))
		return (perror("lock"), EXIT_FAILURE);
	print_tstamp(phi, TAKE_FORK);
	if (pthread_mutex_lock(fork2))
		return (perror("lock"), EXIT_FAILURE);
	print_tstamp(phi, TAKE_FORK);
	return (EXIT_SUCCESS);
}

static int	eat(t_philo *phi)
{
	// take forks

	// if ((!phi->meals && now(phi->data) > phi->data->t_death)
	// 	|| (phi->meals && now(phi->data) > phi->lastmeal + phi->data->t_death))
	// {
	// 	pthread_mutex_lock(&phi->data->stop);
	// 	phi->data->dead = phi->id;
	// 	pthread_mutex_unlock(&phi->data->stop);
	// 	return (EXIT_FAILURE);
	// }
	if (phi->id % 2)
		take_forks(phi, phi->lfork, phi->rfork);
	else
		take_forks(phi, phi->rfork, phi->lfork);
	// if (pthread_mutex_lock(&phi->lfork))
	// 	perror("lock");
	// print_tstamp(phi, TAKE_FORK);
	// if (pthread_mutex_lock(&phi->rfork))
	// 	perror("lock");
	// print_tstamp(phi, TAKE_FORK);
	
	// eat
	phi->lastmeal = now(phi->data);
	// printf("%i meals - ", phi->meals);
	print_tstamp(phi, EAT);
	ft_msleep(phi, phi->data->t_eat);
	phi->meals++;
	// print_tstamp(phi, FINISH);

	// leave forks
	pthread_mutex_unlock(&phi->data->forks[phi->rforkid]);
	pthread_mutex_unlock(&phi->data->forks[phi->lforkid]);

	return (EXIT_SUCCESS);
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
		if (j == EXIT_FAILURE)
		{
			dprintf(2, "return\n");
			return (NULL);
		}
		else if (j == 2)
		{
			philo->data->dead = -1;
			dprintf(2, "return\n");
			return (NULL);
		}
		dprintf(2, "bucle\n");
		ft_msleep(philo, philo->data->t_sleep);
		dprintf(2, "after\n");
	}
	dprintf(2, "return\n");
	return (NULL);
}
