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

	int	perror_exit(char *err)
	{
		perror(err);
		exit(1);
	}

int	print_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	return (EXIT_FAILURE);
}

void	print_tstamp(t_philo *philo, int status)
{
	pthread_mutex_lock(&philo->data->print);
	if (status == 0)
		printf("%ims - %i %s\n", get_tstamp() - philo->data->starttime, philo->id,
			TAKE_FORK);
	else if (status == 1)
		printf("%ims - %i %s\n", get_tstamp() - philo->data->starttime, philo->id,
			EAT);
	else if (status == 2)
		printf("%ims - %i %s\n", get_tstamp() - philo->data->starttime, philo->id,
			SLEEP);
	else if (status == 3)
		printf("%ims - %i %s\n", get_tstamp() - philo->data->starttime, philo->id,
			THINK);
	else if (status == 4)
		printf("%ims - %i %s\n", get_tstamp() - philo->data->starttime, philo->id,
			DIE);
	pthread_mutex_unlock(&philo->data->print);
}
