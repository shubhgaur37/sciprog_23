#include <stdio.h>

// Checks if a matrix is a magic square.
// A magic square is an n-sided matrix whose sum of values for each
// row, column, main and secondary diagonals equals to n(n^2 + 1)/2.
// The function takes as input a matrix 'square' and its side length 'n'
// and outputs 0 if 'n' is negative or 'square' is NOT a magic square;
// otherwise, outputs a non-zero value.

int isMagicSquare(int **square, const int n) {
    // Eliminate the case where 'n' is negative
    if (n < 0) {
        return 0;
    }

    // M is the sum of every row, column,
    // and the main and secondary diagonals
    int M = (n * (n * n + 1)) / 2;

    printf("Sum of each row, column, and diagonal (M) is %d\n", M);

    // Checking that every row and column add up to M
    int i,j;
    for (i = 0; i < n; i++) {
        int rowSum = 0;
        int colSum = 0;

        for (j = 0; j < n; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }

        printf("Row %d sum = %d, Column %d sum = %d\n", i, rowSum, i, colSum);

        // Check if the sum of the row or column is not equal to M
        if (rowSum != M || colSum != M) {
            printf("Not a magic square\n");
            return 0;
        }
    }

    // Checking that the main and secondary diagonals each add up to M
    int mainDiagonalSum = 0;
    int secondaryDiagonalSum = 0;

    for (i = 0; i < n; i++) {
        mainDiagonalSum += square[i][i];
        secondaryDiagonalSum += square[i][n - 1 - i];
    }

    printf("Main diagonal sum = %d, Secondary diagonal sum = %d\n", mainDiagonalSum, secondaryDiagonalSum);

    // Check if the sum of the diagonals is not equal to M
    if (mainDiagonalSum != M || secondaryDiagonalSum != M) {
        printf("Not a magic square\n");
        return 0;
    }

    // If all checks passed, it is a magic square. Return 1
    printf("It is a magic square\n");
    return 1;
}
