/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 01:45:37 by smbaabu           #+#    #+#             */
/*   Updated: 2019/04/01 15:55:20 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		**convert_pieces(char ***pieces, int num_pieces, int board_size)
{
	int	**pieces_int;
	int i;
	
	pieces_int = (int **)malloc(num_pieces * sizeof(int *));
	i = 0;
	while (i < num_pieces)
	{
		pieces_int[i] = convert_piece(pieces[i], board_size);
		i++;
	}
	return (pieces_int);
}

int 	get_first_valid_piece(int *new_piece, int board_size)
{
	int i;

	i = 0;
	while (new_piece[0] > 1)
		move_piece_by(new_piece, -1);
	if (check_invalid_piece(new_piece, board_size) == 0)
		return (1);
	return (get_next_valid_piece(new_piece, board_size, 1));
}

int 	get_next_valid_piece(int *new_piece, int board_size, int move_first)
{
	int i;

	i = 0;
	if (move_first == 0)
		if (check_invalid_piece(new_piece, board_size) == 0)
			return (1);
	while (new_piece[PIECE_SIZE - 1] < board_size * board_size)
	{
		if (move_first > 0)
			move_piece_by(new_piece, 1);
		if (check_invalid_piece(new_piece, board_size) == 0)
			return (1);
	}
	return (0);
}

void	copy_pieces_to(int **new_pieces, int num_pieces, int old_board_size, int growth)
{
	int i;
	int *temp;

	i = 0;
	while (i < num_pieces)
	{
		temp = new_pieces[i];
		new_pieces[i] = copy_piece_to(new_pieces[i], old_board_size, growth);
		free(temp);
		i++;
	}
}

int 	get_piece_index(int **pieces, int num_pieces, int *piece)
{
	int i;
	int j;
	int diff;

	i = 0;
	while (i < num_pieces)
	{
		diff = pieces[i][0] - piece[0];
		j = 1;
		while (j < PIECE_SIZE && pieces[i][j] - piece[j] == diff)
			j++;
		if (j == PIECE_SIZE)
			return (i);
		i++;
	}
	return (-1);
}