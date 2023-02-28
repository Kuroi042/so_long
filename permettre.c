#include "solong.h"
void permetre(int num_rows, int num_col, char **splited)
{
    int check_jnab_1 = 0;
    int check_jnab_2 = 0;
    int check_tool= 0;
    int check_tool_teht = 0;
    int c = 0;
    int r = 0;
    while (c < num_col)
    {
        if (splited[r][c] != '1')
        {
            check_tool = -1;
        }
        if (splited[num_rows - 1][c] != '1')
        {
            check_tool_teht = -1;
        }
        c++;
    }
    while (r < num_rows)
    {
        if (splited[r][0] != '1')
        {
            check_jnab_1 = -1;
        }
        if (splited[r][num_col - 1] != '1')
        {
            check_jnab_2 = -1;
        }
        r++;
    }
    if (check_jnab_1 != 0 || check_jnab_2 != 0 || check_tool != 0 || check_tool_teht != 0)
    {
        printf("The perimetre is not set\n");
    }
}
