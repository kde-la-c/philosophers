/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kde-la-c <kde-la-c@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:09:44 by kde-la-c          #+#    #+#             */
/*   Updated: 2023/10/03 19:09:47 by kde-la-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_data
{
	int				phid;
	long			stsec;
	long			stusec;
	int				*args; // 0 = nbphilos, 1 = ttdie, 2 = tteat, 3 = ttsleep, 5 = nbboucles
	// pthread_mutex_t	*cutlery;
	pthread_mutex_t	cutlery;
}	t_data;

typedef struct s_arg
{
	int		phid;
	void	*data;
}	t_arg;

// read args
int	read_args(int argc, char **argv);

// spawner
int	spawner(int *args);

// output
void	print_tstamp(long stsec, long stusec);

// utils
int	ft_isdigit(int c);
int	ft_atoi(const char *str);

#endif
