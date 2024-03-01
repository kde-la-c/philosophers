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

typedef pthread_mutex_t	t_mtx;
typedef pthread_t		t_thd;
typedef struct s_philo	t_philo;

typedef struct s_main
{
	int		nb_philos;
	t_philo	**philos;
	t_mtx	*forks;
	int		*st_fork;
	t_mtx	start;
	t_mtx	stop;
	t_mtx	print;
	int		t_eat;
	int		t_sleep;
	int		t_death;
	int		loops;
	int		starttime;
}	t_main;

typedef struct s_philo
{
	int		id;
	t_thd	*thd;
	int		lastmeal;
	t_mtx	*lfork;
	int		lforkid;
	t_mtx	*rfork;
	int		rforkid;
	int		meals;
	t_main	*data;
}	t_philo;

/* PARSING */
int		parsing(t_main *data, int argc, char **argv);
int		read_args(int argc, char **argv);

/* OUTPUT */
int		print_error(char *msg);
void	print_tstamp(t_philo *philo, int status);

/* CORE */
int		philosophers(t_main *data);
void	*routine(void *philo);

/* DESTROY */
void	free_struct(t_main *data, int i);
int		dest_mutexes(t_main	*data);
int		join_threads(t_main *data);

/* UTILS */
int		ft_isdigit(int c);
void	ft_bzero(void *s, size_t n);
int		get_tstamp(void);
void	ft_msleep(int sleeptime);

#endif
