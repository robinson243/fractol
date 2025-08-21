#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


// int main(void)
// {
// 	void    *mlx;
// 	void    *win;

// 	mlx = mlx_init(); // Initialiser la connexion à X11
// 	win = mlx_new_window(mlx, 800, 600, "Ma première fenêtre");
// 		// Création fenêtre
// 	mlx_loop(mlx); // Boucle infinie qui attend les événements
// 	(void)win;
// 	return (0);
// }
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

/* Close a window */

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