#include "solong.h"
t_mymlx mymlx;
t_mymap mymmap;
void mapdrwing(int nr, int nc , char **splited, void *mlx , void *mlx_win){
int i = 0;
int j = 0;

  while (i < nr)
    {
        j = 0;
        while (j < nc)
        {
            if(splited[i][j] == '1')
                mlx_put_image_to_window(mlx,mlx_win, mymlx.sand, j * mymlx.tool, i * mymlx.ard);
            if(splited[i][j] == '0')
                mlx_put_image_to_window(mlx,mlx_win, mymlx.wall, j * mymlx.tool, i * mymlx.ard); 
                if(splited[i][j] == 'P')
                mlx_put_image_to_window(mlx,mlx_win, mymlx.jooseph, j * mymlx.tool, i * mymlx.ard);
            if(splited[i][j] == 'E')
                mlx_put_image_to_window(mlx,mlx_win, mymlx.exit, j * mymlx.tool, i * mymlx.ard);
            if(splited[i][j] == 'C')
                mlx_put_image_to_window(mlx,mlx_win, mymlx.coin, j * mymlx.tool, i * mymlx.ard);
            
            j++;
        }
        i++;
    }


}