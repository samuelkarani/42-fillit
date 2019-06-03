/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 01:39:51 by smbaabu           #+#    #+#             */
/*   Updated: 2019/03/30 20:02:26 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*create_board(int board_size)
{
	int *board;
	int len;

	len = 1 + board_size * board_size;
	board = (int *)malloc(len * sizeof(int));
	memset_zero(board, len);
	board[0] = board_size;
	return (board);
}

int		*add_piece_to_board(int *board, int *piece, int idx)
{
	int i;
	int j;
	int len;
	int board_size;
	int *new_board;

	board_size = board[0];
	len = board_size * board_size + 1;
	new_board = copy_board_to(board, board_size);
	i = 1 + idx * PIECE_SIZE;
	j = 0;
	while (j < PIECE_SIZE)
		new_board[i++] = piece[j++];
	return (new_board);
}

int 	*copy_board_to(int *board, int new_board_size)
{
	int *new_board;
	int i;
	int board_size;
	int len;

	len = 1 + new_board_size * new_board_size;
	new_board = (int *)malloc(len * sizeof(int));
	memset_zero(new_board, len);
	new_board[0] = new_board_size;
	board_size = board[0];
	i = 1;
	while (board[i] && i < 1 + board_size * board_size)
	{
		new_board[i] = adapt_piece_to(board[i], board_size, new_board_size - board_size);
		i++;
	}
	return (new_board);
}

char 	**convert_board(int *board)
{
	char **new_board;
	int board_size;
	int i;
	int idx;

	board_size = board[0];
	new_board = (char **)malloc(board_size * board_size * sizeof(int *));
	i = 0;
	while (i < board_size)
	{
		new_board[i] = (char *)malloc(board_size * sizeof(int));
		memset_emptychar(new_board[i], board_size);
		i++;
	}
	i = 1;
	idx = 0;
	while (board[i] && i < 1 + board_size * board_size)
	{	
		write_to_board(new_board, board_size, &board[i], 'A' + idx++);
		i += PIECE_SIZE;
	}
	return (new_board);
}
