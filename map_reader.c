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

    int i = 0;
    int j = 0;
    int x = 0;
    int y = 0;
    ptr->wall = mlx_xpm_file_to_image(ptr->mlx, "waall.xpm", &x, &y);
    ptr->sand = mlx_xpm_file_to_image(ptr->mlx, "sand.xpm", &x, &y);
    ptr->joseph = mlx_xpm_file_to_image(ptr->mlx, "jooseph.xpm", &x, &y);
    ptr->coin = mlx_xpm_file_to_image(ptr->mlx, "bassit.xpm", &x, &y);
    ptr->exit = mlx_xpm_file_to_image(ptr->mlx, "portal.xpm", &x, &y);

    while (i < mymap.num_rows)
    {

      j = 0;
      while (j < mymap.num_col)
      {
        // printf("|%c|", mymap.splited[i][j]);
        if (mymap.splited[i][j] == '1')
          mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->wall, j * 50, i * 50);
        if (mymap.splited[i][j] == '0')
          mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->sand, j * 50, i * 50);
        if (mymap.splited[i][j] == 'P')
          mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->joseph, j * 50, i * 50);
        if (mymap.splited[i][j] == 'C')
          mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->coin, j * 50, i * 50);
        if (mymap.splited[i][j] == 'E'){
          mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->exit, j * 50, i * 50);
           if (ptr->exit == NULL) {
                    write(1, "Error: failed to load image\n", 29);
                    exit(EXIT_FAILURE);
                }
        }
        j++;
      }
      i++;
    }
    mlx_loop(ptr->mlx);
  }
}

//  int i = 0;
//     int j = 0;
//     while (i < mymap.num_rows) {
//         j = 0;
//         while (j < mymap.num_col) {
//             if (mymap.splited[i][j] == '1') {
//                 ptr->wall = mlx_xpm_file_to_image(ptr->mlx, "waall.xpm", &j ,&i);
//                 printf("i = |%d| , j = |%d|\n",i,j);
//                 if (ptr->wall == NULL) {
//                     write(1, "Error: failed to load image\n", 29);
//                     exit(EXIT_FAILURE);
//                 }
//                 mlx_put_image_to_window(ptr->mlx, ptr->mlx_win, ptr->wall, j , i );
//             }
//             j++;
//         }
//         i++;
//     }

//     mlx_loop(ptr->mlx);
// }
