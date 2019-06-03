/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 22:44:55 by smbaabu           #+#    #+#             */
/*   Updated: 2019/04/01 16:44:24 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		connections_numblocks(char **piece)
{
	int i;
	int j;
	int connection;
	int sum_connection;
	int num_blocks;

	num_blocks = 0;
	sum_connection = 0;
	i = 0;
	while (i < 4)
	{
		connection = 0;
		j = 0;
		while (j < 4)
		{
			if (piece[i][j] == BLOCK_CHARACTER)
			{
				if (i < 3 && piece[i + 1][j] == BLOCK_CHARACTER)
					connection++;
				if (i > 0 && piece[i - 1][j] == BLOCK_CHARACTER)
					connection++;
				if (j < 3 && piece[i][j + 1] == BLOCK_CHARACTER)
					connection++;
				if (j > 0 && piece[i][j - 1] == BLOCK_CHARACTER)
					connection++;
				if (connection < 1 || connection > 3)
					return (-1);
				sum_connection += connection;
				connection = 0;
				num_blocks++;
			}
			j++;
		}
		i++;
	}
	if (sum_connection < 6 || sum_connection > 8)
		return (-1);
	return (num_blocks);
}

void	get_blockslen(char **piece, int *maxlen)
{
	int count_horizontal;
	int count_vertical;
	int i;
	int j;

	count_vertical = 0;
	i = 0;
	while (i < PIECE_SIZE)
	{
		count_horizontal = 0;
		j = 0;
		while (j < PIECE_SIZE)
		{
			if (piece[i][j] == BLOCK_CHARACTER)
				count_horizontal++;				
			j++;
		}
		if (count_horizontal > 0)
			count_vertical++;
		if (count_horizontal > *maxlen)
			*maxlen = count_horizontal;
		i++;
	}
	if (count_vertical > *maxlen)
		*maxlen = count_vertical;
}

int		parse(int fd, char **pieces[], int *num_pieces)
{
	int 	i;
	int 	idx;
	int		n;
	int 	maxlen;
	int 	num_blocks;
	char	c;
	char	**piece;
	char	buf[20];
	int 	k;
	int 	next_piece;

	idx = 0;
	next_piece = 1;
	maxlen = 0;
	while ((n = read(fd, buf, 20)) > 0)
	{
		if (n < 19 || idx == 26)
			return (-1);
		piece = (char **)malloc(4 * sizeof(char *));
		i = 1;
		while (i <= n)
		{
			c = buf[i - 1];
			if (i == 19 || (i > 0 && i % 5 == 0))
			{
				if (i != 19 && c != '\n')
					return (-1);
				k = i == 19 ? 4 : 5;
				piece[(i - k) / 5] = new_copy_chars(&buf[i - k], 4);
			}
			else
				if (c != EMPTY_CHARACTER && c != BLOCK_CHARACTER)
					return (-1);
			i++;
		}
		if ((num_blocks = connections_numblocks(piece)) == -1 || num_blocks != 4)
			return (-1);
		pieces[idx++] = piece;
		next_piece = 1;
		get_blockslen(piece, &maxlen);
		if ((n = read(fd, buf, 1)))
		{
			if (n == 0)
				break ;
			if (n == 1 && buf[0] != '\n')
				return (-1);
			next_piece = 0;
		}
	}
	if (next_piece == 0 || idx == 0)
		return (-1);
	*num_pieces = idx;
	return (maxlen);
}