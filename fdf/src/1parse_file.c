/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1parse_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kysgramo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:04:59 by kysgramo          #+#    #+#             */
/*   Updated: 2020/02/25 12:05:06 by kysgramo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int get_height(char *file)
{
    char *line;
    int fd;
    int h;

    fd = open(file, O_RDONLY, 0);
    h = 0;
    while (get_next_line(fd, &line))
    {
        h++;
        free(line);
        
    }
    close (fd);
    return (h);
}

int get_width(char *file)
{
    char *line;
    int fd;
    int w;

    fd = open(file, O_RDONLY, 0);
    
    get_next_line(fd, &line); 
    w = ft_words(line, ' ');
    free(line);
    close (fd);
    return (w);
}

void    fill_matrix(int *z, char *line)
{
    char **num;
    int i;

    i = 0;
    num = ft_strsplit(line, ' ');
    while (num[i])
    {
        z[i] = ft_atoi(num[i]);
        free(num[i]);
        i++;
    }
    free(num);

}

int read_file(char *file, fdf *data)
{
    int i;
    int fd;
    char *line;

    data->h = get_height(file);
    data->w = get_width(file);
    data->z = (int **)malloc(sizeof(int*) * (data->h + 1));
    i = 0;
    while (i <= data->h)
        data->z[i++] = (int*)malloc(sizeof(int) * (data->w + 1));
    fd = open(file, O_RDONLY, 0);
    i = 0;
    while (i != data->h)
    {
        get_next_line(fd, &line);
        fill_matrix(data->z[i], line);
        free(line);
        i++;
        
    }
    close(fd);
    data->z[i] = NULL;
    return (0);
}