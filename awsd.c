
#include "solong.h"
int key_press(int keycode, t_mymlx *mymlx)
{
    if (keycode == 13) // W key
    {
        coin_counter(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited, mymlx);
        if (mymlx->map.splited[mymlx->player.player_x - 1][mymlx->player.player_y] != '1')
        {   
            mymlx->player.player_x--;
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->joseph, mymlx);
            rassam_lmahir(mymlx->player.player_x + 1, mymlx->player.player_y, mymlx->sand, mymlx);
            exit_deleter(mymlx->player.player_x+1, mymlx->player.player_y, mymlx);
        }
    }
    else if (keycode == 1) // S key
    { 
        coin_counter(mymlx->player.player_x, mymlx->player.player_y ,mymlx->map.splited, mymlx);
        if (mymlx->map.splited[mymlx->player.player_x + 1][mymlx->player.player_y] != '1')
        { 
            mymlx->player.player_x++;      
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->joseph, mymlx);
            rassam_lmahir(mymlx->player.player_x - 1, mymlx->player.player_y, mymlx->sand, mymlx);
            exit_deleter(mymlx->player.player_x-1, mymlx->player.player_y, mymlx);
        }
    }
    else if (keycode == 0) // A key
    {   
        coin_counter(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited, mymlx);
        if (mymlx->map.splited[mymlx->player.player_x][mymlx->player.player_y - 1] != '1')
        {     
            mymlx->player.player_y--;
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->joseph, mymlx);
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y + 1, mymlx->sand, mymlx);
            exit_deleter(mymlx->player.player_x, mymlx->player.player_y+1, mymlx);
        }
    }
    else if (keycode == 2) // D key
    {
        coin_counter(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited, mymlx);
        if (mymlx->map.splited[mymlx->player.player_x][mymlx->player.player_y + 1] != '1')
        {
            mymlx->player.player_y++;
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->joseph, mymlx);   // joseph
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y - 1, mymlx->sand, mymlx); // sand
            //printf("x == %d, y == %d \n",mymlx->player.player_x, mymlx->player.player_y);
            exit_deleter(mymlx->player.player_x, mymlx->player.player_y-1,   mymlx);
        }
    }
    return 0;
}

    void coin_counter(int i, int j, char **splited, t_mymlx *mymlx)
    {

        if (splited[i][j] == 'C')
        {

           mymlx->coincounter+=1;
           
            splited[i][j] = '0';
        }
        if (mymlx->num_coins -1 == mymlx->coincounter){
               
            mlx_string_put(mymlx->mlx, mymlx->mlx_win, 12, 10, 0xffffff, "all coins are collected ! Exit now ");
             mymlx->coin_yes = 1; // all coins are collected
        }
    }