#include "solong.h"

 
 void permetre(t_mymlx *mymlx){
    while(mymlx->map.r<mymlx->map.num_rows){ 
                    while(mymlx->map.c<mymlx->map.num_col){ //check for ster up and down
           if (mymlx->map.splited[0][mymlx->map.c] != '1')
                mymlx->map.check_tool_up = -1;
                 if(mymlx->map.splited[mymlx->map.num_rows-1][mymlx->map.c] != '1')
                mymlx->map.check_tool_teht = -1;
                    mymlx->map.c++;
        }
            if(mymlx->map.splited[mymlx->map.r][0]!= '1')
                 mymlx->map.check_side_left = -1;
                   if (mymlx->map.splited[mymlx->map.r][mymlx->map.num_col-1] != '1')
            mymlx->map.check_side_right = -1;            
        mymlx->map.r++;
            }
                 if (mymlx->map.check_tool_up != 0 ||  mymlx->map.check_tool_teht != 0 ||  mymlx->map.check_side_left != 0 ||mymlx->map.check_side_right != 0)
    {
       printf("error The perimetre is not set\n");
        exit(0);
}
          }
void check_num_col(t_mymlx *mymlx){
int i =0;
while(i < mymlx->map.num_rows){


   if( mymlx->map.num_col != len(mymlx->map.splited[i])){
        printf("error check perimetre !! \n");
        exit(0);
   }
    
        i++;
}

}
int len(char *str){
    int i =0;
 
    while(str[i])
    {
        i++;
    }
    return i ;
}
  



