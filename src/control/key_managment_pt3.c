/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_managment_pt3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:06:00 by kysgramo          #+#    #+#             */
/*   Updated: 2020/03/05 18:06:03 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		draw_menu(void *win, void *mlx)
{
	mlx_string_put(win, mlx, 200, 80, 0xFFFF, "Menu");
	mlx_string_put(win, mlx, 100, 90, 0xFFFF,
	"-----------------------------------");
	mlx_string_put(win, mlx, 100, 120, 0xFFFF, "Zoom: + / - (on the top)");
	mlx_string_put(win, mlx, 100, 140, 0xFFFF,
	"Altitude: + and - (on the right)");
	mlx_string_put(win, mlx, 100, 160, 0xFFFF, "Shift: Arrows");
	mlx_string_put(win, mlx, 100, 180, 0xFFFF, "Projections: I, P");
	mlx_string_put(win, mlx, 100, 200, 0xFFFF, "Camera shifts: mouse");
	mlx_string_put(win, mlx, 100, 220, 0xFFFF, "X rotation: 4 / 6");
	mlx_string_put(win, mlx, 100, 240, 0xFFFF, "Y rotation: 8 / 2");
	mlx_string_put(win, mlx, 100, 260, 0xFFFF, "Z rotation: 9 / 1");
	mlx_string_put(win, mlx, 100, 300, 0xFFFF, "Play and enjoy!");
}

void		draw_display2(void *win, void *mlx, t_fdf *data)
{
	char	*tmp;

	if (data->moves->iso == 1)
		mlx_string_put(win, mlx, 100, 700, 0x00FF00, "Projection: isometric");
	else
		mlx_string_put(win, mlx, 100, 700, 0x00FF00, "Projection: parallel");
	mlx_string_put(win, mlx, 100, 720, 0x00FF00,
	"Rotation. X:   ; Y:   ;Z:   ;");
	tmp = ft_itoa(data->moves->angle_ox);
	mlx_string_put(win, mlx, 220, 720, 0x00FF00, tmp);
	free(tmp);
	tmp = ft_itoa(data->moves->angle_oy);
	mlx_string_put(win, mlx, 300, 720, 0x00FF00, tmp);
	free(tmp);
	tmp = ft_itoa(data->moves->angle_oz);
	mlx_string_put(win, mlx, 370, 720, 0x00FF00, tmp);
	free(tmp);
}

void		draw_display(void *win, void *mlx, t_fdf *data)
{
	char	*tmp;

	mlx_string_put(win, mlx, 200, 600, 0x00FF00, "Display");
	mlx_string_put(win, mlx, 100, 610, 0x00FF00,
	"-----------------------------------");
	mlx_string_put(win, mlx, 100, 640, 0x00FF00, "Zoom: ");
	tmp = ft_itoa(data->moves->zoom);
	mlx_string_put(win, mlx, 160, 640, 0x00FF00, tmp);
	free(tmp);
	mlx_string_put(win, mlx, 100, 660, 0x00FF00, "Altitude: ");
	tmp = ft_itoa(data->moves->z_div);
	mlx_string_put(win, mlx, 200, 660, 0x00FF00, tmp);
	free(tmp);
	mlx_string_put(win, mlx, 100, 680, 0x00FF00, "Shift. X:    ; Y: ");
	tmp = ft_itoa(data->moves->shift_x);
	mlx_string_put(win, mlx, 190, 680, 0x00FF00, tmp);
	free(tmp);
	tmp = ft_itoa(data->moves->shift_y);
	mlx_string_put(win, mlx, 270, 680, 0x00FF00, tmp);
	free(tmp);
	draw_display2(win, mlx, data);
}
