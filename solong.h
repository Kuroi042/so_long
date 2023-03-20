/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouderr <mbouderr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:14:32 by mbouderr          #+#    #+#             */
/*   Updated: 2023/03/20 19:00:37 by mbouderr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H

# define SOLONG_H
# include "g_nl/get_next_line.h"
# include "lbft/libft.h"
#include "ftprintf/ft_printf.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_player
{
	int			player_x;
	int			player_y;
	int			path_x;
	int			path_y;
	int			pas;
}				t_player;
typedef struct s_mymap
{
	int			r;
	int			c;
	int			map_line_counter;
	int			num_rows;
	int			num_col;
	int			errori;
	int			check_tool_up;
	int			check_tool_teht;
	int			check_side_left;
	int			check_side_right;
	char		*map1;
	char		*map_str;
	size_t		len_map;
	int			counter;
	int			e_found;
	int			p_found;
	int			e_kayna;
	char		**splited;
	char		**maptester;
}				t_mymap;

typedef struct s_mymlx
{
	void		*mlx;
	void		*mlx_win;
	void		*wall;
	void		*joseph;
	void		*sand;
	void		*coin;
	void		*exit;
	int			coin_yes;
	int			exit_x;
	int			exit_y;
	int			coincounter;
	int			path_coin;
	int			coins_collected;
	int			num_coins;
	int			i;
	int			j;
	int			m;
	int			n;
	int			exitfound;
	int			playerdiali;
	int			colldiali;
	int			exitdiali;
	t_mymap		map;
	t_player	player;

}				t_mymlx;

void			permetre(t_mymlx *mymlx);
void			openber(int fd);
void			berber(char *str);
void			projec(int x, int y, t_mymlx *mymlx);
void			drawingxpm(int i, int j, char **splited, t_mymlx *mymlx);
int				key_press(int keycode, t_mymlx *mymlx);
void			press_w(t_mymlx *mymlx);
void			press_a(t_mymlx *mymlx);
void			press_s(t_mymlx *mymlx);
void			press_d(t_mymlx *mymlx);
void			printexit(t_mymlx *mymlx);
int				pressex(int keycode);
void			press_escap(t_mymlx *mymlx);
void			rassam(int i, int j, void *image, t_mymlx *mymlx);
void			coin_counter(int i, int j, char **splited, t_mymlx *mymlx);
void			line_count(t_mymlx *mymlx);
void			player_position(char **splited, int path_x, int path_y,
					t_mymlx *mymlx);
void			big_path_if(char **splited, int pathx, int pathy,
					t_mymlx *mymlx);
void			drawingxpsuite(char **splited, int i, int j, t_mymlx *mymlx);
void			checker(t_mymlx *mymlx);
void			findexit(char **splited, t_mymlx *mymlx);
void			coin_counter(int i, int j, char **splited, t_mymlx *mymlx);
void			check_num_col(t_mymlx *mymlx);
int				len(char *str);
void			mlx(t_mymlx *mymlx);
void			allerror(t_mymlx *mymlx);
void			N_line_errors(t_mymlx *mymlx);
void			inputter(int j, int k, t_mymlx *mymlx);
void			rowsandcols(t_mymlx *mymlx);
void			get_and_join(t_mymlx *mymlx, int fd);
void			coin_checker_path(char **splited, t_mymlx *mymlx);
void 			check_leaks();
void 			thedestroyer(t_mymlx *mymlx);
void 			vree(t_mymlx *mymlx);
#endif