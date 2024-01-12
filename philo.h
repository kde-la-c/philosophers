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

typedef struct s_main
{
	int				nb_philos;
	pthread_t		*philos;
	pthread_mutex_t	*forks;
	int				*st_fork;
	pthread_mutex_t	start;
	pthread_mutex_t	stop;
	pthread_mutex_t	print;
	int				t_eat;
	int				t_sleep;
	int				t_death;
	int				loops;
	int				starttime;
}	t_main;

typedef struct s_inst
{
	int		id;
	t_main	*data;
}	t_inst;

/* PARSING */
int		parsing(t_main *data, int argc, char **argv);

/* OUTPUT */
int		print_error(char *msg);

/* CORE */
int		philosophers(t_main *data);

/* DESTROY */
void	free_struct(t_main *data);
int		dest_mutexes(t_main	*data);

/* UTILS */
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
int		ft_putnbr_fd(int n, int fd);

#endif
