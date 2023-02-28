
#include "solong.h"
void imposter( char **splited, int   num_rows,int   num_col)
{
    int i = 0;
    int  j = 0;

while (i < num_rows) {
  j = 0;

  while (j < num_col) {
    if ((splited[i][j] != '1') && (splited[i][j] != '0') && (splited[i][j] != 'E') && (splited[i][j] != 'C') && (splited[i][j] != 'P')) {
        printf("character|%c| is imposter \n", splited[i][j]);
           break;
    }

      j++;
  }
i++;
}
}
void checkdupPE(int num_col, int num_rows, char **splited)
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
                if (e_found + p_found > 4)
                {
                    printf("duplicated P | E \n");
                       exit(0);
                }
            }
            j++;
        }
        i++;
    }
}
void openber(int fd)
{

  if(fd == -1){
    printf("open error");
    exit(1);
  }
}

