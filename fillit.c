/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 01:17:32 by smbaabu           #+#    #+#             */
/*   Updated: 2019/04/01 16:40:55 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		get_smallest_piece_size(int num_pieces)
{
	int n;
	int i;
	
	n = num_pieces * PIECE_SIZE;
	i = 1;
	while (i * i <= n)
		i++;
	return ((i - 1) * (i - 1) == n ? i - 1 : i);
}

int 	*solve(int *board, int **pieces, int idx, int num_pieces)
{
	int *new_board;
	int *new_board2;
	int board_size;
	int	*new_piece;
	int valid_piece;
	
	board_size = board[0];
	if (idx == num_pieces)
		return (copy_board_to(board, board_size));
	new_piece = new_copy_ints(pieces[idx], PIECE_SIZE * 2);
	valid_piece = 0;
	while (get_next_valid_piece(new_piece, board_size, valid_piece++) == 1)
	{
		if (check_for_collision(board, new_piece) == 0)
		{
			new_board = add_piece_to_board(board, new_piece, idx);
			new_board2 = solve(new_board, pieces, idx + 1, num_pieces);
			free(new_board);
			if (new_board2 != NULL)
			{
				if (idx == 0)
					free(board);
				free(new_piece);
				return (new_board2);
			}
		}
	}
	free(new_piece);
	if (idx == 0)
	{
		new_board = copy_board_to(board, board_size + 1);
		free(board);
		copy_pieces_to(pieces, num_pieces, board_size, 1);
		return (solve(new_board, pieces, 0, num_pieces));
	}
	return (NULL);
}

void	solver(char ***pieces, int num_pieces, int largest_piece_size)
{
	int **pieces_int;
	int *board;
	int	board_size;
	int *solution_int;
	char **solution;

	board_size = bigger(get_smallest_piece_size(num_pieces), largest_piece_size);
	pieces_int = convert_pieces(pieces, num_pieces, board_size);
	board = create_board(board_size);
	solution_int = solve(board, pieces_int, 0, num_pieces);
	board_size = solution_int[0];
	solution = convert_board(solution_int);
	print_solution(solution, board_size);
	free_ints(pieces_int, num_pieces);
	free(solution_int);
	free_chars(solution, board_size);
}

int		main(int ac, char **av)
{
	int 	fd;
	char	**pieces[26];
	int		num_pieces;
	int 	maxlen;

	if (ac != 2)
	{
		ft_putstr("usage: ./fillit target_file");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	num_pieces = 0;
	if (fd == -1 || (maxlen = parse(fd, pieces, &num_pieces)) == -1)
	{
		ft_putstr("error\n");
		return (1);
	}
	else
	{
		solver(pieces, num_pieces, maxlen);
		return (0);
	}
}
