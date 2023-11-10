#include <stdio.h>
#include <stdlib.h>
#define MAX_FILE_NAME 100
#include "magic_square_stub.h"

// Function to get the number of lines in a file
int getNumberOfLines(char filename[MAX_FILE_NAME]);

int main() {
    // Define file-related variables
    FILE *file;
    char filename[MAX_FILE_NAME];
    
    // Prompt user to enter the file name
    printf("Enter file name: ");
    scanf("%s", filename);

    // Get the number of lines in the file
    int numRows = getNumberOfLines(filename);

    // Open the file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open the file.\n");
        exit(1);
    }
    int i, j;  // Declare 'i' and 'j' outside the loop
    // Allocate memory for the magic square as an array of pointers
    int **magicSquare = malloc(numRows * sizeof(int *));
    for (i = 0; i < numRows; i++) {
        magicSquare[i] = malloc(numRows * sizeof(int));
    }

    // Input integer data into the matrix
    printf("Magic Square:\n");

    for (i = 0; i < numRows; i++) {
        for (j = 0; j < numRows; j++) {
            fscanf(file, "%d", &magicSquare[i][j]);
            printf("%d\t", magicSquare[i][j]);
        }
        printf("\n");
    }

    // Check if the square is magic or not
    isMagicSquare(magicSquare, numRows);

    // Free each row separately before freeing the array of pointers
    for (i = 0; i < numRows; i++) {
        free(magicSquare[i]);
    }
    free(magicSquare);

    // Close the file
    fclose(file);

    return 0;
}

// Function to get the number of lines in a file
int getNumberOfLines(char filename[MAX_FILE_NAME]) {
    FILE *file = fopen(filename, "r");
    
    int chRead;
    int count = 0;

    // Count the number of lines in the file
    while ((chRead = fgetc(file)) != EOF) {
        if (chRead == '\n') {
            count++;
        }
    }

    printf("Number of lines: %d\n", count);
    
    // Close the file
    fclose(file);

    return count;
}
