/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:18:22 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/25 11:18:25 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

fdf     *create_str()
{
    fdf *data;

    if (!(data = (fdf*)malloc(sizeof(fdf))))
        return (NULL);
    data->w = 0;
    data->h = 0;
    data->z = NULL;
    data->zoom = 0;
    data->color = 0;
    data->shift_x = 0;
    data->shift_y = 0;

    data->mlx_ptr = NULL;
    data->win_ptr = NULL;
    return (data);
}

void    clean_str(fdf *data)
{
    data->w = 0;
    data->h = 0;
    data->z = NULL;
    data->zoom = 0;
    data->color = 0;
    data->shift_x = 0;
    data->shift_y = 0;

    data->mlx_ptr = NULL;
    data->win_ptr = NULL;
    free (data);
}

int     deal_key(int key, fdf *data)
{
    ft_printf("%d\n", key);
    if (key == 126)
        data->shift_y -= 10;
    if (key == 125)
        data->shift_y += 10;
    if (key == 124)
        data->shift_x -= 10;
    if (key == 123)
        data->shift_x += 10;
    mlx_clear_window(data->mlx_ptr, data->win_ptr);
    draw(data);
    return (0);
}

int main(int ac, char **av)
{
    fdf *data;

    data = NULL;
    if (ac > 1)
    {
        data = create_str();
        data->zoom = 20;
        read_file(av[1], data);
        data->mlx_ptr = mlx_init();
        data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
        draw(data);
        mlx_key_hook(data->win_ptr, deal_key, data);
        mlx_loop(data->mlx_ptr);
        clean_str(data);
    }
}


