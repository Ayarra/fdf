/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 18:35:43 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/05/17 00:50:48 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_rec(t_var *v)
{
	int i;

	i = 0;
	while (i < 700)
	{
		if (i % 5 == 0)
			mlx_pixel_put(v->mlx_ptr, v->win_ptr, 210, i, 0xFFF000);
		i++;
	}
	i = 20;
	while (i < 85)
	{
		mlx_pixel_put(v->mlx_ptr, v->win_ptr, 20, i, 0x0FFFFF);
		mlx_pixel_put(v->mlx_ptr, v->win_ptr, 190, i, 0x0FFFFF);
		i += 3;
	}
	i = 20;
	while (i < 190)
	{
		mlx_pixel_put(v->mlx_ptr, v->win_ptr, i, 20, 0x0FFFFF);
		mlx_pixel_put(v->mlx_ptr, v->win_ptr, i, 85, 0x0FFFFF);
		i += 3;
	}
}

void	logo_draw(t_var *v, int y, int x, int n)
{
	int i;
	int j;
	int c;

	c = 0;
	while (c < n)
	{
		j = 0;
		while (j < 5)
		{
			i = 0;
			while (i < 5)
			{
				if (i % 3 == 0 && j % 3 == 0)
					mlx_pixel_put(v->mlx_ptr, v->win_ptr, x +
							j + c * 5, y + i, 0xFFFFFF);
				i++;
			}
			j++;
		}
		c++;
	}
}

void	draw_logo_b(t_var *v)
{
	logo_draw(v, 35, 110, 4);
	logo_draw(v, 40, 125, 1);
	logo_draw(v, 45, 125, 1);
	logo_draw(v, 50, 110, 4);
	logo_draw(v, 55, 125, 1);
	logo_draw(v, 60, 125, 1);
	logo_draw(v, 65, 110, 4);
	logo_draw(v, 35, 140, 4);
	logo_draw(v, 40, 140, 1);
	logo_draw(v, 40, 155, 1);
	logo_draw(v, 45, 140, 1);
	logo_draw(v, 45, 155, 1);
	logo_draw(v, 45, 155, 1);
	logo_draw(v, 50, 155, 1);
	logo_draw(v, 55, 155, 1);
	logo_draw(v, 60, 155, 1);
	logo_draw(v, 65, 155, 1);
}

void	draw_logo_a(t_var *v)
{
	logo_draw(v, 35, 50, 3);
	logo_draw(v, 40, 50, 1);
	logo_draw(v, 40, 60, 1);
	logo_draw(v, 45, 60, 1);
	logo_draw(v, 50, 60, 1);
	logo_draw(v, 55, 60, 1);
	logo_draw(v, 60, 60, 1);
	logo_draw(v, 65, 55, 3);
	logo_draw(v, 35, 80, 4);
	logo_draw(v, 40, 95, 1);
	logo_draw(v, 45, 95, 1);
	logo_draw(v, 50, 80, 4);
	logo_draw(v, 55, 95, 1);
	logo_draw(v, 60, 95, 1);
	logo_draw(v, 65, 80, 4);
}

void	instruction(t_var *v)
{
	draw_rec(v);
	draw_logo_a(v);
	draw_logo_b(v);
	draw_btn(v, 10, -10);
	draw_btn(v, 10, 40);
	draw_btn(v, 10, 90);
	draw_btn(v, 10, 140);
	draw_btn(v, 10, 190);
	draw_btn(v, 10, 240);
	draw_btn(v, 10, 290);
	draw_btn(v, 10, 340);
	draw_btn(v, 10, 390);
	draw_btn(v, 10, 440);
	draw_btn(v, 10, 490);
	draw_btn(v, 10, 540);
	btn_content(v);
}
