/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_managment_pt2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 05:21:44 by rmonserr          #+#    #+#             */
/*   Updated: 2020/02/29 21:39:58 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_angle_x(int key, t_fdf *data)
{
	if (key == 91)
		data->moves->angle_ox -= 0.02;
	if (key == 84)
		data->moves->angle_ox += 0.02;
}

void	ft_angle_y(int key, t_fdf *data)
{
	if (key == 88)
		data->moves->angle_oy += 0.02;
	if (key == 86)
		data->moves->angle_oy -= 0.02;
}

void	ft_angle_z(int key, t_fdf *data)
{
	if (key == 92)
		data->moves->angle_oz -= 0.02;
	if (key == 83)
		data->moves->angle_oz += 0.02;
}

void	ft_iso(int key, t_fdf *data)
{
	if (key == 34)
		data->moves->iso = 1;
	if (key == 35)
		data->moves->iso = 0;
}

int		deal_key_exit(void *data)
{
	(void)data;
	exit(0);
}
