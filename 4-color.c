#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// int main(void)
// {
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, 500, 500, "Image");

//     // 1. Créer une image
//     void *img = mlx_new_image(mlx, 500, 500);

//     // 2. Récupérer un pointeur vers la mémoire des pixels
//     int bpp, line_length, endian;
//     char *addr = mlx_get_data_addr(img, &bpp, &line_length, &endian);

//     // 3. Modifier un pixel à (250,250) en rouge
//     int x = 250;
//     int y = 250;
//     char *pixel = addr + (y * line_length + x * (bpp / 8));
//     *(unsigned int *)pixel = 0xFF0000;

//     // 4. Afficher l'image dans la fenêtre
//     mlx_put_image_to_window(mlx, win, img, 0, 0);

//     mlx_loop(mlx);
// }

// int main(void)
// {
// 	void *mlx_ptr;
// 	void *win;
// 	mlx_ptr = mlx_init();
// 	void *img = mlx_new_image(mlx_ptr, 500, 500);

// 	int bpp, line_length, endian;
// 	char *addr = mlx_get_data_addr(img, &bpp, &line_length, &endian);
// 	win = mlx_new_window(mlx_ptr, 500, 500, "test");
// 	int square_size = 50;
// 	int start_x = 225;
// 	int start_y = 225;
// 	for (int y = start_y; y < start_y + square_size; y++)
// 	{
// 		for (int x = start_x; x < start_x + square_size; x++)
// 		{
// 			char *pixel = addr + (y * line_length + x * (bpp / 8));
// 			*(unsigned int *)pixel = 0xFF0000;
// 		}
// 	}
// 	mlx_put_image_to_window(mlx_ptr, win, img, 0, 0);
// 	mlx_loop(mlx_ptr);
// }
