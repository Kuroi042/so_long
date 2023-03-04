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

void permetre(int num_rows, int num_col, char **splited);
void errortext(int error);
void permetre(int num_rows, int num_col, char **splited);
void checkdupPE(int num_col, int num_rows, char **splited);
void openber(int fd);
void errortextprint(int error);
// void berber(char *str);
void imposter(char **splited, int num_rows, int num_col);
void mapdrwing(int nr, int nc, char **splited, void *mlx, void *mlx_win);
void projec(int x , int y);
void drawingxpm(int i, int j, char **splited);
int handle_input(int keycode);
int key_press(int keycode, void *param);
void  findposi(int i, int j, char **splited);

typedef struct s_player
{
    int player_x;
    int player_y;
} t_player;
typedef struct s_mymap
{
    int r;
    int c;
    int num_rows;
    int num_col;
    int errorI;
    int check_tool;
    int check_tool_teht;
    int check_jnab_1;
    int check_jnab_2;
    size_t len_map;
    int counter;
    int e_found;
    int p_found;
    char **splited;

} t_mymap;
 


typedef struct s_mymlx
{
    void *mlx;
    //void *win;
    void *mlx_win;
    void *wall;
    void *joseph;
    void *sand;
    void *coin;
    void *exit;
    t_mymap *map;
    t_player *player;

} t_mymlx;


 

 


#endif