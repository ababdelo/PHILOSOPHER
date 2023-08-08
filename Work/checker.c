/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:00:20 by ababdelo          #+#    #+#             */
/*   Updated: 2023/07/03 15:36:55 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isnbrdigit(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '+')
			i++;
		if (! (av[i] >= '0' && av[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_validity(char *av)
{
	if (!ft_atoi(av))
		return (0);
	return (1);
}

int	check(int ac, char **av)
{
	int	j;

	if (ac < 5 || ac > 6)
		return (get_errors(1));
	j = 1;
	while (av[j])
	{
		if (!isnbrdigit(av[j]) || !check_validity(av[j]))
			return (get_errors(2));
		j++;
	}
	j = 1;
	while (av[j])
	{
		if (ft_atoi(av[j]) < 0)
			return (get_errors(2));
		j++;
	}
	return (0);
}
