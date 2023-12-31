/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:57:55 by ababdelo          #+#    #+#             */
/*   Updated: 2023/07/03 15:47:34 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_philo
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_meals;
	int				meals;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
	pthread_mutex_t	incr;
	int				id;
	long			start_time;
	pthread_t		*thread;
	long			time;
	int				eat_nb;
	long			*last_time_eat;
}					t_philo;

int		init_args(int ac, char **av, t_philo *philo);
int		init_philo(t_philo *philo);

int		isnbrdigit(char *av);
int		check_validity(char *av);
int		check(int ac, char **av);

long	get_time(void);
void	ft_usleep(int times);
int		time_to_die(t_philo *philo);

void	philo_activities(t_philo *philo, pthread_mutex_t *right,
			pthread_mutex_t *left, int id);
void	*philo_life(void *arg);
int		create_th(t_philo *philo);
int		ft_atoi(const char *str);
int		get_errors(int err);

#endif
