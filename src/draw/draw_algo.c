/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2draw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 05:22:22 by rmonserr          #+#    #+#             */
/*   Updated: 2020/02/29 21:39:32 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		replace(t_fdf *data)
{
	mlx_destroy_image(data->win->mlx_ptr, data->img->img_ptr);
	data->img->img_ptr = mlx_new_image(data->win->mlx_ptr, SIZE_X, SIZE_Y);
	data->img->img_data = (int *)mlx_get_data_addr(data->img->img_ptr,
	&data->img->bit_depth, &data->img->line, &data->img->endian);
	draw(data);
	mlx_put_image_to_window(data->win->mlx_ptr,
	data->win->win_ptr, data->img->img_ptr, 0, 0);
	draw_menu(data->win->mlx_ptr, data->win->win_ptr);
	draw_display(data->win->mlx_ptr, data->win->win_ptr, data);
}

void		bresenham(t_fdf *data)
{
	int			error2;

	while ((data->crd->x1 != data->crd->x2 ||
	data->crd->y1 != data->crd->y2))
	{
		if (!(data->crd->x1 <= 0 || data->crd->x1 >= SIZE_X ||
		data->crd->y1 <= 0 || data->crd->y1 >= SIZE_Y))
			data->img->img_data[data->crd->y1 *
			SIZE_X + data->crd->x1] = data->color;
		error2 = data->crd->error * 2;
		if (error2 > -data->crd->delta_y)
		{
			data->crd->error -= data->crd->delta_y;
			data->crd->x1 += data->crd->signx;
		}
		if (error2 < data->crd->delta_x)
		{
			data->crd->error += data->crd->delta_x;
			data->crd->y1 += data->crd->signy;
		}
	}
	clean_crd(data);
}

void		modification(int x1, int y1, int sw, t_fdf *data)
{
	data->color = data->colmat[y1][x1];
	data->crd->x2 = (sw == 1) ? x1++ : x1;
	data->crd->y2 = (sw == 1) ? y1 : y1++;
	data->crd->x1 = x1;
	data->crd->y1 = y1;
	if ((data->colmat[data->crd->y2][data->crd->x2]
		!= data->colmat[data->crd->y1][data->crd->x1]))
		data->color = DEFAULT_COLOR;
	data->crd->z = data->matrix[data->crd->y1][data->crd->x1];
	data->crd->z1 = data->matrix[data->crd->y2][data->crd->x2];
	movement(data);
	fill_crd_struct(data);
	bresenham(data);
}

void		draw(t_fdf *data)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1 && (!(x < 0)))
				modification(x, y, 1, data);
			if (y < data->height - 1 && (!(y < 0)))
				modification(x, y, 2, data);
			x++;
		}
		y++;
	}
}
