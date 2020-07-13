/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:31:24 by kysgramo          #+#    #+#             */
/*   Updated: 2020/03/04 22:31:31 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		rotation(t_fdf *data)
{
	to_zero_coords(data);
	o_x_rotation(data);
	o_y_rotation(data);
	o_z_rotation(data);
	if (data->moves->iso == 1)
		iso(data);
	to_center(data);
}

void		movement(t_fdf *data)
{
	zoom(data);
	z_adjusting(data);
	rotation(data);
	shift(data);
}
