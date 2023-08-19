#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//TABLA 4X4

int grid[4][4] = 0;

//NUMEROS DE EJEMPLO PARA PROBAR

int nums[16] = {2, 2, 1, 3, 2, 2, 3, 1, 2, 3, 1, 2, 1, 3, 2, 2};

//RESTRICCIONES BASICAS O NORMAS

void apply_basic_constraints() {
    int i = 0;
    while (i < 16) {
        // Si la pista es 1, coloca un edificio de altura 4 en la posicion correcta.
        if (clues[i] == 1) {
            if (i < 4) grid[0][i] = 4; // Pistas arriba.
            else if (i < 8) grid[i - 4][3] = 4; // Pistas derecha.
            else if (i < 12) grid[3][11 - i] = 4; // Pistas abajo.
            else grid[12 - i][0] = 4; // Pistas izquierda.
        }
        // Si la pista es 4, coloca edificios en orden ascendente.
        else if (clues[i] == 4) {
            int j = 0;
            while (j < 4) {
                if (i < 4) grid[j][i] = j + 1; // Pistas de arriba.
                else if (i < 8) grid[i - 4][3 - j] = j + 1; // Pistas de la derecha.
                else if (i < 12) grid[3 - j][11 - i] = j + 1; // Pistas de abajo.
                else grid[12 - i][j] = j + 1; // Pistas de la izquierda.
                j++;
            }
        }
        i++;
    }
}

//AHORA A IMPRIMIR LA TABLA

void print_grid() {
    int i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            printf("%d ", grid[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

int main() {
    apply_basic_constraints();
    print_grid();
    return 0;
}
