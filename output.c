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

int	ft_putnbr_fd(int n, int fd)
{
	int	ret;

	ret = 0;
	if (n < 10)
	{
		n += 48;
		ret += write(fd, &n, 1);
	}
	else if (n > 9)
	{
		ret += ft_putnbr_fd(n / 10, fd);
		ret += ft_putnbr_fd(n % 10, fd);
	}
	return (ret);
}

void	print_tstamp(t_inst *inst, char *status)
{
	pthread_mutex_lock(&inst->data->print);
	ft_putnbr_fd(get_tstamp() - inst->data->starttime, 1);
	write(1, "ms - ", 5);
	ft_putnbr_fd(inst->id, 1);
	write(1, " ", 1);
	write(1, status, ft_strlen(status));
	write(1, "\n", 1);
	pthread_mutex_unlock(&inst->data->print);
}
