/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anabaoui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 16:52:01 by anabaoui          #+#    #+#             */
/*   Updated: 2019/05/17 01:03:03 by hhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <mlx.h>
# include <math.h>
# define BUFF_SIZE 32

# define IMG_W 3000
# define IMG_H 2000
# define SCALE 27

typedef struct	s_axes
{
	int	x;
	int	y;
}				t_axes;

typedef struct	s_draw_info
{
	int x;
	int acm;
	int width;
	int dx;
	int dy;
	int movex;
	int movey;
}				t_draw_info;

typedef struct	s_var
{
	int		**tab;
	int		height;
	int		width;
	int		max_width;
	char	*line;
	char	**split_line;
	int		fd;
	int		x;
	int		y;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_data;
	int		bpp;
	int		size_l;
	int		endian;
	int		scale;
	int		xmove;
	int		ymove;
	float	speed;
	float	zmove;
	int		iso;
	int		color_effect;
	int		color;
}				t_var;

int				get_next_line(const int fd, char **line);
int				fdf(char *argv);
int				draw(t_var *v);
void			instruction(t_var *v);
void			initialization(t_var *v, char c);
int				keys_hook(int key, t_var *v);
void			go_draw(t_var *v);
void			draw_btn(t_var *v, int x, int y);
void			btn_content(t_var *v);
void			draw_image(t_axes *point, t_draw_info d, t_var *v, int z);
int				mouse_hook(int m, int x, int y, t_var *v);
#endif
