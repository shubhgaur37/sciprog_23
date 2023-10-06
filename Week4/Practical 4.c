#include <stdio.h>
#include <math.h>

// Declare constants and arrays
int num_intervals = 12;
double tan_values[13];

// Function declarations
double convert_degrees_to_radians(double degrees);
double calculate_integral_approximation(int num_intervals);

int main() {
    // Initialize variables
    int i;
    double degrees, radians;

    // Calculate tan values for equidistant points from 0 to 60 degrees
    for (i = 0; i <= num_intervals; i++) {
        degrees = i * 5.0;
        radians = convert_degrees_to_radians(degrees);
        tan_values[i] = tan(radians);
    }

    // Calculate the integral using the modified rule
    double integral_approximation = calculate_integral_approximation(num_intervals);
    double integral_exact = log(2.0);

    // Print the results with updated statements
    printf("The numerical approximation of the integral from x=0 degrees to x=60 degrees for the function tan(x) with respect to x is:\n%.5f\n", integral_approximation);
    printf("The exact value of the integral is:\n%.5f\n", integral_exact);

    return 0;
}

// Function to convert degrees to radians
double convert_degrees_to_radians(double degrees) {
    return (degrees * M_PI) / 180.0;
}

// Function to perform the modified rule
double calculate_integral_approximation(int num_intervals) {
    int i;
    double width, area = tan_values[0] + tan_values[num_intervals];

    for (i = 1; i < num_intervals; i++) {
        area += 2.0 * tan_values[i];
    }

    // Calculate width and finalize the area
    width = convert_degrees_to_radians((60.0 - 0) / (2.0 * num_intervals));
    area = width * area;

    return area;
}
