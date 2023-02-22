
#include "solong.h"
t_mymap mymap;
int counter = 0;
void errorcases(int error, char **splited, int num_rows, int num_col)
{
    int i = 0;
    int j = 0;
    while (i < num_rows)
    {
        while (j < num_col)
        {
            if ((splited[i][j] != '1') || (splited[i][j] != '0') || (splited[i][j] != 'E') || (splited[i][j] != 'C') || (splited[i][j] != 'P'))
                {
                    
                }
        }
    }
}
void checkdupPE(int num_col, int num_rows, char **splited, int error_count)
{
    int i = 0;
    int j = 0;
    int p_found = 0;
    int e_found = 0;
    while (i < num_rows)
    {
        j = 0;
        while (j < num_col)
        {
            if ((splited[i][j] == 'P') || (splited[i][j] == 'E'))
            {
                p_found++;
                e_found++;
                if (e_found + p_found > 2)
                {

                    errortextprint(2);
                    error_count++;
                    break;
                }
            }
            j++;
        }
        i++;
    }
}
void checkasccimap(char **splited, int i, int j, int num_rows, int num_col)
{
    while (i < num_rows)
    {
        j = 0;
        while (j < num_col)
        {
            while (splited[i][j] != '\0')
            {
                if (ft_isascii(splited[i][j]) == 0)
                {
                    errortextprint(3);
                    break;
                }
            }
            j++;
        }
        i++;
    }
}
void errortextprint(int error)
{
    if (error == 1)
        printf("missing arguments in the map");
    if (error == 2)
        printf("duplicated P or E");
    if (error == 3)
        printf("map is not ascii");
    if (error == 4)
        printf("map is not majuscule");
}
