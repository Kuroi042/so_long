#ifndef SOLONG_H

#define SOLONG_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include "libft/libft.h"
#include <mlx.h>

void permetre(int num_rows, int num_col, char **splited);
void errortext(int error);
void permetre(int num_rows, int num_col, char **splited);
void checkdupPE(int num_col, int num_rows, char **splited, int error_count);
void errortextprint(int error);
void checkasccimap(char **splited, int i, int j, int num_rows, int num_col);
void berberber(char *str);
//void errorcases(int error, char **splited , int num_rows, int num_col);

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

#endif