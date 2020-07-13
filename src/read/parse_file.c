/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1parse_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmonserr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 05:22:06 by rmonserr          #+#    #+#             */
/*   Updated: 2020/02/29 21:39:18 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_height(char *file)
{
	char	*line;
	int		fd;
	int		h;
	int		i;

	fd = open(file, O_RDONLY, 0);
	h = 0;
	i = get_next_line(fd, &line);
	if (i != 1)
	{
		close(fd);
		if (i == -1)
			return (-1);
		else
			return (0);
	}
	h++;
	free(line);
	while (get_next_line(fd, &line))
	{
		h++;
		free(line);
	}
	close(fd);
	return (h);
}

int		get_width(char *file)
{
	char	*line;
	int		fd;
	int		w;
	int		w1;

	fd = open(file, O_RDONLY, 0);
	get_next_line(fd, &line);
	w = ft_words(line, ' ');
	free(line);
	while (get_next_line(fd, &line))
	{
		w1 = ft_words(line, ' ');
		free(line);
		if (w1 != w)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (w);
}

int		read_hw(char *file, t_fdf *data)
{
	data->height = get_height(file);
	if (data->height == 0)
		return (-1);
	if (data->height == -1)
		return (-3);
	if (data->height == -4)
		return (-4);
	data->width = get_width(file);
	if (data->width < 0)
		return (-2);
	return (1);
}

void	fill_colmat(int *zcol, int *zmat, char *line)
{
	char	**num;
	char	**col;
	int		i;
	int		sw;

	i = 0;
	sw = 0;
	num = ft_strsplit(line, ' ');
	while (num[i])
	{
		col = ft_strsplit(num[i], ',');
		if (col[1] != NULL)
			zcol[i] = ft_atoi16(col[1], 16);
		else
			zcol[i] = 0x808000;
		zmat[i] = ft_atoi(col[0]);
		free(col[0]);
		free(col[1]);
		free(num[i]);
		free(col);
		i++;
	}
	free(num);
}

int		read_file(char *file, t_fdf *data, int i, int ii)
{
	int		fd;
	char	*line;
	int		j;

	j = read_hw(file, data);
	if (j < 0)
		return (j);
	data->matrix = (int **)malloc(sizeof(int*) * (data->height + 1));
	data->colmat = (int **)malloc(sizeof(int*) * (data->height + 1));
	while (i <= data->height)
	{
		data->matrix[i] = (int*)malloc(sizeof(int) * (data->width + 1));
		data->colmat[i] = (int*)malloc(sizeof(int) * (data->width + 1));
		i++;
	}
	fd = open(file, O_RDONLY, 0);
	while (ii != data->height)
	{
		get_next_line(fd, &line);
		fill_colmat(data->colmat[ii], data->matrix[ii], line);
		free(line);
		ii++;
	}
	close(fd);
	return (0);
}
