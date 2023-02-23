#include "solong.h"
t_mymap mymap;
void permetre(int num_rows, int num_col, char **splited)
{
    mymap.check_jnab_1 = 0;
    mymap.check_jnab_2 = 0;
    mymap.c = 0;
    mymap.r = 0;
    while (mymap.c < num_col)
    {
        if (splited[mymap.r][mymap.c] != '1')
        {
            mymap.check_tool = -1;
        }
        if (splited[num_rows - 1][mymap.c] != '1')
        {
            mymap.check_tool_teht = -1;
        }
        mymap.c++;
    }
    while (mymap.r < num_rows)
    {
        if (splited[mymap.r][0] != '1')
        {
            mymap.check_jnab_1 = -1;
        }
        if (splited[mymap.r][num_col - 1] != '1')
        {
            mymap.check_jnab_2 = -1;
        }
        mymap.r++;
    }
    if (mymap.check_jnab_1 != 0 || mymap.check_jnab_2 != 0 || mymap.check_tool != 0 || mymap.check_tool_teht != 0)
    {
        printf("The perimetre is not set\n");
    }
}
