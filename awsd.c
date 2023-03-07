#include "solong.h"

int key_press(int keycode, t_mymlx *mymlx)
{
    if (keycode == 13) // W key
    {
         
        coin_counter(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited, mymlx);
        // exit_point(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited);
        if (mymlx->map.splited[mymlx->player.player_x - 1][mymlx->player.player_y] != '1')
        {
               
            mymlx->player.player_x--;
            rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->joseph, mymlx);
            rassam_lmahir(mymlx->player.player_x + 1, mymlx->player.player_y, mymlx->sand, mymlx);
        }
      
    }

    if (keycode == 1) // S key
    { 
        
        coin_counter(mymlx->player.player_x, mymlx->player.player_y ,mymlx->map.splited, mymlx);
        // exit_point(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited);
        if (mymlx->map.splited[mymlx->player.player_x + 1][mymlx->player.player_y] != '1')
        { 

                mymlx->player.player_x++;
             
                rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->joseph, mymlx);
      
                rassam_lmahir(mymlx->player.player_x - 1, mymlx->player.player_y, mymlx->sand, mymlx);
   
        }
    }
    if (keycode == 0) // A key
    {
         
        coin_counter(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited, mymlx);
        // exit_point(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited);
        if (mymlx->map.splited[mymlx->player.player_x][mymlx->player.player_y - 1] != '1')
        {

          
                mymlx->player.player_y--;
                
                rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->joseph, mymlx);
                rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y + 1, mymlx->sand, mymlx);
          
        }
      
    }
        if (keycode == 2) // D key
        {
            
            coin_counter(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited, mymlx);
            //    exit_point(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited);
            if (mymlx->map.splited[mymlx->player.player_x][mymlx->player.player_y + 1] != '1')
            {
                  
                mymlx->player.player_y++;

                
                laporte(mymlx->player.player_x, mymlx->player.player_y, mymlx->map.splited, mymlx);
                rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->joseph, mymlx);   // joseph
                rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y - 1, mymlx->sand, mymlx); // sand
              
            }
            
           
        }
        return 0;
    }

    void coin_counter(int i, int j, char **splited, t_mymlx *mymlx)
    {
        if (splited[i][j] == 'C')
        {
            mymlx->coincounter += 1;
            splited[i][j] = '0';
        }
        if (mymlx->num_coins == mymlx->coincounter)
            mlx_string_put(mymlx->mlx, mymlx->mlx_win, 12, 10, 0xffffff, "all coins are collected ! Exit now ");
        
    }



    void laporte(int i, int j, char **splited, t_mymlx *mymlx){

             
            if(mymlx->coincounter != mymlx->num_coins && splited[i][j] == 'E')
                rassam_lmahir(mymlx->player.player_x, mymlx->player.player_y, mymlx->exit, mymlx);               


    }
