/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudias <marvin@42lausanne.ch>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:54:09 by gudias            #+#    #+#             */
/*   Updated: 2022/01/12 04:56:40 by gudias           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int	check_duplicate(char **argv)
{
	int	i;

	while (*argv)
	{
		i = 1;
		while (*(argv + i))
		{	
			if (atoi(*argv) == atoi(*(argv + i)))
				return (1);
			i++;
		}
		argv++;
	}
	return (0);	
		
}

int	check_args(char **argv)
{
	int	i;

	while (*argv)
	{
		i = 0;
		while ((*argv)[i])
		{
			if (!isdigit((*argv)[i]))
				return (1);
			i++;
		}
		argv++;	
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 2)
	{
		argv++;
		if (check_args(argv) || check_duplicate(argv))
			printf("wrong argument or duplicate\n");
		else
			printf("nb ok\n");
		while (*argv)
		{	
			printf("%s\n", *argv);
			argv++;
		}
	}
	else
		write(1, "Bad args\n", 8);
	return (0);
}
