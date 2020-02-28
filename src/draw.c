/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 17:52:03 by anabaoui          #+#    #+#             */
/*   Updated: 2019/05/17 01:10:06 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	iso(int *x, int *y, t_var *v, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = v->xmove + (previous_x - previous_y) * cos(0.523599);
	*y = v->ymove + (previous_x + previous_y) * sin(0.523599) - z;
}

void		draw_line(t_axes *point, t_var *v, int z)
{
	t_draw_info	draw_info;

	draw_info.acm = 0;
	draw_info.width = v->width * v->scale;
	draw_info.dx = point[1].x - point[0].x;
	draw_info.dy = point[1].y - point[0].y;
	if (draw_info.dx > 0)
		draw_info.movex = 1;
	else
		draw_info.movex = -1;
	if (draw_info.dy > 0)
		draw_info.movey = 1;
	else
		draw_info.movey = -1;
	if (abs(draw_info.dx) > abs(draw_info.dy))
		draw_info.x = 1;
	else
		draw_info.x = 0;
	draw_image(point, draw_info, v, z);
}

void		go_draw_line(t_var *v, t_axes *p)
{
	if (v->y < v->height && v->x + 1 < v->width)
	{
		p[1].x = (v->x + 1) * v->scale + ((!v->iso) ? v->xmove : 0);
		p[1].y = v->y * v->scale + ((!v->iso) ?
				(-v->scale * v->tab[v->y][v->x + 1] * v->zmove + v->ymove) : 0);
		if (v->iso)
			iso(&(p[1].x), &(p[1].y), v, v->scale *
					v->tab[v->y][v->x + 1] * v->zmove);
		draw_line(p, v, v->tab[v->y][v->x] || v->tab[v->y][v->x + 1]);
	}
	if (v->x < v->width && v->y + 1 < v->height)
	{
		p[1].x = v->x * v->scale + ((!v->iso) ? v->xmove : 0);
		p[1].y = (v->y + 1) * v->scale + ((!v->iso) ?
				(-v->scale * v->tab[v->y + 1][v->x] * v->zmove + v->ymove) : 0);
		if (v->iso)
			iso(&(p[1].x), &(p[1].y), v, v->scale *
					v->tab[v->y + 1][v->x] * v->zmove);
		draw_line(p, v, v->tab[v->y][v->x] || v->tab[v->y + 1][v->x]);
	}
}

void		go_draw(t_var *v)
{
	t_axes p[2];

	v->y = 0;
	while (v->y < v->height)
	{
		v->x = 0;
		while (v->x < v->width)
		{
			p[0].x = v->x * v->scale + ((!v->iso) ? v->xmove : 0);
			p[0].y = v->y * v->scale + ((!v->iso) ?
					(-v->scale * v->tab[v->y][v->x] * v->zmove + v->ymove) : 0);
			if (v->iso)
				iso(&(p[0].x), &(p[0].y), v, v->scale *
						v->tab[v->y][v->x] * v->zmove);
			go_draw_line(v, p);
			v->x++;
		}
		v->y++;
	}
}

int			draw(t_var *v)
{
	initialization(v, 'i');
	v->color = v->color_effect;
	v->mlx_ptr = mlx_init();
	v->win_ptr = mlx_new_window(v->mlx_ptr, 1300, 700, "1337 FDF");
	v->img_ptr = mlx_new_image(v->mlx_ptr, IMG_W, IMG_H);
	v->img_data = (int *)mlx_get_data_addr(v->img_ptr, &v->bpp,
			&v->size_l, &v->endian);
	go_draw(v);
	mlx_hook(v->win_ptr, 2, 1, keys_hook, v);
	mlx_mouse_hook(v->win_ptr, mouse_hook, v);
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->img_ptr, 210, 0);
	instruction(v);
	mlx_loop(v->mlx_ptr);
	return (1);
}
