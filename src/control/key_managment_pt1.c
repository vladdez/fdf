/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_managment_pt1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 05:21:32 by rmonserr          #+#    #+#             */
/*   Updated: 2020/02/29 21:39:46 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_altitude(int key, t_fdf *data)
{
	if (data->moves->z_div < 0)
		data->moves->z_div = 0;
	else if (data->moves->z_div > 10)
		data->moves->z_div = 10;
	if (key == 69)
		data->moves->z_div += 0.1;
	if (key == 78)
		data->moves->z_div -= 0.1;
}

void	ft_zoom(int key, t_fdf *data)
{
	if (data->moves->zoom < 1)
		data->moves->zoom = 1;
	if (key == 24)
		data->moves->zoom += 0.1;
	if (key == 27)
		data->moves->zoom -= 0.1;
}

void	ft_moves(int key, t_fdf *data)
{
	if (data->moves->shift_x < -750)
		data->moves->shift_x = -750;
	else if (data->moves->shift_x > 770)
		data->moves->shift_x = 770;
	if (data->moves->shift_y < -170)
		data->moves->shift_y = -170;
	else if (data->moves->shift_y > 190)
		data->moves->shift_y = 190;
	if (key == 123)
		data->moves->shift_x -= 10;
	if (key == 124)
		data->moves->shift_x += 10;
	if (key == 126)
		data->moves->shift_y -= 10;
	if (key == 125)
		data->moves->shift_y += 10;
}

int		deal_key(int key, t_fdf *data)
{
	ft_iso(key, data);
	ft_moves(key, data);
	ft_zoom(key, data);
	ft_altitude(key, data);
	ft_angle_x(key, data);
	ft_angle_y(key, data);
	ft_angle_z(key, data);
	if (key == 53)
		exit(1);
	replace(data);
	return (0);
}
