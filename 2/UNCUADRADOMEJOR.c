#include <unistd.h>
#define SIZE 4
void ft_putchar(char c)
{
    write(1, &c, 1);
}
void draw_matriz(void)
{
    int matriz[SIZE][SIZE];
    int f[SIZE][2];
    int c[SIZE][2];
    int fd = 0;
    int cd = 0;
    while (cd < SIZE)
    {
        fd = 0;
        while (fd < SIZE)
        {
            ft_putchar(cd + '0');
            ft_putchar(fd + '0');
            ft_putchar(' ');
            fd++;
        }
        ft_putchar('\n');
        cd++;
    }
}

void main(void)
{
    draw_matriz();
}