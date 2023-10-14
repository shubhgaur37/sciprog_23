#include<stdio.h>
#include<stdlib.h>

// Function to calculate the next Fibonacci number using pointers
void calculateNextFibonacci(int *current, int *previous) {
    int sum = *current + *previous;
    *previous = *current;
    *current = sum;
}

int main() {
    int n, i;
    int fib0 = 0, fib1 = 1;

    // Input the value of n
    printf("Enter the value of n: ");
    scanf("%d", &n);

    // Check if the input is positive
    if (n < 1) {
        printf("The number is not positive.\n");
        exit(1); // Terminate the program
    }

    printf("The Fibonacci sequence is:\n");
    printf("%d %d ", fib0, fib1);

    // Calculate Fibonacci sequence starting from the third element
    for (i = 3; i <= n; i++) {
        calculateNextFibonacci(&fib1, &fib0);
        printf("%d ", fib1);

        // Print a newline after every 10 elements for better presentation
        if ((i + 1) % 10 == 0)
            printf("\n");
    }

    return 0;
}
