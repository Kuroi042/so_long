
#include "solong.h"
t_mymap mymap;
int counter = 0;
// void errorcases(int error, char **splited , int num_rows, int num_col)
// {
//     int i = 0;
//     int j = 0;
//     while (i <  num_rows)
//     {
//         while (j <  num_col)
//         {
//             if ((splited[i][j] != '1') || (splited[i][j] != '0') || (splited[i][j] != 'E') || (splited[i][j] != 'C') || (splited[i][j] != 'P'))
//                 error = 1; // missing arguments in the map;
//             errortextprint(1);
//             if ((splited[i][j] == 'P') || (splited[i][j] == 'E'))
//             {
//                 counter++;
//                 if (counter == 2)
//                     error = 1; // duplicated P or E
//                 errortextprint(2);
//             }
//             if (ft_isascii(splited[i][j] == 0))
//                 error = 3; // map is not ascii
//             errortextprint(3);
//             if (ft_isalpha(splited[i][j] == 1))
//                 error = 4; // map is not majuscule
//             errortextprint(4);
//             j++;
//         }
//     }
// }
void errortextprint(int error , char **splited)
{
    if (error == 1)
        printf("missing arguments in the map");
    if (error == 2)
        printf("duplicated P or E");
    if (error == 3)
        printf("map is not ascii");
    if (error == 4)
        printf("map is not majuscule");
        if(error == 5)
        printf("impooooster");        
}
