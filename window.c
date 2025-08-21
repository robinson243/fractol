/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:07:37 by romukena          #+#    #+#             */
/*   Updated: 2025/08/21 18:39:58 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_window(t_win *win, int width, int height, char *title)
{
	win->mlx = mlx_init();
	win->win = mlx_new_window(win->mlx, width, height, title);
	win->img.img = mlx_new_image(win->mlx, width, height);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bpp,
			&win->img.line_len, &win->img.endian);
	win->img.w = width;
	win->img.h = height;
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

void	fill_background(t_img *img, int color)
{
	int	start_x;
	int	start_y;

	start_x = 0;
	start_y = 0;
	while (start_y < img->h)
	{
		start_x = 0;
		while (start_x < img->w)
		{
			put_pixel(img, start_x, start_y, color);
			start_x++;
		}
		start_y++;
	}
}

int	close_window(t_win *win)
{
	mlx_destroy_window(win->mlx, win->win);
	free(win->img.img);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_win *win)
{
	if (keycode == 65307)
		close_window(win);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_win *win)
{
	double	new_x;
	double	new_y;

	new_x = (x - win->width / 2) / win->zoom + win->offset_x;
	new_y = (y - win->height / 2) / win->zoom + win->offset_y;
	if (button == 4 && win->zoom < MAX_ZOOM)
		win->zoom *= 1.1;
	if (button == 5 && win->zoom > MIN_ZOOM)
		win->zoom /= 1.1;
	win->offset_x = new_x - (x - win->width / 2) / win->zoom;
	win->offset_y = new_y - (y - win->height / 2) / win->zoom;
	return (0);
}

int	main(void)
{
	t_win	win;

	init_window(&win, 800, 600, "Test Background");
	fill_background(&win.img, 0x00FF0000);
	mlx_put_image_to_window(win.mlx, win.win, win.img.img, 0, 0);
	mlx_loop(win.mlx);
	return (0);
}
