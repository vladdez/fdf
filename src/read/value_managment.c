/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 04:46:17 by rmonserr          #+#    #+#             */
/*   Updated: 2020/03/04 04:46:22 by rmonserr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_abs(int value)
{
	(value > 0) ? (value *= 1) : (value *= -1);
	return (value);
}

void	fill_crd_struct(t_fdf *data)
{
	data->crd->delta_x = ft_abs(data->crd->x2 - data->crd->x1);
	data->crd->delta_y = ft_abs(data->crd->y2 - data->crd->y1);
	data->crd->signx = data->crd->x1 < data->crd->x2 ? 1 : -1;
	data->crd->signy = data->crd->y1 < data->crd->y2 ? 1 : -1;
	data->crd->error = data->crd->delta_x - data->crd->delta_y;
}
