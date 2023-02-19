#include "solong.h"


int main(int argc , char *argv[])
{   
  // int i = 0;
char **splited;
  char *map1;
  
  char *map_str; // map_str ghadi doz f get_next_line
  //char **map; //ghadi doz mn split wtkherej lina stora

  // int i = 0;
  // int j = 0;
if(argc == 2)
{
int fd = open(argv[1],O_RDONLY);
map_str = get_next_line(fd);
size_t len = ft_strlen(map_str);
map1 = ft_calloc(len , 1);
while(map_str)
{
  map1 = ft_strjoin(map1,map_str);
map_str = get_next_line(fd);

//printf("%s",map_str);

 


}
splited =  ft_split(map1,'\n');

printf("%s", splited[0]);

}

}