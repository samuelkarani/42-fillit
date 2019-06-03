/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 22:15:30 by smbaabu           #+#    #+#             */
/*   Updated: 2019/03/27 23:41:46 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int check_for_neighbors(int board_size, int a, int b, int horizontal)
{
	if (horizontal == 1)
		return (a - b == 1 && b % board_size != 0);
	return (a / board_size - b / board_size == 1 && a % board_size == b % board_size);
}

int num_neighbors(int *piece, int board_size, int i)
{
	int j;
	int a;
	int b;
	int count;

	j = 0;
	count = 0;
	while (j < PIECE_SIZE)
	{
		if (i != j)
		{
			if (i > j)
			{
				a = piece[i];
				b = piece[j];
			}
			else
			{
				a = piece[j];
				b = piece[i];
			}
			if (check_for_neighbors(board_size, a, b, 1) == 1)
				count++;
			if (check_for_neighbors(board_size, a, b, 0) == 1)
				count++;
		}
		j++;
	}
	return (count);
}

int	check_invalid_piece(int *piece, int board_size)
{
	int i;

	i = 0;
	while (i < PIECE_SIZE)
	{
		if (num_neighbors(piece, board_size, i) != piece[i + PIECE_SIZE])
			return (1);
		i++;
	}
	return (0);
}

int check_for_collision(int *board, int *piece)
{
	int i;
	int j;

	i = 1;
	while (board[i])
	{
		j = 0;
		while (j < PIECE_SIZE)
		{
			if (board[i] == piece[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}