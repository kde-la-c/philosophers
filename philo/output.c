/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:06:28 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/10/14 21:06:31 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	print_error(char *msg)
{
	printf("%s\n", msg);
	return (EXIT_FAILURE);
}

void	print_tstamp(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->data->print);
	if (status == TAKE_FORK)
		printf(STATUS, get_tstamp() - philo->data->starttime,
			philo->id, "has taken a fork");
	else if (status == EAT)
		printf(STATUS, get_tstamp() - philo->data->starttime,
			philo->id, "is eating");
	else if (status == SLEEP)
		printf(STATUS, get_tstamp() - philo->data->starttime,
			philo->id, "is sleeping");
	else if (status == THINK)
		printf(STATUS, get_tstamp() - philo->data->starttime,
			philo->id, "is thinking");
	else if (status == DIE)
		printf(STATUS, get_tstamp() - philo->data->starttime,
			philo->id, "died");
	pthread_mutex_unlock(&philo->data->print);
}
