#include <stdio.h>
char b[4][8] = {{0}, {10, 0}, {32, 32, 32, 32, 34, 37, 115, 0}, {37, 115, 34, 44, 10, 0}};
char s[13][95] = {
    "%s#include <stdio.h>%s",
    "%schar b[4][8] = {{0}, {10, 0}, {32, 32, 32, 32, 34, 37, 115, 0}, {37, 115, 34, 44, 10, 0}};%s",
    "%schar s[13][95] = {%s",
    "%s};%s",
    "%sint main(){%s",
    "%s    for (int i = 0; i <= 2; ++i)%s",
    "%s        printf(s[i], b[0], b[1]);%s",
    "%s    for (int i = 0; i <= 12; ++i)%s",
    "%s        printf(s[i], b[2], b[3]);%s",
    "%s    for (int i = 3; i <= 12; ++i)%s",
    "%s        printf(s[i], b[0], b[1]);%s",
    "%s    return 0;%s",
    "%s}%s",
};
int main(){
    for (int i = 0; i <= 2; ++i)
        printf(s[i], b[0], b[1]);
    for (int i = 0; i <= 12; ++i)
        printf(s[i], b[2], b[3]);
    for (int i = 3; i <= 12; ++i)
        printf(s[i], b[0], b[1]);
    return 0;
}
