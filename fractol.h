/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:36:27 by romukena          #+#    #+#             */
/*   Updated: 2025/08/23 22:24:34 by romukena         ###   ########.fr       */
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
	double	c_re;
	double	c_im;
	double	julia_c_re;
	double	julia_c_im;
	int		fractol_type;
}			t_win;

/* Window functions */
void		init_window(t_win *win, int width, int height, char *title);
void		put_pixel(t_img *img, int x, int y, int color);
void		fill_background(t_img *img, int color);
int			close_window(t_win *win);
void		init_fractol(t_win *win, int width, int height);

/* Event handlers */
int			handle_keypress(int keycode, t_win *win);
int			handle_mouse(int button, int x, int y, t_win *win);
void		give_info(t_win *win);

/* Fractal calculations */
int			calculate_mandelbrot(double c_re, double c_im);
int			calculate_julia(double z_re, double z_im, double c_re, double c_im);
void		render_fractal(t_win *win);
void		screen_to_complex(t_win *win, int x, int y, double out[2]);

/* Color functions */
int			get_color(int iter);

/* Utility functions */
int			ft_atoi(const char *str);
int			ft_strcmp(char *s1, char *s2);
void		ft_putstr_fd(char *s, int fd);
double		ft_atod(const char *str);

/* Parse functions */
int			error_messages(void);
void		init_params(t_win *win);
int			parse_args(int argc, char **argv, t_win *win, int *size);
int			parse_julia(int argc, char **argv, t_win *win, int *size);
int			parse_mandelbrot(int argc, char **argv, int *w, int *h);
void		init_julia_default(t_win *win);
void		init_params(t_win *win);

#endif