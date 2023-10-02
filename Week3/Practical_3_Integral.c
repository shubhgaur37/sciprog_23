#include <stdio.h>
#include <math.h>

int main() {
    // Initialize the end-points and the number of points
    int N = 12;
    double x_0 = 0.0;
    double x_12 = M_PI / 3.0;
    double width = (x_12 - x_0) / (double)N;

    // Calculate the values of f(x) = tan(c) for the end-points, and then add
    double X = tan(x_0) + tan(x_12);

    // Get equidistant points, we need to evaluate tan at these points
    double x;
    double y;
    double sum = X;

    int i;
    for (i = 1; i < 12; i++) {
        x = x_0 + width * i;
        y = tan(x);
        sum += 2 * y;
    }

    double integral_approx = sum * width * 0.5;
    double integral_exact = log(2.0);

    printf("Your Approximation of the integral from x=0 to x=pi/3 of the function tan(x) with respect to x is \n %.5f\n The exact solution is: \n %.5f\n", integral_approx, integral_exact);

    return 0;
}
