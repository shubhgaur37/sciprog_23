#include <stdio.h>

// Function to perform matrix multiplication
void matrixMultiply(int rowsA, int colsA, int colsB, double matrixA[rowsA][colsA], double matrixB[colsA][colsB], double resultMatrix[rowsA][colsB]) {
    int i, j, k;

    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) {
            for (k = 0; k < colsA; k++) {
                resultMatrix[i][j] = resultMatrix[i][j] + matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    int rowsA = 5, colsA = 3, colsB = 4; // Dimensions of matrices
    double matrixA[rowsA][colsA], matrixB[colsA][colsB], resultMatrix[rowsA][colsB];
    int i, j;

    // Initializing matrix A
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsA; j++) {
            matrixA[i][j] = i + j;
        }
    }

    // Initializing matrix B
    for (i = 0; i < colsA; i++) {
        for (j = 0; j < colsB; j++) {
            matrixB[i][j] = i - j;
        }
    }

    // Initializing result matrix to 0
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) {
            resultMatrix[i][j] = 0.0;
        }
    }

    // Calling the matrixMultiply function
    matrixMultiply(rowsA, colsA, colsB, matrixA, matrixB, resultMatrix);

    printf("\n Matrix A: \n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsA; j++) {
            printf("%3.0f ", matrixA[i][j]);
        }
        printf("\n");
    }

    printf("\n Matrix B: \n");
    for (i = 0; i < colsA; i++) {
        for (j = 0; j < colsB; j++) {
            printf("%3.0f ", matrixB[i][j]);
        }
        printf("\n");
    }

    printf("\n Result Matrix C (Matrix A * Matrix B): \n");
    for (i = 0; i < rowsA; i++) {
        for (j = 0; j < colsB; j++) {
            printf("%3.0f ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
