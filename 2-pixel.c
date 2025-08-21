#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*📝 Exercice 2

Objectif :

Crée une fenêtre 800x600

Affiche un pixel rouge en haut à gauche (0,0)

Affiche un pixel bleu en bas à droite

Quand tu as fini, colle ton code et je te dirai si c’est correct ✅ ou pas ❌.  */

// int main(void)
// {
//     void    *mlx;
//     void    *win;

//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 500, 500, "Pixel");
//     mlx_pixel_put(mlx, win, 250, 250, 0x00FF00); // Vert au centre
//     mlx_loop(mlx);
// }

// int main(void)
// {
// 	void *mlx;
// 	void *win;
// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 800, 600, "Pixel rouge et bleu");
// 	mlx_pixel_put(mlx, win, 0, 0, 0xFF0000);
// 	mlx_pixel_put(mlx, win, 799, 599,  0x0000FF);
// 	mlx_loop(mlx);
// }
