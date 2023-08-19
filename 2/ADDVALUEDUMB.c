#include <unistd.h>
#define UP 0
#define DW 1
#define LF 0
#define RG 1

void ft_putchar(char c)
{
    write(1, &c, 1);
}
void lector_arg(char *str, int col[2][4], int row[2][4])
{
    col[UP][0] = str[0];
    col[UP][1] = str[2];
    col[UP][2] = str[4];
    col[UP][3] = str[6];
    col[DW][0] = str[8];
    col[DW][1] = str[10];
    col[DW][2] = str[12];
    col[DW][3] = str[14];
    row[LF][0] = str[16];
    row[LF][1] = str[18];
    row[LF][2] = str[20];
    row[LF][3] = str[22];
    row[RG][0] = str[24];
    row[RG][1] = str[26];
    row[RG][2] = str[28];
    row[RG][3] = str[30];
}
int main(int argc, char *argv[])
{
    char str[] = "1 2 3 4 1 2 3 4 1 2 3 4 1 2 3 4";
}