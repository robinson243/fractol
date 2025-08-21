#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* int	main(void)
{
	void *mlx_ptr;
	void *win;
	mlx_ptr = mlx_init();
	void *img = mlx_new_image(mlx_ptr, 500, 500);

	int bpp, line_length, endian;
	char *addr = mlx_get_data_addr(img, &bpp, &line_length, &endian);
	win = mlx_new_window(mlx_ptr, 500, 500, "test");

	int height = 60;
	int width = 100;
	int start_x = 200;
	int start_y = 220;
	for (int y = start_y; y < start_y + height; y++)
	{
		for (int x = start_x; x < start_x + width; x++)
		{
			if ((y == start_y || y == start_y + height - 1) || ( x == start_x || x == start_x + width - 1))
			{
				char *pixel = addr + (y * line_length + x * (bpp / 8));
				*(unsigned int *)pixel = 0xFF0000;
			}
		}
	}
	mlx_put_image_to_window(mlx_ptr, win, img, 0, 0);
	mlx_loop(mlx_ptr);
} */