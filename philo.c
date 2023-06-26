/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:57:49 by ababdelo          #+#    #+#             */
/*   Updated: 2023/06/26 15:25:38 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (get_errors(5));
	if (check(ac, av))
		return (0);
	if (init_args(ac, av, philo))
		return (1);
	if (init_philo(philo))
		return (1);
	if (create_th(philo))
		return (1);
}
