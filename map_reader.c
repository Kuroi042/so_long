#include "solong.h"

int main(int argc, char *argv[])
{
 
  t_mymlx *mymlx;
  mymlx = (t_mymlx*)malloc(sizeof(t_mymap));
  char *map1;
  char *map_str; // map_str ghadi doz f get_next_line
  if (argc == 2)
  {
    int fd = open(argv[1], O_RDONLY);
    // openber(fd);
    map_str = get_next_line(fd);
  // map1 =  (char*)malloc(1);
    map1 =  (char*)malloc(1 * sizeof(char));
  map1[0] = '\0';
    while (map_str)
    {
      map1 = ft_strjoinget(map1, map_str);
      map_str = get_next_line(fd);
      mymlx->map.num_rows++;                              // rows = 0 inrements to 1234
    }

    mymlx->map.splited = ft_split(map1,'\n');
    mymlx->map.num_col = ft_strlen(mymlx->map.splited[0]);  // num colum                    //num_rows
  //       int i =0;
  //   while (i<mymlx->map.num_rows){
  //  printf("%s\n", mymlx->map.splited[i]);
  //  i++;
  //   }
    permetre(mymlx);
   imposter(mymlx->map.splited, mymlx->map.num_rows, mymlx->map.num_col);
  checkdupPE(mymlx->map.num_col, mymlx->map.num_rows, mymlx->map.splited);

    mymlx->mlx = mlx_init();
    mymlx->mlx_win = mlx_new_window(mymlx->mlx, mymlx->map.num_col * 32, mymlx->map.num_rows * 32, "moghmarat jojo l3jibaaa");
    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    projec(x, y,mymlx);
    drawingxpm(i, j, mymlx->map.splited, mymlx);
    mlx_key_hook(mymlx->mlx_win, key_press, mymlx);
    mlx_loop(mymlx->mlx);
  }
}