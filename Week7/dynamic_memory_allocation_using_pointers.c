#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for an array of integers.
int *allocateArray(int size)
{
    int *arrayPointer;                                // Declare a pointer variable for the array.
    arrayPointer = (int *)malloc(size * sizeof(int)); // Allocate memory for an array and store its address.
    return arrayPointer;                              // Return the pointer to the allocated memory.
}

// Function to fill an array with ones.
void fillWithOnes(int *array, int size)
{
    int index; // Declare an integer variable for the loop index.
    for (index = 0; index < size; index++)
    {
        array[index] = 1; // Set each element of the array to 1.
    }
    // Print the size as an additional argument.
    printf("\nAdditional argument (size) implicitly passed to fillWithOnes: %d\n", size);
}

// Function to print the elements of an array.
void printArray(int *array, int size)
{
    int index; // Declare an integer variable for the loop index.
    for (index = 0; index < size; index++)
    {
        printf("arr[%d]: %d\n", index, array[index]); // Print the element at index i of the array.
    }
}

// Function to free memory allocated for an array.
void freeArrayMemory(int *array)
{
    free(array); // Free the memory associated with the array.
}

int main()
{
    int arraySize, *dynamicArray; // Declare integer arraySize and a pointer to an integer dynamicArray.

    printf("Enter the size of the array:\n"); // Prompt the user to enter the size of the array.
    scanf("%d", &arraySize);                  // Read an integer value from the user and store it in arraySize.

    dynamicArray = allocateArray(arraySize); // Allocate memory for an array and store the pointer in dynamicArray.
    fillWithOnes(dynamicArray, arraySize);   // Fill the allocated array with ones.

    printf("\nArray after filling with ones:\n");
    printArray(dynamicArray, arraySize); // Print the elements of the array.

    freeArrayMemory(dynamicArray); // Free the allocated memory.
    printf("\nMemory freed successfully.\n");

    dynamicArray = NULL; // Set the pointer dynamicArray to NULL.
    return 0;            // Return 0 to indicate successful program execution.
}
