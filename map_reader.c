#include "solong.h"

int main(int argc, char *argv[])
{
  t_mymlx *mymlx;
  mymlx = (t_mymlx *)malloc(sizeof(t_mymlx));
  ft_memset(mymlx, 0, sizeof(t_mymlx));
  mymlx->map.map_str = malloc(1);
  if (!mymlx->map.map_str)
    return (0);
  if (argc == 2)
  {
    int fd = open(argv[1], O_RDONLY);
    openber(fd);
    berber(argv[1]);
    mymlx->map.map1 = (char *)malloc(1 * sizeof(char));
    // if(get_next_line(fd) == NULL){
    //   printf("void map\n");
    //   exit(0);
    // }
      mymlx->map.map_str = get_next_line(fd);
        if(!mymlx->map.map_str){
                printf("uhaa \n");
      exit(0);
        }
    while (1)
    {
      mymlx->map.map1 = ft_strjoinget(mymlx->map.map1, mymlx->map.map_str);
      mymlx->map.map_line_counter++;
      mymlx->map.map_str = get_next_line(fd);
      if (mymlx->map.map_str == NULL){
        break;
      }
    }
    // printf("|%d|\n",mymlx->map.map_line_counter);
    mymlx->map.maptester = ft_split(mymlx->map.map1, '\n');
    mymlx->map.splited = ft_split(mymlx->map.map1, '\n');
      while (mymlx->map.splited[mymlx->map.num_rows] != NULL)
    {
      mymlx->map.num_rows++;
    }
    // printf("wakha %d\n",mymlx->map.num_rows);
    mymlx->map.num_col = ft_strlen(mymlx->map.splited[0]);
    
    allerror(mymlx);
   
  }
  printf("hhh %s ??\n",argv[0]);
  exit(0);
}