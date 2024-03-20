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
		printf(STATUS, now(philo->data), philo->id, "has taken a fork");
	else if (status == EAT)
		printf(STATUS, now(philo->data), philo->id, "is eating");
	else if (status == SLEEP)
		printf(STATUS, now(philo->data), philo->id, "is sleeping");
	else if (status == THINK)
		printf(STATUS, now(philo->data), philo->id, "is thinking");
	else if (status == DIE)
	{
		printf(STATUS, now(philo->data), philo->id, "died");
		return ;
	}
	else if (status == FINISH)
		printf(STATUS, now(philo->data), philo->id, "finished eating");
	pthread_mutex_unlock(&philo->data->print);
}
