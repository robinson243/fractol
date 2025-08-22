/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:07:37 by romukena          #+#    #+#             */
/*   Updated: 2025/08/22 22:00:04 by romukena         ###   ########.fr       */
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
	mlx_destroy_image(win->mlx, win->img.img);
	mlx_destroy_window(win->mlx, win->win);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_win *win)
{
	if (keycode == 65307)
		close_window(win);
	else if (keycode == 65361)
		win->offset_x -= 0.1 / win->zoom;
	else if (keycode == 65363)
		win->offset_x += 0.1 / win->zoom;
	else if (keycode == 65362)
		win->offset_y -= 0.1 / win->zoom;
	else if (keycode == 65364)
		win->offset_y += 0.1 / win->zoom;
	else if (keycode == 65451 && win->zoom < MAX_ZOOM)
		win->zoom *= 1.1;
	else if (keycode == 65453 && win->zoom > MIN_ZOOM)
		win->zoom /= 1.1;
	else if (keycode == 114)
	{
		win->zoom = 1.0;
		win->offset_x = 0.0;
		win->offset_y = 0.0;
	}
	else
		return (0);
	render_fractal(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
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
	render_fractal(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	return (0);
}

int	calculate_mandelbrot(double c_re, double c_im)
{
	double	z_re;
	double	z_im;
	double	temp_re;
	double	temp_im;
	int		i;

	z_re = 0;
	z_im = 0;
	i = 0;
	while (i < MAX_ITER)
	{
		if ((z_im * z_im) + (z_re * z_re) > ESCAPE_RADIUS * ESCAPE_RADIUS)
			break ;
		temp_re = z_re;
		temp_im = z_im;
		z_re = (temp_re * temp_re) - (temp_im * temp_im) + c_re;
		z_im = 2 * temp_re * temp_im + c_im;
		i++;
	}
	return (i);
}

int	get_color(int iter)
{
	static int	color[5];

	color[0] = 0xCDB4DB;
	color[1] = 0xFFC8DD;
	color[2] = 0xFFAFCC;
	color[3] = 0xBDE0FE;
	color[4] = 0xA2D2FF;
	if (iter == MAX_ITER)
		return (0x000000);
	return (color[iter % 5]);
}

void	screen_to_complex(t_win *win, int x, int y, double out[2])
{
	double	scale;

	scale = 4.0 / (win->width * win->zoom);
	out[0] = (x - win->width / 2.0) * scale + win->offset_x;
	out[1] = (y - win->height / 2.0) * scale + win->offset_y;
}

void	render_fractal(t_win *win)
{
	int		x;
	int		y;
	double	out[2];
	int		iter;

	y = 0;
	while (y < win->height)
	{
		x = 0;
		while (x < win->width)
		{
			screen_to_complex(win, x, y, out);
			iter = calculate_mandelbrot(out[0], out[1]);
			put_pixel(&win->img, x, y, get_color(iter));
			x++;
		}
		y++;
	}
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (sign * result);
}

int	main(int argc, char **argv)
{
	t_win	win;
	int		width;
	int		height;

	width = 800;
	height = 600;
	if (argc == 3)
	{
		width = ft_atoi(argv[1]);
		height = ft_atoi(argv[2]);
		if (width <= 0 || height <= 0 || width > 3840 || height > 2160)
		{
			printf("Error: Invalid window size. Using default 800x600\n");
			width = 800;
			height = 600;
		}
	}
	else if (argc != 1)
	{
		printf("Usage: %s [width height]\n", argv[0]);
		return (1);
	}
	init_window(&win, width, height, "Mandelbrot");
	mlx_hook(win.win, 2, 1L << 0, handle_keypress, &win);
	mlx_hook(win.win, 4, 1L << 2, handle_mouse, &win);
	mlx_hook(win.win, 17, 0, close_window, &win);
	render_fractal(&win);
	mlx_put_image_to_window(win.mlx, win.win, win.img.img, 0, 0);
	mlx_loop(win.mlx);
	return (0);
}
