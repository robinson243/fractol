/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 17:07:37 by romukena          #+#    #+#             */
/*   Updated: 2025/09/04 11:00:47 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_win	win;
	int		size[2];

	size[0] = 800;
	size[1] = 600;
	init_params(&win);
	if (parse_args(argc, argv, &win, size))
		return (1);
	if (size[0] <= 0 || size[0] > 3840 || size[1] <= 0 || size[1] > 2160)
		return (ft_putstr_fd("Error: Invalid size. Using default 800x600\n", 2),
			free_all(&win), 1);
	if (init_fractol(&win, size[0], size[1]) != 0)
		return (free_all(&win), 1);
	return (0);
}
