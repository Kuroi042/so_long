#include "solong.h"
void permetre(t_mymlx *mymlx)
{
    int check_jnab_1 = 0;
    int check_jnab_2 = 0;
    int check_tool= 0;
    int check_tool_teht = 0;
    int c = 0;
    int r = 0;
  while (c < mymlx->map.num_col)
    {
        
        if (mymlx->map.splited[0][c] != '1')
                check_tool = -1;
            c++;
    }
    while (c < mymlx->map.num_col){
        if(mymlx->map.splited[mymlx->map.num_rows][c] != '1')
                check_tool_teht = -1;
        c++;
    }
    while (r <  mymlx->map.num_rows){ 
  
      
          if(mymlx->map.splited[r][0]!= '1')

                check_jnab_1 = -1;
        r++;
}
  while (r <  mymlx->map.num_rows){
        if (mymlx->map.splited[r][mymlx->map.num_col] != '1')
        {
            check_tool_teht = -1;
           
        }
        r++;
    }
    if (check_jnab_1 != 0 || check_jnab_2 != 0 || check_tool != 0 || check_tool_teht != 0)
    {
        printf("The perimetre is not set\n");
      
}
}
 
