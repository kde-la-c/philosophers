/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:09:36 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/10/03 19:09:38 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	main(int argc, char **argv)
{
	int	*args;

	args = NULL;
	if (parsing(args, argc, argv) == EXIT_FAILURE)
		return (print_error("Error\nInvalid input\n"));
	return (0);
}
