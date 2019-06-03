/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 20:13:12 by smbaabu           #+#    #+#             */
/*   Updated: 2019/04/01 15:51:10 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*convert_piece(char **piece, int board_size)
{
	int	i;
	int	j;
	int *new_piece;
	int idx;

	new_piece = (int *)malloc(2 * PIECE_SIZE * sizeof(int));
	memset_zero(new_piece, 2 * PIECE_SIZE);
	idx = 0;
	i = 0;
	while (i < PIECE_SIZE)
	{
		j = 0;
		while (j < PIECE_SIZE)
		{
			if (piece[i][j] == BLOCK_CHARACTER)
				new_piece[idx++] = i * PIECE_SIZE + j + 1;
			j++;
		}
		i++;
	}
	while (i < PIECE_SIZE * 2)
	{
		new_piece[i] = num_neighbors(new_piece, PIECE_SIZE, i - PIECE_SIZE);
		i++;
	}
	if (get_first_valid_piece(new_piece, PIECE_SIZE) == 0)
		return (NULL);
	if (board_size != PIECE_SIZE)
		adapt_piece(new_piece, PIECE_SIZE, board_size - PIECE_SIZE);
	return (new_piece);
}

void	move_piece_by(int *piece, int n)
{
	int i;

	i = 0;
	while (i < PIECE_SIZE)
		piece[i++] += n;
}

void	adapt_piece(int *piece, int old_board_size, int growth)
{
	int i;

	i = 0;
	while (i < PIECE_SIZE)
	{
		piece[i] = adapt_piece_to(piece[i], old_board_size, growth);
		i++;
	}
}

int		adapt_piece_to(int n, int old_board_size, int growth)
{
	if (growth == 0)
		return (n);
	if (growth > 0)
		return (n > old_board_size ? n + (n % old_board_size == 0 ? n - 1 : n) / old_board_size * growth : n);
	return (n > old_board_size + growth ? n + (n % old_board_size == 0 ? n - 1 : n) / old_board_size * growth : n);
}

int		*copy_piece_to(int *piece, int old_board_size, int growth)
{
	int *new_piece;
	int i;
	
	i = 0;

	new_piece = (int *)malloc(2 * PIECE_SIZE * sizeof(int));
	i = 0;
	while (i < PIECE_SIZE)
	{
		new_piece[i] = adapt_piece_to(piece[i], old_board_size, growth);
		i++;
	}
	while (i < 2 * PIECE_SIZE)
	{
		new_piece[i] = piece[i];
		i++;
	}
	return (new_piece);
}
