/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 05:26:47 by rmonserr          #+#    #+#             */
/*   Updated: 2020/03/02 19:22:58 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		read_withnoerr(char *file, t_fdf *data)
{
	int		i;
	int		len;

	len = ft_strlen(file);
	if (len < 5 || file[len - 1] != 'f' || file[len - 2] != 'd' ||
			file[len - 3] != 'f' || file[len - 4] != '.')
	{
		ft_putendl_fd("Usage: ./fdf *.fdf.", 2);
		return (-1);
	}
	i = read_file(file, data, 0, 0);
	if (i < 0)
	{
		if (i == -2)
			ft_putendl_fd("Found wrong line length. Exiting.", 2);
		if (i == -1)
			ft_putendl_fd("No data found.", 2);
		if (i == -3)
			ft_putendl_fd("No such file or permission denied.", 2);
		return (-1);
	}
	return (1);
}

int		main(int argc, char **argv)
{
	t_fdf *data;

	data = NULL;
	if (argc == 2)
	{
		data = create_str();
		data->img->img_data = (int *)mlx_get_data_addr(data->img->img_ptr,
				&data->img->bit_depth, &data->img->line, &data->img->endian);
		if (read_withnoerr(argv[1], data) < 0)
			return (0);
		draw(data);
		mlx_hook(data->win->win_ptr, 4, 0, mouse_press, data);
		mlx_hook(data->win->win_ptr, 2, 0, deal_key, data);
		mlx_hook(data->win->win_ptr, 17, 0, deal_key_exit, data);
		mlx_put_image_to_window(data->win->mlx_ptr, data->win->win_ptr,
				data->img->img_ptr, 0, 0);
		draw_menu(data->win->mlx_ptr, data->win->win_ptr);
		draw_display(data->win->mlx_ptr, data->win->win_ptr, data);
		mlx_loop(data->win->mlx_ptr);
	}
	else
		ft_putendl_fd("Usage: ./fdf MAP_FILE.", 2);
}
