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
	int	i;
	int	*args;

	i = 0;
	args = (int *)malloc(sizeof(int) * argc);
	if (read_args(argc, argv))
	{
		write(2, "invalid args\n", 13);
		free(args);
		return (1);
	}
	while (++i < argc)
	{
		args[i - 1] = ft_atoi(argv[i]);
	}
	args[i - 1] = -1;
	spawner(args);	
	return (0);
}
