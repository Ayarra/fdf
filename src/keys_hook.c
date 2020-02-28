/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:57:56 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/05/17 01:11:04 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_win(t_var *v)
{
	mlx_destroy_image(v->mlx_ptr, v->img_ptr);
	v->img_ptr = mlx_new_image(v->mlx_ptr, IMG_W, IMG_H);
	mlx_clear_window(v->mlx_ptr, v->win_ptr);
}

void	free_tab(t_var *v)
{
	int i;

	i = 0;
	while (i < v->height)
	{
		ft_memdel((void **)&(v->tab[i]));
		i++;
	}
	ft_memdel((void **)v->tab);
	exit(0);
}

void	initialization(t_var *v, char c)
{
	if (c == 'i')
	{
		v->scale = SCALE;
		v->xmove = 400;
		v->ymove = 100;
		v->zmove = 0.08;
		v->speed = 0.1;
		v->iso = 1;
		v->color_effect = 0;
		v->color = v->color_effect + 1;
	}
	else if (c == 'p')
	{
		clear_win(v);
		go_draw(v);
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->img_ptr, 210, 0);
		instruction(v);
	}
}

int		mouse_hook(int m, int x, int y, t_var *v)
{
	if (m == 1)
	{
		v->xmove = x - 210;
		v->ymove = y;
	}
	initialization(v, 'p');
	return (0);
}

int		keys_hook(int k, t_var *v)
{
	if (k == 53)
		free_tab(v);
	else if (k == 124 || k == 2 || k == 123 || k == 0)
		v->xmove += (k == 124 || k == 2) ? (1 + v->speed) : (-1 - v->speed);
	else if (k == 126 || k == 13 || k == 125 || k == 1)
		v->ymove += (k == 126 || k == 13) ? -(1 + v->speed) : (1 + v->speed);
	else if (k == 24 || k == 27)
		v->scale += (k == 24) ? (1 + v->speed) : (-1 - v->speed);
	else if (k == 7 || k == 6)
		v->zmove += (k == 7) ? (0.1 + v->speed) : (-0.1 - v->speed);
	else if (k == 34)
		v->iso = (v->iso) ? 0 : 1;
	else if (k == 36)
		initialization(v, 'i');
	else if (k == 8)
		v->color_effect = (v->color_effect) ? 0 : 1;
	if (k == 69 || k == 78)
	{
		v->speed = (k == 69) ? (v->speed * 2) : (v->speed / 2);
		if (v->speed > 4)
			v->speed = v->speed / 2;
	}
	else
		initialization(v, 'p');
	return (0);
}
