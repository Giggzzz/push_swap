/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:54:09 by gudias            #+#    #+#             */
/*   Updated: 2022/01/17 04:42:03 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	check_duplicate(char **argv)
{
	int	i;

	while (*argv)
	{
		i = 1;
		while (*(argv + i))
		{	
			if (ft_atoi(*argv) == ft_atoi(*(argv + i)))
				return (1);
			i++;
		}
		argv++;
	}
	return (0);	
		
}

int	check_args(char **argv)
{
	while (*argv)
	{
		if (ft_strncmp(*argv, "0", 2) && !ft_atoi(*argv)) 
			return (1);
		argv++;	
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		argv++;
		if (check_args(argv))
			ft_printf("wrong argument\n");
		else if (check_duplicate(argv))
			ft_printf("duplicate\n");
		else
			ft_printf("nb ok\n");
		while (*argv)
		{	
			ft_printf("%s\n", *argv);
			argv++;
		}
	}
	else
		ft_putstr_fd("Bad args nb\n", 1);
	return (0);
}
