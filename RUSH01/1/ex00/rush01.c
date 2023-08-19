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
    // PUEDES COPIAR LA IMPLEMENTACIÓN DEL FRAGMENTO ANTERIOR AQUÍ
}

int main() {
    apply_basic_constraints();
    print_grid();
    return 0;
}
