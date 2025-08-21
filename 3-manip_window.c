#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



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
