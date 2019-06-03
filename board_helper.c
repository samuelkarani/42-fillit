/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 01:05:37 by smbaabu           #+#    #+#             */
/*   Updated: 2019/03/30 20:24:01 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	memset_zero(int *board, int len)
{
	int i;

	i = 0;
	while (i < len)
		board[i++] = 0;
}

void	memset_emptychar(char *board, int len)
{
	int i;

	i = 0;
	while (i < len)
		board[i++] = EMPTY_CHARACTER;
}

void 	write_to_board(char **board, int board_size, int *piece, int c)
{
	int i;
	int j;
	int idx;
	
	idx = 0;
	while (idx < PIECE_SIZE)
	{
		i = (piece[idx] - 1) / board_size;
		j = (piece[idx] - 1) % board_size;
		board[i][j] = c;
		idx++;
	}
}
