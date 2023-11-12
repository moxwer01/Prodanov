#include <stdio.h>
#include <stdlib.h>

void initializeGrid(int grid[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void printGrid(int grid[][100], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 1) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
}

int countNeighbors(int grid[][100], int rows, int cols, int x, int y) {
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }

            int newRow = x + i;
            int newCol = y + j;

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                if (grid[newRow][newCol] == 1) {
                    count++;
                }
            }
        }
    }

    return count;
}

void updateGrid(int grid[][100], int rows, int cols) {
    int newGrid[rows][cols];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int aliveNeighbors = countNeighbors(grid, rows, cols, i, j);

            if (grid[i][j] == 1) {
                if (aliveNeighbors < 2 || aliveNeighbors > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if (aliveNeighbors == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int grid[100][100];
    initializeGrid(grid, rows, cols);
    
    printf("Initial Grid:\n");
    printGrid(grid, rows, cols);

    for (int i = 0; i < 10; i++) {
        updateGrid(grid, rows, cols);

        printf("\n %d:\n", i + 1);
        printGrid(grid, rows, cols);
    }

    return 0;
}
