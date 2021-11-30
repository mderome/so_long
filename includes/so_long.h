/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 09:36:55 by mderome           #+#    #+#             */
/*   Updated: 2021/11/30 12:38:30 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define UP 119
# define LEFT 97
# define DOWN 115
# define RIGHT 100
# define ESC 65307
# define ESC_CLICK 1421103264

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*typedef struct s_image {
	void	*wall;
	void	*ground;
	void	*chara;
	void	*collect;
	void	*exit;
}				t_image;

typedef struct	s_map {
	char 	**map;
	int		x;
	int		y;
}				t_map;

typedef struct	s_prsn {
	int	player;
	int collec;
	int	exit;
	int fail;
	int fail_wall;
}				t_prsn;*/

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	**map;
	int		x;
	int		y;
	int		player;
	int		collec;
	int		exit;
	int		fail;
	int		fail_wall;
	void	*wall;
	void	*ground;
	void	*chara;
	void	*collect;
	void	*exit2;
	int		pos_p_x;
	int		pos_p_y;
	int		take_collect;
	int		nb_hook;
	char	*nb_to_print;
}				t_vars;

/*****************************************************************************/
/*																			 */
/*                   				MAIN									 */
/*																			 */
/*****************************************************************************/

int		main(int ac, char **av);
void	free_map(t_vars *vars);
int		ft_len_tab(t_vars *vars);
void	put_map(t_vars *vars, void *mlx, void *mlx_win);
void	put_obj(t_vars *vars, void *mlx, void *mlx_win);

/*****************************************************************************/
/*																			 */
/*                   			PARSING MAPS								 */
/*																			 */
/*****************************************************************************/

int		parsing_map(t_vars *vars);
void	init_struct(t_vars *vars);
int		check_map(char *file, t_vars *vars);
int		check_check(t_vars *vars);
void	check_obj(t_vars *vars, int pos_x, int pos_y);

/*****************************************************************************/
/*																			 */
/*                   			PRINT ERROR									 */
/*																			 */
/*****************************************************************************/

void	print_error_map(t_vars *vars);

/*****************************************************************************/
/*																			 */
/*                   				FREE									 */
/*																			 */
/*****************************************************************************/

int		close_win(t_vars *vars);
void	free_image(t_vars *vars);

/*****************************************************************************/
/*																			 */
/*                   				MOOVE									 */
/*																			 */
/*****************************************************************************/

void	check_moove(int keycode, t_vars *vars);
void	put_moov(t_vars *vars, void *mlx, void *mlx_win, int moove);

#endif