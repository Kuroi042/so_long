#include "solong.h"
t_mymlx mymlx;

void exit_point(int i , int j ,char **splited){
if(splited[i][j] == 'E')
{
  mlx_destroy_window(mymlx.mlx,mymlx.mlx_win);
}



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
    mymlx.map = malloc(sizeof(t_mymap));
    mymlx.player = malloc(sizeof(t_player));

    mymlx.map->splited = ft_split(map1, '\n');
    free(map1);
    mymlx.map->num_col = ft_strlen(mymlx.map->splited[0]);  // num colum                    //num_rows
    while (mymlx.map->splited[mymlx.map->num_rows] != NULL) // num coll
    {                                                       // splited[0] ...[NULL]
      mymlx.map->num_rows++;                                // rows = 0 inrements to 1234
    }
    permetre(mymlx.map->num_rows, mymlx.map->num_col, mymlx.map->splited);
    imposter(mymlx.map->splited, mymlx.map->num_rows, mymlx.map->num_col);
    checkdupPE(mymlx.map->num_col, mymlx.map->num_rows, mymlx.map->splited);

    mymlx.mlx = mlx_init();
    mymlx.mlx_win = mlx_new_window(mymlx.mlx, mymlx.map->num_col * 32, mymlx.map->num_rows * 32, "moghmarat jojo l3jibaaa");
    int i = 0;
    int j = 0;

    int x = 0;
    int y = 0;

    projec(x, y);
    drawingxpm(i, j, mymlx.map->splited);
    mlx_key_hook(mymlx.mlx_win, key_press, NULL);

    mlx_loop(mymlx.mlx);
    //     free(mymlx.map->splited);
    //   free(mymlx.map );
    //   free(map1);
    // free(mymlx.player);
  }
}