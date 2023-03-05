#include "solong.h"
t_mymlx mymlx;

t_mymlx *ptr = &mymlx;
void projec(int x , int y)
{
   
    ptr->wall = mlx_xpm_file_to_image(ptr->mlx, "waall.xpm", &x, &y);
    ptr->sand = mlx_xpm_file_to_image(ptr->mlx, "sand.xpm", &x, &y);
    ptr->joseph = mlx_xpm_file_to_image(ptr->mlx, "jooseph.xpm", &x, &y);
    ptr->coin = mlx_xpm_file_to_image(ptr->mlx, "bassit.xpm", &x, &y);
    ptr->exit = mlx_xpm_file_to_image(ptr->mlx, "kherja.xpm", &x, &y);
}

void drawingxpm(int i, int j, char **splited)
{
    while (i < mymlx.map->num_rows)
    {
        j = 0;
        while (j < mymlx.map->num_col)
        {
            if (splited[i][j] == '1')
                mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->wall, j * 32, i * 32);
            if (splited[i][j] == '0' || splited[i][j] == 'E' || splited[i][j] == 'P' || splited[i][j] == 'C')
                mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->sand, j * 32, i * 32);
            if (splited[i][j] == 'P'){
                mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->joseph, j * 32, i * 32);           
                mymlx.player->player_x = i;
                mymlx.player->player_y = j;
            }
            if (splited[i][j] == 'C'){
                mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->coin, j * 32, i*32);
                    mymlx.num_coins++;
            }
            if (splited[i][j] == 'E')
                mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->exit, j * 32, i *32);
            j++;
        }
        i++;
    }
}

void rassam_lmahir(int i, int j, void *image ) {
    mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, image, j*32, i*32);
}

