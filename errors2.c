
#include "solong.h"

 
void  berber(char *str) {
      if(!ft_strnstr(str,".ber",ft_strlen(str))){
      printf(".ber is not found\n");
      exit(0);
    }
    }
 

void line_counter(t_mymlx *mymlx){
if(mymlx->map.map_line_counter != mymlx->map.num_rows ){
    printf("map.ber lines are not correct ! \n");
    exit(0);
}
  }
void checkforPE(t_mymlx *mymlx){
  int i =0;
  int j =0;
  int found = 0;
  int cfound =0;
   while(i <mymlx->map.num_rows){
    j =0;
    while(j <mymlx->map.num_col){
        if(mymlx->map.splited[i][j ]== 'P' && mymlx->map.splited[i][j ]== 'E'){
        printf("found == %d\n", found);
              found++;
        }
        if( mymlx->map.splited[i][j ]== 'C')
          cfound++;
  j++;
    } 
    i++;
   }
   if(found != 2 && cfound < mymlx->num_coins){}{ 
      printf("error P || E || C check map %d\n  c == %d < num coin %d", found, cfound,mymlx->num_coins);
      exit(0);
}
}


 

 
void allerror(t_mymlx *mymlx){
  inputter(mymlx);
    permetre(mymlx);
    check_num_col( mymlx);
    line_counter(mymlx);
    imposter(mymlx->map.splited, mymlx->map.num_rows, mymlx->map.num_col);
    checkdupPE(mymlx->map.num_col, mymlx->map.num_rows, mymlx->map.splited);
    checker(mymlx);
    mlx(mymlx);
}

void inputter(t_mymlx *mymlx){
int j;
int k;
j = 0;
k = 0;


  while (k < mymlx->map.num_rows)
    {
      while (j < mymlx->map.num_col)
      {
        if (mymlx->map.splited[k][j]== 'E')
          mymlx->exitdiali++;
        if (mymlx->map.splited[k][j]== 'P')
          mymlx->playerdiali++;
        if (mymlx->map.splited[k][j]== 'C')
          mymlx->colldiali++;

        j++;
      }
      j=0;
      k++;
    }
    if (mymlx->colldiali == 0 || mymlx->playerdiali != 1 || mymlx->exitdiali !=1 ){
      printf("ahuuu \n");
      exit(0);
    }
}