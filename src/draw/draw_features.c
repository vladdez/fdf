/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_features.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 12:05:24 by kysgramo          #+#    #+#             */
/*   Updated: 2020/03/01 12:05:27 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_fdf *data)
{
	int previous_x1;
	int previous_y1;
	int previous_x2;
	int previous_y2;

	previous_x1 = data->crd->x1;
	previous_y1 = data->crd->y1;
	previous_x2 = data->crd->x2;
	previous_y2 = data->crd->y2;
	data->crd->x1 = (previous_x1 - previous_y1) * cos(0.523599);
	data->crd->y1 = -data->crd->z + (previous_x1 + previous_y1) * sin(0.523599);
	data->crd->x2 = (previous_x2 - previous_y2) * cos(0.523599);
	data->crd->y2 = -data->crd->z1 + (previous_x2 +
	previous_y2) * sin(0.523599);
}

void	z_adjusting(t_fdf *data)
{
	data->crd->z *= data->moves->zoom;
	data->crd->z1 *= data->moves->zoom;
	if (data->crd->z > 0)
		data->crd->z += (int)(data->moves->z_div * data->moves->zoom);
	if (data->crd->z1 > 0)
		data->crd->z1 += (int)(data->moves->z_div * data->moves->zoom);
}

void	zoom(t_fdf *data)
{
	data->crd->x1 *= data->moves->zoom;
	data->crd->y1 *= data->moves->zoom;
	data->crd->x2 *= data->moves->zoom;
	data->crd->y2 *= data->moves->zoom;
}

void	shift(t_fdf *data)
{
	data->crd->x1 += data->moves->shift_x;
	data->crd->y1 += data->moves->shift_y;
	data->crd->x2 += data->moves->shift_x;
	data->crd->y2 += data->moves->shift_y;
}
