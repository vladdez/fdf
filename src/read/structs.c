/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 19:05:23 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/29 21:42:07 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*fill_struct(t_fdf *data)
{
	data->moves->angle_ox = 0;
	data->moves->angle_oy = 0;
	data->moves->angle_oz = 0;
	data->width = 0;
	data->height = 0;
	data->matrix = NULL;
	data->colmat = NULL;
	data->moves->zoom = 20;
	data->color = 0;
	data->moves->iso = 0;
	data->moves->z_div = 0.1;
	data->img->bit_depth = 32;
	data->img->line = SIZE_X;
	data->img->endian = 0;
	data->moves->shift_x = 0;
	data->moves->shift_y = 0;
	return (data);
}

t_fdf	*create_str(void)
{
	t_fdf *data;

	if (!(data = (t_fdf*)malloc(sizeof(t_fdf))))
		return (NULL);
	if (!(data->img = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	if (!(data->win = (t_win*)malloc(sizeof(t_win))))
		return (NULL);
	if (!(data->moves = (t_movement*)malloc(sizeof(t_movement))))
		return (NULL);
	if (!(data->crd = (t_crd*)malloc(sizeof(t_crd))))
		return (NULL);
	if (!(data->win->mlx_ptr = mlx_init()))
		return (NULL);
	if (!(data->win->win_ptr = mlx_new_window(data->win->mlx_ptr,
	SIZE_X, SIZE_Y, "FDF")))
		return (NULL);
	if (!(data->img->img_ptr = mlx_new_image(data->win->mlx_ptr,
	SIZE_X, SIZE_Y)))
		return (NULL);
	if (!(data->mouse = (t_mouse*)malloc(sizeof(t_mouse))))
		return (NULL);
	fill_struct(data);
	return (data);
}

void	clean_str(t_fdf *data)
{
	data->width = 0;
	data->height = 0;
	data->matrix = NULL;
	data->moves->zoom = 0;
	data->color = 0;
	data->moves->shift_x = 0;
	data->moves->shift_y = 0;
	data->moves->iso = 0;
	data->moves->z_div = 0.1;
	data->img->bit_depth = 0;
	data->img->line = 0;
	data->img->endian = 0;
	data->moves->angle_ox = 0;
	data->moves->angle_oy = 0;
	data->moves->angle_oz = 0;
	data->img->img_ptr = NULL;
	data->img->img_data = NULL;
	data->win->mlx_ptr = NULL;
	data->win->win_ptr = NULL;
	free(data);
}

void	clean_crd(t_fdf *data)
{
	data->crd->x1 = 0;
	data->crd->y1 = 0;
	data->crd->x2 = 0;
	data->crd->y2 = 0;
	data->crd->z = 0;
	data->crd->z1 = 0;
	data->crd->delta_x = 0;
	data->crd->delta_y = 0;
	data->crd->signx = 0;
	data->crd->signy = 0;
	data->crd->error = 0;
}
