/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 00:12:22 by romukena          #+#    #+#             */
/*   Updated: 2025/09/04 16:11:19 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	error_messages(void)
{
	ft_putstr_fd("Usage: ./fractol <fractal_type> [parameters]\n", 2);
	ft_putstr_fd("Available fractals:\n", 2);
	ft_putstr_fd("  mandelbrot [width height]\n", 2);
	ft_putstr_fd("  julia [c_real c_imaginary] [width height]\n", 2);
	ft_putstr_fd("  burningship [width height]\n", 2);
	ft_putstr_fd("Examples:\n", 2);
	ft_putstr_fd("  ./fractol mandelbrot\n", 2);
	ft_putstr_fd("  ./fractol mandelbrot 1024 768\n", 2);
	ft_putstr_fd("  ./fractol julia -0.7 0.27015\n", 2);
	ft_putstr_fd("  ./fractol julia -0.4 0.6 1200 800\n", 2);
	ft_putstr_fd("  ./fractol bruningship\n", 2);
	ft_putstr_fd("  ./fractol bruningship 1024 768\n", 2);
	return (1);
}

int	parse_mandelbrot(int argc, char **argv, int *w, int *h)
{
	if (argc >= 4)
	{
		*w = ft_atoi(argv[2]);
		*h = ft_atoi(argv[3]);
	}
	return (0);
}

int	parse_julia(int argc, char **argv, t_win *win, int *size)
{
	init_julia_default(win);
	if (argc >= 4)
	{
		win->julia_c_re = ft_atod(argv[2]);
		win->julia_c_im = ft_atod(argv[3]);
	}
	if (argc >= 6)
	{
		size[0] = ft_atoi(argv[4]);
		size[1] = ft_atoi(argv[5]);
	}
	return (0);
}

int	parse_burningship(int ac, char **av, int *size)
{
	if (ac >= 4)
	{
		size[0] = ft_atoi(av[4]);
		size[1] = ft_atoi(av[5]);
	}
	return (0);
}

int	parse_args(int argc, char **argv, t_win *win, int *size)
{
	if (argc < 2)
		return (error_messages());
	if (!ft_strcmp(argv[1], "mandelbrot"))
	{
		win->fractol_type = 0;
		return (parse_mandelbrot(argc, argv, &size[0], &size[1]));
	}
	else if (!ft_strcmp(argv[1], "burningship"))
	{
		win->fractol_type = 2;
		return (parse_burningship(argc, argv, size));
	}
	else if (!ft_strcmp(argv[1], "julia"))
		return (parse_julia(argc, argv, win, size));
	return (ft_putstr_fd("Error: Unknown fractal type. Use mandelbrot/julia\n",
			2), 1);
}
