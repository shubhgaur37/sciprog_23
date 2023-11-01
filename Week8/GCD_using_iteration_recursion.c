#include<stdio.h>

// Function to find GCD using iteration
int gcd_iteration(int a, int b) {
    int temp; // Declare a temporary variable
    while (b != 0) { // Execute the loop until b becomes 0
        temp = b; // Store the current value of b in temp
        b = a % b; // Update b with the remainder of the division a by b
        a = temp; // Update a with the previous value of b (stored in temp)
    }
    return a; // Return the final GCD value
}

// Function to find GCD using recursion
int gcd_recursive(int a, int b) {
    if (b == 0)
        return a; // Base case: if b is 0, return a (the current GCD)
    else
        return gcd_recursive(b, a % b); // Recursive case: call the function with updated values of a and b
}

int main() {
    int num1, num2;

    // Input
    printf("Enter two numbers:\n");
    scanf("%d %d", &num1, &num2);

    // Output
    printf("The GCD calculated using Recursion is: %d\n", gcd_recursive(num1, num2));
    printf("The GCD calculated using Iteration is: %d\n", gcd_iteration(num1, num2));

    return 0;
}
