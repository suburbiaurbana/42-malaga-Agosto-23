#include <unistd.h>

void putchar(char c){
    write(1, &c, 1);
}
void ft_2d(int f, int c){
    int matriz[f][c];

    int fd = 0;
    int cd = 0;

    while (cd < c){
        fd = 0;
        while (fd < f){
            putchar(cd + '0');
            putchar(fd + '0');
            putchar(' ');

            fd++;
        }
        putchar('\n');
        cd++;
    }
}

void main(){
    ft_2d(5,5);

}