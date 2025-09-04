/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:04:33 by romukena          #+#    #+#             */
/*   Updated: 2025/08/30 13:21:46 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
		give_info(win);
	else
		return (0);
	render_fractal(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_win *win)
{
	(void)x;
	(void)y;
	if (button == 4 && win->zoom < MAX_ZOOM)
		win->zoom *= 1.1;
	else if (button == 5 && win->zoom > MIN_ZOOM)
		win->zoom /= 1.1;
	else
		return (0);
	render_fractal(win);
	mlx_put_image_to_window(win->mlx, win->win, win->img.img, 0, 0);
	return (0);
}
