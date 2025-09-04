/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:06:15 by romukena          #+#    #+#             */
/*   Updated: 2025/09/03 00:26:16 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	screen_to_complex(t_win *win, int x, int y, double out[2])
{
	double	scale_x;
	double	scale_y;

	scale_x = 3.0 / (win->width * win->zoom);
	scale_y = 2.0 / (win->height * win->zoom);
	out[0] = (x - win->width / 2.0) * scale_x + win->offset_x;
	out[1] = (y - win->height / 2.0) * scale_y + win->offset_y;
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

int	calculate_julia(double z_re, double z_im, double c_re, double c_im)
{
	double	temp_re;
	double	temp_im;
	int		i;

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
			if (win->fractol_type == 0)
				iter = calculate_mandelbrot(out[0], out[1]);
			else
				iter = calculate_julia(out[0], out[1], win->julia_c_re,
						win->julia_c_im);
			put_pixel(&win->img, x, y, get_color(iter));
			x++;
		}
		y++;
	}
}
