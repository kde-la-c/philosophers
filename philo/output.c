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

int	ft_putendl_fd(char *s, int fd)
{
	int	ret;

	ret = 0;
	while (*s)
		ret += write(fd, s++, 1);
	ret += write(fd, "\n", 1);
	return (ret);
}

int	print_errno(int	retno)
{
	// if (!retno)
	// 	ft_putendl_fd("All meals taken!", 1);
	if (retno != MSG_DEATH)
		ft_putendl_fd("Error", 2);
	if (retno == ERR_ALLOC)
		ft_putendl_fd("Memory allocation problem", 2);
	else if (retno == ERR_ARGS)
		ft_putendl_fd("Bad arguments", 2);
	else if (retno == ERR_MTX_INIT)
		ft_putendl_fd("Bad mutex initialization", 2);
	else if (retno == ERR_THD_INIT)
		ft_putendl_fd("Bad thread initialization", 2);
	return (retno);
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
