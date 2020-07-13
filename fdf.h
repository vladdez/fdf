/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:18:33 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/25 11:19:39 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <errno.h>
# include "minilibx_macos/mlx.h"

# define DEFAULT_COLOR 0x808000

# define SIZE_X 2048
# define SIZE_Y 1024

typedef struct	s_crd
{
	int			x1;
	int			x2;
	int			z;
	int			z1;
	int			y1;
	int			y2;
	int			delta_x;
	int			delta_y;
	int			signx;
	int			signy;
	int			error;
}				t_crd;

typedef struct	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_win;

typedef struct	s_img
{
	void		*img_ptr;
	int			*img_data;
	int			line;
	int			endian;
	int			bit_depth;
}				t_img;

typedef struct	s_movement
{
	double		zoom;
	int			iso;
	float		z_div;
	double		angle_ox;
	double		angle_oy;
	double		angle_oz;
	int			shift_x;
	int			shift_y;
}				t_movement;

typedef struct	s_mouse
{
	int			mouse_x;
	int			mouse_y;
	int			key;
}				t_mouse;

typedef struct	s_fdf
{
	int			width;
	int			height;
	int			**matrix;
	int			**colmat;
	int			color;
	t_win		*win;
	t_img		*img;
	t_movement	*moves;
	t_crd		*crd;
	t_mouse		*mouse;
}				t_fdf;

/*
** ---------------------moves--------------------
*/

void			ft_moves(int key, t_fdf *data);
void			ft_iso(int key, t_fdf *data);
void			ft_zoom(int key, t_fdf *data);
void			ft_altitude(int key, t_fdf *data);
void			o_x_rotation(t_fdf *data);
void			o_y_rotation(t_fdf *data);
void			o_z_rotation(t_fdf *data);
void			to_zero_coords(t_fdf *data);
void			to_center(t_fdf *data);
void			ft_angle_x(int	key, t_fdf *data);
void			ft_angle_y(int	key, t_fdf *data);
void			ft_angle_z(int	key, t_fdf *data);
void			rotation(t_fdf *data);
void			movement(t_fdf *data);
void			z_adjusting(t_fdf *data);
void			iso(t_fdf *data);
void			zoom(t_fdf *data);
void			shift(t_fdf *data);
int				mouse_press(int key, int x, int y, t_fdf *data);

/*
** ----------------------draw---------------------
*/

void			bresenham(t_fdf *data);
void			draw(t_fdf *data);
void			replace(t_fdf *data);
void			draw_menu(void *win, void *mlx);
void			draw_display(void *win, void *mlx, t_fdf *data);

/*
** ----------------values & structs---------------
*/

int				read_file(char *file, t_fdf *data, int i, int ii);
int				ft_atoi16(const char *str, int str_base);
int				main(int argc, char **argv);
int				deal_key(int key, t_fdf *data);
int				deal_key_exit(void *data);
t_fdf			*create_str();
void			clean_str(t_fdf *data);
void			clean_crd(t_fdf *data);
void			fill_crd_struct(t_fdf *data);
int				ft_abs(int	value);

#endif
