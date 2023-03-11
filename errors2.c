
#include "solong.h"

// void berber(char *str)
// {
//     size_t  i = 0;
//     char *result = ft_strnstr(str, ".ber", ft_strlen(str));
//     while( i < ft_strlen(str))
//     {
//         if(str[i] == ' '){
  
//             write(1,"argv is wrong\n",15);
//             exit(1);
          
//     }
//        i++;
//     }
//     if (result == NULL)
//     {
//         printf("String does not contain \".ber\"\n");
//     }
//         if (ft_strncmp(result, ".ber", 4) == 0)
//         {
//             printf("String contains \".ber\"\n");
//         }
//     }
void line_counter(t_mymlx *mymlx){
  if( mymlx->map.map_line_counter != mymlx->map.num_rows)
  {
    printf("errors in map lines\n");
    exit(0);
  }
}