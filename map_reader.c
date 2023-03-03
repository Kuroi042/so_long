#include "solong.h"
t_mymap mymap;
t_mymlx mymlx;
void errortextprint(int error)
{
  if (error == 1)
    printf("missing arguments in the map\n");
  if (error == 2)
    printf("duplicated P / E\n");
  if (error == 3)
    printf("map is not ascii\n");
  if (error == 4)
    printf("map is not majuscule\n");
}

int main(int argc, char *argv[])
{
  char *map1;
  char *map_str; // map_str ghadi doz f get_next_line
  if (argc == 2)
  {
    int fd = open(argv[1], O_RDONLY);
    // openber(fd);
    map_str = get_next_line(fd);
    size_t len = ft_strlen(map_str);
    map1 = ft_calloc(len, 1);
    while (map_str)
    {
      map1 = ft_strjoinget(map1, map_str);

      map_str = get_next_line(fd);
    }
    mymap.splited = ft_split(map1, '\n');
    free(map1);
    mymap.num_col = ft_strlen(mymap.splited[0]);  // num colum                    //num_rows
    while (mymap.splited[mymap.num_rows] != NULL) // num coll
    {                                             // splited[0] ...[NULL]
      mymap.num_rows++;                           // rows = 0 inrements to 1234
    }

    permetre(mymap.num_rows, mymap.num_col, mymap.splited);
    imposter(mymap.splited, mymap.num_rows, mymap.num_col);
    checkdupPE(mymap.num_col, mymap.num_rows, mymap.splited);

    t_mymlx *ptr = &mymlx;

    ptr->mlx = mlx_init();
    ptr->mlx_win = mlx_new_window(ptr->mlx, mymap.num_col * 32, mymap.num_rows * 32, "moghmarat jojo");

    int x = 0;
    int y = 0;
    projec(x, y);
    drawingxpm(mymap.num_rows, mymap.num_col, mymap.splited);
    mlx_loop(ptr->mlx);
  }
}
