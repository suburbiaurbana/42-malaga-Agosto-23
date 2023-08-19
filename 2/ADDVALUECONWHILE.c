#include <unistd.h>
void ft_putchar(char c)
{
    write(1, &c, 1);
}
void lector_arg(char *str, int col[4][2], int row[4][2])
{
    int n = 0;
    int i = 0;
    int j = 0;

    while (n < 16)
    {
        if (i == 4)
        {
            i = 0;
            j++;
        }
        if (str[n] > '0' && str[n] < '5')
        {
            if (j < 2)
                col[i][j] = str[n] - '0';
            else
                row[i][j-2] = str[n] - '0';
        }
        n++;
        i++;
    }
}
int main(int argc, char *argv[])
{
    char str[] = "1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4";
}