/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 01:17:55 by smbaabu           #+#    #+#             */
/*   Updated: 2019/04/01 16:55:23 by smbaabu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

# define PIECE_SIZE 4
# define BLOCK_CHARACTER '#'
# define EMPTY_CHARACTER '.'

int		get_smallest_piece_size(int num_pieces);
int 	*solve(int *board, int **pieces, int idx, int num_pieces);
void	solver(char ***pieces, int num_pieces, int largest_piece_size);
// parse
int		parse(int fd, char **pieces[], int *num_pieces);
// board
int		*create_board(int board_size);
int		*add_piece_to_board(int *board, int *piece, int idx);
int 	*copy_board_to(int *board, int new_board_size);
char 	**convert_board(int *board);

void	memset_zero(int *board, int len);
void	memset_emptychar(char *board, int len);
void 	write_to_board(char **board, int board_size, int *piece, int c);
// pieces
int		**convert_pieces(char ***pieces, int num_pieces, int board_size);
int 	get_first_valid_piece(int *new_piece, int board_size);
int 	get_next_valid_piece(int *new_piece, int board_size, int move_first);
void	copy_pieces_to(int **new_pieces, int num_pieces, int old_board_size, int growth);
int 	get_piece_index(int **pieces, int num_pieces, int *piece);

int*	convert_piece(char **piece, int board_size);
void	move_piece_by(int *piece, int n);
void	adapt_piece(int *piece, int old_board_size, int growth);
int		adapt_piece_to(int n, int old_board_size, int growth);
int		*copy_piece_to(int *piece, int old_board_size, int growth);

int 	num_neighbors(int *piece, int board_size, int i);
int		check_invalid_piece(int *piece, int board_size);
int		check_for_collision(int *board, int *piece);
// utils
int 	bigger(int a, int b);
int		array_equal_int(int *a, int *b, int n);
int		array_equal_str(char **s1, char **s2, int n);
void	free_ints(int **items, int n);
void	free_chars(char **items, int n);
void 	print_solution(char **solution, int n);
void	print_arr(int *arr, int num);
void	print_arrs(int **arr, int n, int m);
int		*new_copy_ints(int *arr, int size);
char	*new_copy_chars(char *A, int size);
// libft
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char const *s);
void	ft_putchar(char c);
void	ft_putnbr(int n);
