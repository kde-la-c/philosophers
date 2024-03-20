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

	now = now(philo->data);
	if (philo->meals)
		if ()
} */

static int	eat(t_philo *phi)
{
	// take forks

	if ((!phi->meals && now(phi->data) > phi->data->t_death)
		|| (phi->meals && now(phi->data) > phi->lastmeal + phi->data->t_death))
	{
		pthread_mutex_lock(&phi->data->stop);
		phi->data->dead = phi->id;
		pthread_mutex_unlock(&phi->data->stop);
		return (EXIT_FAILURE);
	}
	if (pthread_mutex_lock(&phi->data->forks[phi->lforkid]))
		perror("lock");
	print_tstamp(phi, TAKE_FORK);
	if (pthread_mutex_lock(&phi->data->forks[phi->rforkid]))
		perror("lock");
	print_tstamp(phi, TAKE_FORK);

	// eat
	phi->lastmeal = now(phi->data);
	// printf("%i meals - ", phi->meals);
	print_tstamp(phi, EAT);
	ft_msleep(phi->data->t_eat);
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
			return (NULL);
		else if (j == 2)
		{
			philo->data->dead = -1;
			return (NULL);
		}
		ft_msleep(philo->data->t_sleep);
	}
	return (NULL);
}
