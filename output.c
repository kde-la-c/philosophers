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

void	print_tsatamp(int basetime)
{
	ft_putnbr_fd(get_tstamp() - basetime, 1);
	write(1, "ms \n", 4);
}
