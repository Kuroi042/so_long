#include "solong.h"
t_mymlx mymlx;
t_mymap mymap;
t_mymlx *ptr = &mymlx;
void projec(int x , int y)
{
   
    ptr->wall = mlx_xpm_file_to_image(ptr->mlx, "waall.xpm", &x, &y);
    ptr->sand = mlx_xpm_file_to_image(ptr->mlx, "sand.xpm", &x, &y);
    ptr->joseph = mlx_xpm_file_to_image(ptr->mlx, "jooseph.xpm", &x, &y);
    ptr->coin = mlx_xpm_file_to_image(ptr->mlx, "bassit.xpm", &x, &y);
    ptr->exit = mlx_xpm_file_to_image(ptr->mlx, "kherja.xpm", &x, &y);
}

void drawingxpm(int num_rows, int num_col, char **splited)
{
    int i = 0;
    int j = 0;
    while (i < num_rows)
    {
        j = 0;
        while (j < num_col)
        {
            if (splited[i][j] == '1')
                mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->wall, j * 32, i * 32);
            if (splited[i][j] == '0')
                mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->sand, j * 32, i * 32);
            if (splited[i][j] == 'P')
                mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->joseph, j * 32, i * 32);
            if (splited[i][j] == 'C')
                mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->coin, j * 32, i * 32);
            if (splited[i][j] == 'E')
            {
                mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->exit, j * 32, i * 32);
                if (ptr->exit == NULL)
                {
                    write(1, "Error: failed to load image\n", 29);
                    exit(EXIT_FAILURE);
                }
            }
            j++;
        }
        i++;
    }
}