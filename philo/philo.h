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
# include <errno.h>

# define TAKE_FORK	0
# define EAT		1
# define SLEEP		2
# define THINK		3
# define DIE		4

typedef struct s_main
{
	//TODO add t_philo array here
	int				nb_philos;
	pthread_t		*thds;
	pthread_mutex_t	*forks;
	int				*st_fork;
	pthread_mutex_t	start;
	int				death;
	pthread_mutex_t	stop;
	pthread_mutex_t	print;
	int				t_eat;
	int				t_sleep;
	int				t_death;
	int				loops;
	int				starttime;

	int				meals;
}	t_main;

typedef struct s_philo
{
	int				id;
	int				lastmeal;
	int				rfork;
	int				lfork;
	t_main			*data;

	int		ate;
}	t_philo;

/* PARSING */
int		parsing(t_main *data, int argc, char **argv);

	int perror_exit(char *err);

/* OUTPUT */
int		print_error(char *msg);
void	print_tstamp(t_philo *philo, int status);

/* CORE */
int		philosophers(t_main *data);
void	*routine(void *philo);

/* DESTROY */
void	free_struct(t_main *data);
int		dest_mutexes(t_main	*data);
int		join_threads(t_main *data);

/* UTILS */
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
int		get_tstamp(void);
void	ft_msleep(int sleeptime);

#endif
