#include "solong.h"
#include <stdbool.h>

t_mymap mymap;
// bool printed_message = false;
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
  mymap.errorI = 0;
  if (argc == 2)
  {
    int fd = open(argv[1], O_RDONLY);
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
   checkasccimap(mymap.splited,  mymap.num_rows, mymap.num_col);
  imposter( mymap.splited,  mymap.num_rows, mymap.num_col);
   checkdupPE( mymap.num_col,  mymap.num_rows, mymap.splited);

  }
}

