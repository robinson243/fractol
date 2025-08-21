#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// /* Definition des couleurs */
// typedef struct s_color {
//     int r, g, b;
// } t_color;

// /* t_color blue = {0, 0, 255};    // Bleu pur
// t_color red = {255, 0, 0};     // Rouge pur
// t_color yellow = {255, 255, 0}; // Jaune */

// /* ⚡ Étape 2 : Interpoler entre 2 couleurs

// Le principe d’un dégradé = mélanger 2 couleurs en fonction d’un ratio entre 0 et 1.

// Si ratio = 0 → couleur de départ

// Si ratio = 1 → couleur d’arrivée

// Si ratio = 0.5 → pile au milieu */

// int interpolate(t_color start, t_color end, float ratio) {
//     int r = start.r + (end.r - start.r) * ratio;
//     int g = start.g + (end.g - start.g) * ratio;
//     int b = start.b + (end.b - start.b) * ratio;
//     return (r << 16) | (g << 8) | b; // format 0xRRGGBB
// }

// /* 
// ⚡ Étape 3 : Utiliser ça pour un dégradé horizontal

// On veut remplir une ligne de pixels du rouge → bleu.

// On parcourt la largeur du rectangle

// Pour chaque pixel x, on calcule un ratio en fonction de sa position : */

// void draw_horizontal_gradient(char *addr, int bpp, int line_length,
//                               int start_x, int start_y, int width, int height,
//                               t_color c1, t_color c2)
// {
//     for (int y = start_y; y < start_y + height; y++)
//     {
//         for (int x = start_x; x < start_x + width; x++)
//         {
//             // Calculer la progression de gauche (0) à droite (1)
//             float ratio = (float)(x - start_x) / (float)(width - 1);

//             // Obtenir la couleur interpolée
//             int color = interpolate(c1, c2, ratio);

//             // Positionner le pixel
//             char *pixel = addr + (y * line_length + x * (bpp / 8));
//             *(unsigned int *)pixel = color;
//         }
//     }
// }

// void draw_vertical_gradient(char *addr, int bpp, int line_length,
//                               int start_x, int start_y, int width, int height,
//                               t_color c1, t_color c2)
// {
//     for (int y = start_y; y < start_y + height; y++)
//     {
//         for (int x = start_x; x < start_x + width; x++)
//         {
//             // Calculer la progression de gauche (0) à droite (1)
//             float ratio = (float)(y - start_y) / (float)(height - 1);

//             // Obtenir la couleur interpolée
//             int color = interpolate(c1, c2, ratio);

//             // Positionner le pixel
//             char *pixel = addr + (y * line_length + x * (bpp / 8));
//             *(unsigned int *)pixel = color;
//         }
//     }
// }

// int main(void)
// {
//     void    *mlx;
//     void    *win;
//     void    *img;
//     char    *addr;
//     int     bpp, line_length, endian;

//     // Init MiniLibX
//     mlx = mlx_init();
//     win = mlx_new_window(mlx, 500, 300, "Dégradé Horizontal");
//     img = mlx_new_image(mlx, 500, 300);
//     addr = mlx_get_data_addr(img, &bpp, &line_length, &endian);

//     // Couleurs
//     t_color blue = {0, 0, 255};
//     t_color red = {255, 0, 0};

//     // Dessiner un dégradé bleu → rouge
//     draw_vertical_gradient(addr, bpp, line_length, 0, 0, 500, 300, blue, red);

//     // Afficher l’image
//     mlx_put_image_to_window(mlx, win, img, 0, 0);

//     mlx_loop(mlx);
// }
