/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 11:18:33 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/25 11:19:39 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf.h"
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx_macos/mlx.h"

typedef struct 
{
   int      w;
   int      h;
   int      **z;
   int      zoom;
   int      color;
   int      shift_x;
   int      shift_y;

   void     *mlx_ptr;
   void     *win_ptr;
}               fdf;


int      read_file(char *file, fdf *data);
void     bresenham(float x, float y, float x1, float y1, fdf *data);
void     draw(fdf *data);
int      main(int ac, char **av);

#endif