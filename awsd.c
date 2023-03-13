#include "solong.h"
int key_press(int keycode, t_mymlx *mymlx)
{
    if (keycode == 13) // W key
    {
        if (mymlx->map.splited[mymlx->player.player_x - 1][mymlx->player.player_y] != '1')
        {   
            rassam_lmahir(mymlx->player.player_x-1, mymlx->player.player_y, mymlx->sand, mymlx);
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->sand, mymlx);
            rassam_lmahir(mymlx->player.player_x-1, mymlx->player.player_y, mymlx->joseph, mymlx);
             mymlx->player.player_x--;
            printexit(mymlx);
            coin_counter(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited, mymlx);
            
        }
    }
    else if (keycode == 1) // S key
    { 
        if (mymlx->map.splited[mymlx->player.player_x + 1][mymlx->player.player_y] != '1')
        { 
            rassam_lmahir(mymlx->player.player_x + 1 , mymlx->player.player_y, mymlx->sand, mymlx);
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->sand, mymlx);
            rassam_lmahir(mymlx->player.player_x + 1, mymlx->player.player_y, mymlx->joseph, mymlx);
            mymlx->player.player_x++;   
            printexit(mymlx);
            coin_counter(mymlx->player.player_x, mymlx->player.player_y ,mymlx->map.splited, mymlx);
        }
    }
    else if (keycode == 0) // A key
    {   
        if (mymlx->map.splited[mymlx->player.player_x][mymlx->player.player_y - 1] != '1')
        {     
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y-1, mymlx->sand, mymlx); // next place sand
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->sand, mymlx); //sand 
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y-1, mymlx->joseph, mymlx); //joseph nxt place
            mymlx->player.player_y--;
            printexit(mymlx);
            coin_counter(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited, mymlx);
        }
    }
    else if (keycode == 2) // D key
    {
       
        if (mymlx->map.splited[mymlx->player.player_x][mymlx->player.player_y + 1] != '1')
        {
           rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y +1, mymlx->sand, mymlx); //sand
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->sand, mymlx);   // joseph
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y +1, mymlx->joseph, mymlx); // sand
             mymlx->player.player_y++;
            printexit(mymlx);
             coin_counter(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited, mymlx);
        }
    }
    return 0;
}

    void coin_counter(int i, int j, char **splited, t_mymlx *mymlx)
    {

        if (splited[i][j] == 'C')
        {

           mymlx->coincounter+=1;
           printf("num coins = %d\n",mymlx->coincounter);
            splited[i][j] = '0';
        }
        if (mymlx->num_coins == mymlx->coincounter){
            mymlx->coin_yes = 1;
            mlx_string_put(mymlx->mlx, mymlx->mlx_win, 12, 10, 0xffffff, "all coins are collected ! Exit now ");
    
        }
    }