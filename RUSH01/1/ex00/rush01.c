#include <unistd.h>
#include <stdlib.h>

// DEFINIENDO LA CUADRÍCULA (MATRIZ 4X4 INICIALIZADA CON CEROS)
int grid[4][4] = {{0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

// PISTAS DE EJEMPLO (ARRIBA, DERECHA, ABAJO, IZQUIERDA - EN SENTIDO HORARIO ALREDEDOR DE LA CUADRÍCULA)
int clues[16] = {2, 2, 1, 3, 2, 2, 3, 1, 2, 3, 1, 2, 1, 3, 2, 2};

// FUNCIÓN PARA ESCRIBIR UN SOLO CARÁCTER EN LA SALIDA ESTÁNDAR
void write_char(char c) {
    write(1, &c, 1);
}

// FUNCIÓN PARA IMPRIMIR LA CUADRÍCULA USANDO LA FUNCIÓN WRITE
void print_grid() {
    int i = 0;
    while (i < 4) {
        int j = 0;
        while (j < 4) {
            char c = grid[i][j] + '0';
            write_char(c);
            write_char(' ');
            j++;
        }
        write_char('\n');
        i++;
    }
}

// FUNCIÓN PARA APLICAR RESTRICCIONES BÁSICAS SEGÚN LAS PISTAS
	void apply_basic_constraints() {
    int i = 0;
    while (i < 16) {
        //Si la pista es 1, coloca un edificio de altura 4en la posición correspondiente.
        if (clues[i] == 1) {
            if (i < 4) grid[0][i] = 4; // Pistas de arriba
            else if (i < 8) grid[i - 4][3] = 4; // Pistas de la derecha
            else if (i < 12) grid[3][11 - i] = 4; // Pistas de abajo
            else grid[12 - i][0] = 4; // Pistas de la izquierda
        }
        //Si la pista es 4, coloca edificios en orden ascendente.
        else if (clues[i] == 4) {
            int j = 0;
            while (j < 4) {
                if (i < 4) grid[j][i] = j + 1; // Pistas de arriba
                else if (i < 8) grid[i - 4][3 - j] = j + 1; // Pistas de la derecha
                else if (i < 12) grid[3 - j][11 - i] = j + 1; // Pistas de abajo
                else grid[12 - i][j] = j + 1; // Pistas de la izquierda
                j++;
            }
        }
		else if (clues[i] == 3) {

		}
        i++;
    }
}

int main() {
    apply_basic_constraints();
    print_grid();
    return 0;
}
