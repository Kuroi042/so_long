#ifndef SOLONG_H

#define SOLONG_H
#include <mlx.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"

typedef struct s_player
{
    int player_x;
    int player_y;
    int path_x;
    int path_y;
} t_player;
typedef struct s_mymap
{
    int r;
    int c;
    int map_line_counter;
    int num_rows;
    int num_col;
    int errorI;
    int check_tool;
    int check_tool_teht;
    int check_jnab_1;
    int check_jnab_2;
    char *map1;
    char *map_str; // map_str ghadi doz f get_next_line
    size_t len_map;
    int counter;
    int e_found;
    int p_found;
    char **splited;
    char **maptester;
} t_mymap;

typedef struct s_mymlx
{
    void *mlx;
    void *mlx_win;
    void *wall;
    void *joseph;
    void *sand;
    void *coin;
    void *exit;
    void *enter;
    int coin_yes;
    int exit_x;
    int exit_y;
    int coincounter;
    int path_coin;
    int coins_collected;
    int num_coins;
    int i;
    int j;
    int m;
    int n;
    int exitfound;
    t_mymap map;
    t_player player;
 
} t_mymlx;

void permetre(t_mymlx *mymlx);
void errortext(int error);
void checkdupPE(int num_col, int num_rows, char **splited);
void openber(int fd);
void errortextprint(int error);
void berber(char *str);
void imposter(char **splited, int num_rows, int num_col);
void projec(int x, int y, t_mymlx *mymlx);
void drawingxpm(int i, int j, char **splited, t_mymlx *mymlx);
int key_press(int keycode, t_mymlx *mymlx);
void rassam_lmahir(int i, int j, void *image, t_mymlx *mymlx);
void printexit(t_mymlx *mymlx);
void coin_counter(int i, int j, char **splited, t_mymlx *mymlx);
void line_counter(t_mymlx *mymlx);
void is_valid_move(char **map,t_mymlx *mymlx);
void player_position(char **splited, int path_x, int path_y, t_mymlx *mymlx);
void coin_checker(t_mymlx *mymlx);
void diffcoin(t_mymlx *mymlx);
void  checker(t_mymlx *mymlx); //chhal 3ndi mn coin 9bl manfloodi 
void findexit(char **splited, t_mymlx *mymlx);
#endif