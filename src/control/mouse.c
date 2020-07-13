/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 21:46:34 by rmonserr          #+#    #+#             */
/*   Updated: 2020/03/04 21:46:37 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_release(int key, int x, int y, t_fdf *data)
{
	x++;
	x--;
	y++;
	y--;
	data->mouse->key += key;
	return (0);
}

int	mouse_move(int x, int y, t_fdf *data)
{
	mlx_hook(data->win->win_ptr, 5, 0, mouse_release, data);
	if (data->mouse->key > 0)
		return (0);
	if (x > data->mouse->mouse_x)
		data->moves->angle_ox += 0.02;
	if (x < data->mouse->mouse_x)
		data->moves->angle_ox -= 0.02;
	if (y > data->mouse->mouse_y)
		data->moves->angle_oy += 0.02;
	if (y < data->mouse->mouse_y)
		data->moves->angle_oy -= 0.02;
	data->mouse->mouse_x = x;
	data->mouse->mouse_y = y;
	replace(data);
	return (0);
}

int	mouse_press(int key, int x, int y, t_fdf *data)
{
	if (key == 1)
		mlx_hook(data->win->win_ptr, 6, 0, mouse_move, data);
	if (key == 4)
	{
		data->moves->zoom += 1;
		replace(data);
		return (0);
	}
	if (key == 5 && data->moves->zoom > 1)
	{
		data->moves->zoom -= 1;
		replace(data);
		return (0);
	}
	x++;
	x--;
	y++;
	y--;
	data->mouse->key = 0;
	return (0);
}
