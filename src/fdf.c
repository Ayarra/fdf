/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:58:51 by anabaoui          #+#    #+#             */
/*   Updated: 2019/05/16 18:46:40 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		width_height(t_var *v, char *file)
{
	char *t;

	if ((v->fd = open(file, O_RDONLY)) <= 0)
		return (0);
	v->height = 0;
	v->max_width = 0;
	while (get_next_line(v->fd, &v->line) > 0)
	{
		v->split_line = ft_strsplit(v->line, ' ');
		v->width = 0;
		while (*v->split_line != 0)
		{
			v->width++;
			t = *(v->split_line++);
			ft_memdel((void **)&t);
		}
		if (v->max_width < v->width)
			v->max_width = v->width;
		ft_memdel((void **)v->split_line);
		v->height++;
	}
	if (!v->height)
		return (0);
	close(v->fd);
	return (1);
}

int		allocate_tab(t_var *v)
{
	int		i;

	if (!(v->tab = (int **)malloc(sizeof(int *) * v->height)))
		return (0);
	i = 0;
	while (i < v->height)
	{
		if (!(v->tab[i] = (int *)malloc(sizeof(int) * v->width)))
			return (0);
		i++;
	}
	return (1);
}

int		fill_tab(t_var *v, char *file)
{
	v->fd = open(file, O_RDONLY);
	if (v->fd <= 0)
		return (0);
	if (!(allocate_tab(v)))
		return (0);
	v->y = 0;
	while (get_next_line(v->fd, &v->line) > 0)
	{
		v->x = 0;
		v->split_line = ft_strsplit(v->line, ' ');
		while (v->x < v->width)
		{
			if (!(v->split_line[v->x]))
				v->tab[v->y][v->x] = 0;
			else
				v->tab[v->y][v->x] = atoi(v->split_line[v->x]);
			ft_memdel((void **)&(v->split_line[v->x]));
			v->x++;
		}
		ft_memdel((void **)v->split_line);
		ft_memdel((void **)&(v->line));
		v->y++;
	}
	close(v->fd);
	return (1);
}

int		fdf(char *argv)
{
	t_var	v;

	if (!(width_height(&v, argv)))
		return (0);
	if (!(fill_tab(&v, argv)))
		return (0);
	draw(&v);
	return (0);
}
