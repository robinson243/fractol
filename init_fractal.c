/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:11:02 by romukena          #+#    #+#             */
/*   Updated: 2025/08/24 00:11:28 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_fractol(t_win *win, int width, int height)
{
	init_window(win, width, height, "Fractol");
	render_fractal(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	mlx_hook(win->win, 2, 1L << 0, handle_keypress, win);
	mlx_hook(win->win, 4, 1L << 2, handle_mouse, win);
	mlx_hook(win->win, 17, 0, close_window, win);
	mlx_loop(win->mlx);
}

void	init_params(t_win *win)
{
	win->fractol_type = -1;
	win->c_re = 0.0;
	win->c_im = 0.0;
	win->julia_c_re = 0.0;
	win->julia_c_im = 0.0;
}

void	init_julia_default(t_win *win)
{
	win->fractol_type = 1;
	win->c_re = -0.7;
	win->c_im = 0.27015;
	win->julia_c_re = win->c_re;
	win->julia_c_im = win->c_im;
}
