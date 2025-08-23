/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:03:25 by romukena          #+#    #+#             */
/*   Updated: 2025/08/24 00:05:15 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_window(t_win *win, int width, int height, char *title)
{
	win->mlx = mlx_init();
	if (!win->mlx)
		exit(1);
	win->win = mlx_new_window(win->mlx, width, height, title);
	if (!win->win)
		exit(1);
	win->img.img = mlx_new_image(win->mlx, width, height);
	if (!win->img.img)
		exit(1);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bpp,
			&win->img.line_len, &win->img.endian);
	win->img.w = width;
	win->img.h = height;
	win->width = width;
	win->height = height;
	win->zoom = 1.0;
	win->offset_x = 0.0;
	win->offset_y = 0.0;
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	close_window(t_win *win)
{
	mlx_destroy_image(win->mlx, win->img.img);
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
	return (0);
}

void	give_info(t_win *win)
{
	win->zoom = 1.0;
	win->offset_x = 0.0;
	win->offset_y = 0.0;
}
