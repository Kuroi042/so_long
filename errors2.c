#include "solong.h"

void berberber(char *str) {
    char *s = ft_calloc(4, sizeof(char));
    if(!s) { 
        printf("NULL");
    }
    ft_strlcpy(s, ".ber",5);
    printf("%s",s);
    size_t len = ft_strlen(s);
   if(ft_strnstr(((str, s, len), s, len) != 0 ))
   {
printf("dfds");
   }

 
 
}

int main() {
    char str[] = ".sder";
    berberber(str);
    return 0;
}