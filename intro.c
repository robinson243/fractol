// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include "minilibx-linux/mlx.h"

// int main(void)
// {
// 	/* Commence toujours le programme avec init on init tjrs un ptr parce qu'on le reutilise partout */
// 	void *mlx_ptr;
// 	void *mlx_win;
// 	mlx_ptr = mlx_init();
// 	if (!mlx_ptr)
// 		return (1);
	
// 	/* Ouvrir une image */
// 	mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "Hello World");
// 	(void)mlx_win;
// 	mlx_loop(mlx_ptr);
// }