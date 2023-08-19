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
        write_char('\\n');
        i++;
    }
}

// FUNCIÓN PARA APLICAR RESTRICCIONES BÁSICAS SEGÚN LAS PISTAS
void apply_basic_constraints() {
    int i = 0;
    while (i < 16) {
        if (clues[i] == 1) {
            if (i < 4) grid[0][i] = 4;
            else if (i < 8) grid[i - 4][3] = 4;
            else if (i < 12) grid[3][11 - i] = 4;
            else grid[12 - i][0] = 4;
        }
        else if (clues[i] == 4) {
            int j = 0;
            while (j < 4) {
                if (i < 4) grid[j][i] = j + 1;
                else if (i < 8) grid[i - 4][3 - j] = j + 1;
                else if (i < 12) grid[3 - j][11 - i] = j + 1;
                else grid[12 - i][j] = j + 1;
                j++;
            }
        }
        i++;
    }
}

// FUNCIÓN PARA VERIFICAR LA PISTA DE UNA FILA O COLUMNA
int check_clue(int values[4], int clue) {
    int count = 0;
    int max_height = 0;
    int i = 0;
    while (i < 4) {
        if (values[i] > max_height) {
            max_height = values[i];
            count++;
        }
        i++;
    }
    return clue == 0 || clue == count;
}

// FUNCIÓN PARA VERIFICAR SI UN VALOR ES VÁLIDO EN UNA CELDA DADA
int is_valid(int value, int row, int col) {
    int i = 0;
    while (i < 4) {
        if (grid[row][i] == value || grid[i][col] == value) {
            return 0;
        }
        i++;
    }
    int temp_row[4];
    int temp_col[4];
    i = 0;
    while (i < 4) {
        temp_row[i] = (i == col) ? value : grid[row][i];
        temp_col[i] = (i == row) ? value : grid[i][col];
        i++;
    }
    if (!check_clue(temp_col, clues[col]) || !check_clue(temp_col, clues[11 - col])) {
        return 0;
    }
    if (!check_clue(temp_row, clues[15 - row]) || !check_clue(temp_row, clues[4 + row])) {
        return 0;
    }
    return 1;
}

// FUNCIÓN DE BACKTRACKING PARA RESOLVER EL ROMPECABEZAS
int solve(int row, int col) {
    if (row == 4) {
        return 1;
    }
    if (grid[row][col] != 0) {
                return solve(col == 3 ? row + 1 : row, col == 3 ? 0 : col + 1);
    }

    // PROBAR DIFERENTES VALORES EN LA CELDA ACTUAL
    int value = 1;
    while (value <= 4) {
        if (is_valid(value, row, col)) {
            grid[row][col] = value;
            if (solve(col == 3 ? row + 1 : row, col == 3 ? 0 : col + 1)) {
                return 1; // SOLUCIÓN ENCONTRADA
            }
            grid[row][col] = 0; // RETROCEDER
        }
        value++;
    }

    return 0; // NO SE ENCONTRÓ SOLUCIÓN
}

int main() {
    apply_basic_constraints();
    if (solve(0, 0)) {
        print_grid();
    } else {
        write(1, "No solution found\\n", 18);
    }
    return 0;
}
