/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 21:09:04 by otiffiny          #+#    #+#             */
/*   Updated: 2019/12/24 20:33:48 by otiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct		s_fillit
{
	char			letter;
	void			*tetro_type;
	struct s_fillit	*next;
}					t_fillit;

# define TETRO_1 (int [8]) {0,0,0,1,0,2,0,3}
# define TETRO_2 (int [8]) {0,0,1,0,2,0,3,0}
# define TETRO_3 (int [8]) {0,0,1,0,0,1,1,1}
# define TETRO_4 (int [8]) {0,0,0,1,0,2,1,2}
# define TETRO_5 (int [8]) {0,0,1,0,2,0,0,1}
# define TETRO_6 (int [8]) {0,0,1,0,1,1,1,2}
# define TETRO_7 (int [8]) {2,0,0,1,1,1,2,1}
# define TETRO_8 (int [8]) {1,0,1,1,0,2,1,2}
# define TETRO_9 (int [8]) {0,0,0,1,1,1,2,1}
# define TETRO_10 (int [8]) {0,0,1,0,0,1,0,2}
# define TETRO_11 (int [8]) {0,0,1,0,2,0,2,1}
# define TETRO_12 (int [8]) {1,0,0,1,1,1,2,1}
# define TETRO_13 (int [8]) {0,0,0,1,1,1,0,2}
# define TETRO_14 (int [8]) {0,0,1,0,2,0,1,1}
# define TETRO_15 (int [8]) {1,0,0,1,1,1,1,2}
# define TETRO_16 (int [8]) {1,0,2,0,0,1,1,1}
# define TETRO_17 (int [8]) {0,0,0,1,1,1,1,2}
# define TETRO_18 (int [8]) {0,0,1,0,1,1,2,1}
# define TETRO_19 (int [8]) {1,0,0,1,1,1,0,2}

void				free_square(char **square, int size);
int					solution(char **square, t_fillit *coord, int size);
int					*move_tetro(int *tetro, int x, int y);
void				print_answer(char **square, int size);
int					collision_solve(char **square, int *tetro, t_fillit *coord,\
					int size);
int					tetro_overlap(char **square, int *tetro);
int					map_overlap(int *tetro, int size);
void				move_letter(char **square, int *tetro, char letter);
void				del_tetro(char **square, int *tab);
int					count_tetro(t_fillit *coord);
char				**create_square(int size);
char				*create_line(int size);
int					solver(int fd);
void				free_list(t_fillit *temp);
void				free_end(t_fillit *coord);
int					*move_coord(int *link);
int					define_x(int *link);
int					define_y(int *link);
int					*read_one_tetro(const int fd, char *line);
int					calc_size(t_fillit *coord);
int					*t_type(char *type);
int					coordcpy(int *dest, int *src);
char				*gettype(int *tetro);
int					tabcmp(int *tab, int *arr, int n);
void				type_error(void);
int					one_tetro(const int fd, char *line);
int					block_count(char *line);
int					check_block(char *point);
int					validate(const int fd);
t_fillit			*first_list(void *tetro_type, char tetro_letter);
t_fillit			*next_list(void *tetro_type, t_fillit *first, char letter);
t_fillit			*let_coord(t_fillit *coord);
t_fillit			*save_temp(const int fd, char *line);

#endif
