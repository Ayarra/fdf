/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guide_btn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 20:50:05 by hhamdaou          #+#    #+#             */
/*   Updated: 2019/05/17 01:11:36 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_image(t_axes *point, t_draw_info d, t_var *v, int z)
{
	int x;
	int y;

	x = point[0].x;
	y = point[0].y;
	d.width = IMG_W;
	if (y * d.width + x >= 0 && x <= 1300 && y <= 700)
		v->img_data[y * d.width + x] = z ? (0xFFFFFF - v->color) : 0x0FFFFF;
	while ((x != point[1].x) || (y != point[1].y))
	{
		((0xFFFFFF - v->color) > 1) ? (v->color += v->color_effect) :
			(v->color = v->color_effect);
		(d.x) ? (x += d.movex) : (y += d.movey);
		(d.x) ? (d.acm += abs(d.dy)) : (d.acm += abs(d.dx));
		if (d.acm >= abs((d.x) ? (d.dx) : (d.dy)))
		{
			(d.x) ? (y += d.movey) : (x += d.movex);
			(d.x) ? (d.acm -= abs(d.dx)) : (d.acm -= abs(d.dy));
		}
		if (y * d.width + x >= 0 && x <= 1300 && y <= 700)
			v->img_data[y * d.width + x] = z ? (0xFFFFFF - v->color) : 0x0FFFFF;
	}
}

void	btn_content(t_var *v)
{
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 113, 0x0FFFFF, "=");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 163, 0x0FFFFF, "-");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 113, 0x0FFFFF, "Zoom in");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 163, 0x0FFFFF, "Zoom out");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 213, 0x0FFFFF, "X");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 263, 0x0FFFFF, "Z");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 213, 0x0FFFFF, "Z up");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 263, 0x0FFFFF, "Z down");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 313, 0x0FFFFF, "W");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 363, 0x0FFFFF, "S");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 313, 0x0FFFFF, "up");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 363, 0x0FFFFF, "down");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 413, 0x0FFFFF, "D");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 463, 0x0FFFFF, "A");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 413, 0x0FFFFF, "right");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 463, 0x0FFFFF, "left");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 513, 0x0FFFFF, "I");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 513, 0x0FFFFF, "ISO & PAR");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 563, 0x0FFFFF, "+");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 563, 0x0FFFFF, "Speed up");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 613, 0x0FFFFF, "-");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 613, 0x0FFFFF, "Speed down");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 30, 663, 0xFFF000, "C");
	mlx_string_put(v->mlx_ptr, v->win_ptr, 60, 663, 0xFFF000, "DANCE COLOR");
}

void	draw_btn(t_var *v, int x, int y)
{
	int i;

	i = 120 + y;
	while (i < 150 + y)
	{
		mlx_pixel_put(v->mlx_ptr, v->win_ptr, 10 + x, i, 0xFFFFFF);
		mlx_pixel_put(v->mlx_ptr, v->win_ptr, 40 + x, i++, 0xFFFFFF);
	}
	i = 10 + x;
	while (i < 40 + x)
	{
		mlx_pixel_put(v->mlx_ptr, v->win_ptr, i, 120 + y, 0xFFFFFF);
		mlx_pixel_put(v->mlx_ptr, v->win_ptr, i++, 150 + y, 0xFFFFFF);
	}
}
