#include <stdio.h>
#include <math.h>

// Function declarations
double calculate_arctanh1(const double x, const double delta);
double calculate_arctanh2(const double x);

int main() {
    double delta, x;

    // Input the precision value (delta)
    printf("Enter the value of delta (precision):\n");
    scanf("%lf", &delta);

    // Initialize arrays to store results
    int length = 1000;
    double arctanh1_values[length];
    double arctanh2_values[length];

    int j = 0;
    x = -0.9;

    // Calculate arctanh values for different x within the specified range
    while (x <= 0.9 && j < length) {
        arctanh1_values[j] = calculate_arctanh1(x, delta);
        arctanh2_values[j] = calculate_arctanh2(x);

        // Print the difference between the two calculations
        printf("The difference in arctanh values at x = %.1f is %.15f.\n", x, fabs(arctanh1_values[j] - arctanh2_values[j]));

        j++;
        x += 0.1; // Increment x by 0.1
    }

    // Compare the accuracy of each method with each other (to 10 significant figures)
    printf("\nComparison of accuracy to 10 significant figures:\n");
    int k;
    for (k = 0; k < j; k++) {
        printf("At x = %.1f: Method 1: %.10f, Method 2: %.10f\n", -0.9 + k * 0.1, arctanh1_values[k], arctanh2_values[k]);
    }

    return 0;
}

// Function to calculate arctanh using the specified precision (delta)
double calculate_arctanh1(const double x, const double delta) {
    double arcTan = 0;
    double elem;
    int n = 0;

    // Use a do-while loop to calculate terms until the desired precision is reached
    do {
        double val = 2 * n + 1;
        elem = pow(x, val) / val;
        arcTan += elem;
        n++;
    } while (fabs(elem) >= delta);

    return arcTan;
}

// Function to calculate arctanh using the logarithmic formula
double calculate_arctanh2(const double x) {
    return (log((1 + x) / (1 - x)) / 2);
}
