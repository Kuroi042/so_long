#include "solong.h"
// count the coin after and befor flood
void coincounter(char **splited, t_mymlx *mymlx)
{
    int i = 0;
    while (i < mymlx->map.num_rows)
    {
        int j = 0;
        while (j < mymlx->map.num_col)
        {
            if (splited[i][j] == 'C')
                mymlx->path_coin++;
            j++;
        }
        i++;
    }
}
// find the exit after the flood
void findexit(char **splited, t_mymlx *mymlx)
{
    int i = 0;
    while (i < mymlx->map.num_rows)
    {
        int j = 0;
        while (j < mymlx->map.num_col)
        {
            if (splited[i][j] == 'E')
                mymlx->exitfound = -1;
            j++;
        }
        i++;
    }
}
// itiration in the map using if
void player_position(char **splited, int path_x, int path_y, t_mymlx *mymlx)
{
    while (path_x < mymlx->map.num_rows && path_x >= 0)
    {
        path_y = 0;
        while (path_y < mymlx->map.num_col && path_y >= 0)
        {
            if (splited[path_x][path_y] == 'P')
            {
                if ((path_x >= 0 && splited[path_x - 1][path_y] == '0') || splited[path_x - 1][path_y] == 'C' || splited[path_x - 1][path_y] == 'E')
                    splited[path_x - 1][path_y] = 'P';
                if ((path_x < mymlx->map.num_rows - 1 && splited[path_x + 1][path_y] == '0') || splited[path_x + 1][path_y] == 'C' || splited[path_x + 1][path_y] == 'E')
                    splited[path_x + 1][path_y] = 'P';
                if ((path_y >= 0 && splited[path_x][path_y - 1] == '0') || splited[path_x][path_y - 1] == 'C' || splited[path_x][path_y - 1] == 'C' || splited[path_x][path_y - 1] == 'E')
                    splited[path_x][path_y - 1] = 'P';
                if ((path_y < mymlx->map.num_col - 1 && splited[path_x][path_y + 1] == '0') || splited[path_x][path_y + 1] == 'C' || splited[path_x][path_y + 1] == 'E')
                    splited[path_x][path_y + 1] = 'P';
            }
            path_y++;
        }
        path_x++;
    }
}
// checker for Coin and exitafter and before flood
void checker(t_mymlx *mymlx)
{
    coincounter(mymlx->map.maptester, mymlx);
    int k = mymlx->path_coin; // before flood
    int g = 0;
    while (g != mymlx->map.num_col)
    {
        player_position(mymlx->map.maptester, mymlx->m, mymlx->n, mymlx);
        g++;
    }
    coincounter(mymlx->map.maptester, mymlx);
    int m = mymlx->path_coin; // after flood
    if (k != m)
    {
        printf("map is invalid\n");
        exit(0);
    }
    findexit(mymlx->map.maptester, mymlx);
    if (mymlx->exitfound == -1)
    {
        printf("map is invalid\n");
        exit(0);
    }
}
