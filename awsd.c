
#include "solong.h"
int key_press(int keycode, t_mymlx *mymlx)
{
    if (keycode == 13) // W key
    {
        coin_counter(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited, mymlx);
        if (mymlx->map.splited[mymlx->player.player_x - 1][mymlx->player.player_y] != '1')
        {   
           
            rassam_lmahir(mymlx->player.player_x-1, mymlx->player.player_y, mymlx->sand, mymlx);
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->sand, mymlx);
            rassam_lmahir(mymlx->player.player_x-1, mymlx->player.player_y, mymlx->joseph, mymlx);
            exit_deleter(mymlx->player.player_x, mymlx->player.player_y, mymlx);
             mymlx->player.player_x--;
            
        }
    }
    else if (keycode == 1) // S key
    { 
        coin_counter(mymlx->player.player_x, mymlx->player.player_y ,mymlx->map.splited, mymlx);
        if (mymlx->map.splited[mymlx->player.player_x + 1][mymlx->player.player_y] != '1')
        { 
            
            rassam_lmahir(mymlx->player.player_x + 1 , mymlx->player.player_y, mymlx->sand, mymlx);
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->sand, mymlx);
            rassam_lmahir(mymlx->player.player_x + 1, mymlx->player.player_y, mymlx->joseph, mymlx);
            exit_deleter(mymlx->player.player_x, mymlx->player.player_y, mymlx);
            mymlx->player.player_x++;   
        }
    }
    else if (keycode == 0) // A key
    {   
        coin_counter(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited, mymlx);
        if (mymlx->map.splited[mymlx->player.player_x][mymlx->player.player_y - 1] != '1')
        {     
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y-1, mymlx->sand, mymlx); // next place sand
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->sand, mymlx); //sand 
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y-1, mymlx->joseph, mymlx); //joseph nxt place
            exit_deleter(mymlx->player.player_x, mymlx->player.player_y, mymlx);//exit deleter 
            mymlx->player.player_y--;
        }
    }
    else if (keycode == 2) // D key
    {
        coin_counter(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited, mymlx);
        if (mymlx->map.splited[mymlx->player.player_x][mymlx->player.player_y + 1] != '1')
        {
           rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y +1, mymlx->sand, mymlx); //sand
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->sand, mymlx);   // joseph
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y +1, mymlx->joseph, mymlx); // sand
            exit_deleter(mymlx->player.player_x, mymlx->player.player_y,   mymlx); //exit deleter
             mymlx->player.player_y++;
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