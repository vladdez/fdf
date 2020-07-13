/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_managment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:34:12 by rmonserr          #+#    #+#             */
/*   Updated: 2020/03/03 12:34:15 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	to_zero_coords(t_fdf *data)
{
	data->crd->x1 -= (data->width * data->moves->zoom / 2);
	data->crd->y1 -= (data->height * data->moves->zoom / 2);
	data->crd->x2 -= (data->width * data->moves->zoom / 2);
	data->crd->y2 -= (data->height * data->moves->zoom / 2);
}

void	to_center(t_fdf *data)
{
	data->crd->x1 += (SIZE_X / 2);
	data->crd->y1 += (SIZE_Y / 2);
	data->crd->x2 += (SIZE_X / 2);
	data->crd->y2 += (SIZE_Y / 2);
}

void	o_y_rotation(t_fdf *data)
{
	int	tmpx1;
	int	tmpx2;

	tmpx1 = data->crd->x1;
	tmpx2 = data->crd->x2;
	data->crd->x1 = tmpx1 * cos(data->moves->angle_oy) +
	data->crd->z * sin(data->moves->angle_oy);
	data->crd->z = -tmpx1 * sin(data->moves->angle_oy) +
	data->crd->z * cos(data->moves->angle_oy);
	data->crd->x2 = tmpx2 * cos(data->moves->angle_oy) +
	data->crd->z1 * sin(data->moves->angle_oy);
	data->crd->z1 = -tmpx2 * sin(data->moves->angle_oy) +
	data->crd->z1 * cos(data->moves->angle_oy);
}

void	o_x_rotation(t_fdf *data)
{
	int tmpy1;
	int	tmpy2;

	tmpy1 = data->crd->y1;
	tmpy2 = data->crd->y2;
	data->crd->y1 = tmpy1 * cos(data->moves->angle_ox) +
	data->crd->z * sin(data->moves->angle_ox);
	data->crd->z = -tmpy1 * sin(data->moves->angle_ox) +
	data->crd->z * cos(data->moves->angle_ox);
	data->crd->y2 = tmpy2 * cos(data->moves->angle_ox) +
	data->crd->z1 * sin(data->moves->angle_ox);
	data->crd->z1 = -tmpy2 * sin(data->moves->angle_ox) +
	data->crd->z1 * cos(data->moves->angle_ox);
}

void	o_z_rotation(t_fdf *data)
{
	int	tmpx1;
	int	tmpx2;
	int tmpy1;
	int tmpy2;

	tmpx1 = data->crd->x1;
	tmpy1 = data->crd->y1;
	tmpx2 = data->crd->x2;
	tmpy2 = data->crd->y2;
	data->crd->x1 = tmpx1 * cos(data->moves->angle_oz) -
	tmpy1 * sin(data->moves->angle_oz);
	data->crd->y1 = tmpx1 * sin(data->moves->angle_oz) +
	tmpy1 * cos(data->moves->angle_oz);
	data->crd->x2 = tmpx2 * cos(data->moves->angle_oz) -
	tmpy2 * sin(data->moves->angle_oz);
	data->crd->y2 = tmpx2 * sin(data->moves->angle_oz) +
	tmpy2 * cos(data->moves->angle_oz);
}
