#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* int main(void)
{
	void    *mlx;
	void    *win;

	mlx = mlx_init(); // Initialiser la connexion à X11
	win = mlx_new_window(mlx, 800, 600, "Ma première fenêtre");
		// Création fenêtre
	mlx_loop(mlx); // Boucle infinie qui attend les événements
	(void)win;
	return (0);
} */
/* Exo 1 :
Crée une fenêtre 500×500 intitulée "Hello MLX".

Change la taille et le titre.

Teste avec plusieurs fenêtres ouvertes (appelle mlx_new_window() deux fois).
*/

// int main(void)
// {
// 	void	*mlx;
// 	void	*windows;

// 	mlx = mlx_init();
// 	(void)windows;
// 	windows = mlx_new_window(mlx, 500, 500, "Hello MLX");
// 	mlx_loop(mlx);
// }

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

// int close_window(void *param)
// {
//     (void)param;
//     exit(0);
// }

// int main(void)
// {
//     void *mlx = mlx_init();
//     void *win = mlx_new_window(mlx, 500, 500, "Fermer proprement");

//     mlx_hook(win, 17, 0, close_window, NULL); // Gestion de la croix
//     mlx_loop(mlx);
// }

/*
📝 Exercice 3

Objectif :

Ouvre une fenêtre 600×400.

Ferme la fenêtre correctement quand on clique sur la croix.

Bonus : affiche "Bye!" dans le terminal avant de quitter.

Tu peux coder ça et me coller ton résultat ; je te dirai si c’est correct ✅ ou pas ❌.
*/

// int close_window(void *param)
// {
// 	(void)param;
// 	printf("Bye\n");
// 	exit(0);
// }

// int main(void)
// {
// 	void *mlx;
// 	void *win;

// 	mlx = mlx_init();
// 	win = mlx_new_window(mlx, 600, 400, "close");
// 	mlx_hook(win, 17, 0, close_window, NULL);
// 	mlx_loop(mlx);
// }

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

int	main(void)
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
}