#include "solong.h"
void projec(int x, int y, t_mymlx *mymlx)
{

    mymlx->wall = mlx_xpm_file_to_image(mymlx->mlx, "xpms/waall.xpm", &x, &y);
    mymlx->sand = mlx_xpm_file_to_image(mymlx->mlx, "xpms/sand.xpm", &x, &y);
    mymlx->joseph = mlx_xpm_file_to_image(mymlx->mlx, "xpms/jooseph.xpm", &x, &y);
    mymlx->coin = mlx_xpm_file_to_image(mymlx->mlx, "xpms/bassit.xpm", &x, &y);
    mymlx->exit = mlx_xpm_file_to_image(mymlx->mlx, "xpms/kherja.xpm", &x, &y);
    mymlx->enter = mlx_xpm_file_to_image(mymlx->mlx ,"xpms/dkhel.xpm" , &x,&y);
}
void drawingxpm(int i, int j, char **splited, t_mymlx *mymlx)
{
    while (i < mymlx->map.num_rows)
    {
        j = 0;
        while (j < mymlx->map.num_col)
        {
            if (splited[i][j] == '1')
                mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win, mymlx->wall, j * 32, i * 32);
            if (splited[i][j] == '0' || splited[i][j] == 'E' || splited[i][j] == 'P' || splited[i][j] == 'C')
                mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win, mymlx->sand, j * 32, i * 32);
            if (splited[i][j] == 'P')
            {
                mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win, mymlx->joseph, j * 32, i * 32);
                mymlx->player.player_x = i;
                mymlx->player.player_y = j;
            }
            if (splited[i][j] == 'C')
            {
                mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win, mymlx->coin, j * 32, i * 32);
                mymlx->num_coins++;
            }
            if (splited[i][j] == 'E')
                
                mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win, mymlx->exit, j * 32, i * 32);
            j++;
        }
        i++;
    }
}

void rassam_lmahir(int i, int j, void *image ,t_mymlx *mymlx)
{   
    if (mymlx->map.splited[i][j] == 'E' && mymlx->coincounter != mymlx->num_coins) {
        mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win, mymlx->enter, j * 32, i * 32);
   
    } 
    else {
        mlx_put_image_to_window(mymlx->mlx, mymlx->mlx_win,  image, j * 32, i * 32);
    }
}
void exit_deleter(int i, int j,t_mymlx *mymlx){

    if(mymlx->map.splited[i][j] == 'E' &&  mymlx->coincounter != mymlx->num_coins){ // kant katssawi
       printf("3afsaaak\n");
       mlx_put_image_to_window( mymlx->mlx, mymlx->mlx_win,  mymlx->exit, j * 32, i * 32);
    }
   if(mymlx->map.splited[i][j] == 'E' &&  mymlx->coin_yes == 1){
        printf("exiiit\n");
        exit(0);
    }
}
