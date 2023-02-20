#include "solong.h"

t_mymap mymap;



int main(int argc, char *argv[])
{

  char *map1;
  char *map_str; // map_str ghadi doz f get_next_line
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
   mymap.errorI = -1;
    // errorcases(mymap.errorI,mymap.splited);
    // errorcases(mymap.errorI,mymap.splited);
    // errorcases(mymap.errorI,mymap.splited);
    // errorcases(mymap.errorI,mymap.splited);
   


  }
}
