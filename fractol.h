/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:36:27 by romukena          #+#    #+#             */
/*   Updated: 2025/08/22 21:59:36 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "minilibx-linux/mlx.h"
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MIN_ZOOM 0.1
# define MAX_ZOOM 1000000000.0
# define MAX_ITER 100
# define ESCAPE_RADIUS 2.0

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		w;
	int		h;
}			t_img;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		width;
	int		height;
	double	zoom;
	double	offset_x;
	double	offset_y;
	double	mouse_x;
	double	mouse_y;
}			t_win;

typedef struct s_fractal
{
	int		type;
	double	c_re;
	double	c_im;
}			t_fractal;

void		init_window(t_win *win, int width, int height, char *title);
void		put_pixel(t_img *img, int x, int y, int color);
void		fill_background(t_img *img, int color);
int			close_window(t_win *win);
int			handle_keypress(int keycode, t_win *win);
int			handle_mouse(int button, int x, int y, t_win *win);
int			calculate_mandelbrot(double c_re, double c_im);
int			get_color(int iter);
void		screen_to_complex(t_win *win, int x, int y, double out[2]);
void		render_fractal(t_win *win);
int			ft_atoi(const char *str);

#endif