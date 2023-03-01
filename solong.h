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
void imposter( char **splited, int num_rows, int num_col);
void mapdrwing(int nr, int nc , char **splited, void *mlx , void *mlx_win);



    typedef struct s_mymap
{
    int r;
    int c;
    int num_rows;
    int num_col;
    int errorI;    // missing arguments in the map/
    //int errorII;   // all argument are found but without dup check
    //int errorIII;  // player or exit is duplicated
    //int errorIIII; // majuscule map;
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
// struct

typedef struct s_mymlx
{
    void 	*wall;
	void	*joseph;
	void	*sand;
	void 	*coin;
	void	*exit;
    int     *tool;
    int     *ard;
}  t_mymlx;

#endif