/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 05:17:57 by gudias            #+#    #+#             */
/*   Updated: 2022/01/20 05:44:26 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicate(char **argv)
{
	int	i;

	while (*argv)
	{
		i = 1;
		while (*(argv + i))
		{
			if (ft_atoi(*argv) == ft_atoi(*(argv + i)))
				return (0);
			i++;
		}
		argv++;
	}
	return (1);
}

static int	check_format(char **argv)
{
	while (*argv)
	{
		if (!ft_isnumber(*argv))
			return (0);
		if (**argv == '+')
			(*argv)++;
		if (ft_strlen(*argv) != ft_strlen(ft_itoa(ft_atoi(*argv))))
			return (0);
		argv++;
	}
	return (1);
}

int	check_args(char **argv)
{
	if (!check_format(argv))
	{
		ft_printf("Wrong argument\n");
		return (0);
	}
	else if (!check_duplicate(argv))
	{
		ft_printf("duplicate\n");
		return (0);
	}
	ft_printf("Args OK\n");
	return (1);
}
