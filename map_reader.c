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
    mymlx->map.map1 = (char *)malloc(1 * sizeof(char));
    while (1)
    {
      mymlx->map.map_str = get_next_line(fd);
      if (mymlx->map.map_str == NULL)
        break;
      mymlx->map.map1 = ft_strjoinget(mymlx->map.map1, mymlx->map.map_str);
      mymlx->map.map_line_counter++;
    }
    mymlx->map.num_rows = 0;
    mymlx->map.maptester = ft_split(mymlx->map.map1, '\n');
    mymlx->map.splited = ft_split(mymlx->map.map1, '\n');
    mymlx->map.num_col = ft_strlen(mymlx->map.splited[0]); // num colum                    //num_rows
    while (mymlx->map.splited[mymlx->map.num_rows] != NULL)
    {
      mymlx->map.num_rows++;
    }
   
    mymlx->map.num_col = ft_strlen(mymlx->map.splited[0]);
    // berber(argv[1]);
    line_counter(mymlx);
    permetre(mymlx);
    imposter(mymlx->map.splited, mymlx->map.num_rows, mymlx->map.num_col);
    checkdupPE(mymlx->map.num_col, mymlx->map.num_rows, mymlx->map.splited);
    checker(mymlx);
     int i = 0;
      while (i<mymlx->map.num_rows){
     printf("%s\n", mymlx->map.maptester[i]);
     i++;
      }
    mymlx->mlx = mlx_init();
    mymlx->mlx_win = mlx_new_window(mymlx->mlx, mymlx->map.num_col * 32, mymlx->map.num_rows * 32, "3ayn dahrek");
    projec(mymlx->m, mymlx->n, mymlx);
    drawingxpm(mymlx->i, mymlx->j, mymlx->map.splited, mymlx);
    mlx_key_hook(mymlx->mlx_win, key_press, mymlx);
    mlx_loop(mymlx->mlx);
  }
}