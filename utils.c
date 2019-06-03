/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 20:42:43 by smbaabu           #+#    #+#             */
/*   Updated: 2019/04/01 17:42:05 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int 	bigger(int a, int b)
{
	return (a > b ? a : b);
}

void	free_ints(int **items, int n)
{
	int i;

	if (items == NULL)
		return ;
	i = 0;
	while (i < n)
		free(items[i++]);
	free(items);
}

void	free_chars(char **items, int n)
{
	int i;

	if (items == NULL)
		return ;
	i = 0;
	while (i < n)
		free(items[i++]);
	free(items);
}

void 	print_solution(char **solution, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, solution[i++], n);
		ft_putchar('\n');
	}
}

int		*new_copy_ints(int *A, int size)
{
	int *ret;
	int i;

	ret = (int *)malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		ret[i] = A[i];
		i++;
	}
	return (ret);
}

char	*new_copy_chars(char *A, int size)
{
	char *ret;
	int i;

	ret = (char *)malloc(size * sizeof(char));
	i = 0;
	while (i < size)
	{
		ret[i] = A[i];
		i++;
	}
	return (ret);
}
