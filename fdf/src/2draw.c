/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2draw.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 12:36:04 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/26 12:36:08 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float   ft_fabs(float x)
{
    if (x < 0)
        x = x * -1;
    return (x);
}

void    isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.523599);
    *y = ((*x + *y) * sin(0.523599)) - z;
}

void    bresenham(float x, float y, float x1, float y1, fdf *data)
{
    float   x_step;
    float   y_step;
    int     max;
    int     z;
    int     z1;

    z = data->z[(int)y][(int)x];
    z1 = data->z[(int)y1][(int)x1];

    x *= data->zoom;
    y *= data->zoom;
    x1 *= data->zoom;
    y1 *= data->zoom;

    data->color = (z || z1) ? 0xe80c0c : 0xffffff;

    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);

    x += data->shift_x;
    y += data->shift_y;
    x1 += data->shift_x;
    y1 += data->shift_y;

    x_step = x1 - x;
    y_step = y1 - y;

    if (ft_fabs(x_step) > ft_fabs(y_step))
        max = ft_fabs(x_step);
    else
        max = ft_fabs(y_step);

    x_step /= max;
    y_step /= max;
    printf("---%f\n", x_step);
    while ((int)(x - x1) || (int)(y - y1))
    {
        
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
        x += x_step;
        y += y_step;
    } 
}

void    draw(fdf *data)
{
    int x;
    int y;

    y = 0;
    while (y < data->h)
    {
        x = 0;
        while (x < data->w)
        {
            if (x < data->w - 1)
                bresenham(x, y, x + 1, y, data);
            if (y  < data->h - 1)
                bresenham(x, y, x, y + 1, data);
            x++;
        }
        y++;
    }
}