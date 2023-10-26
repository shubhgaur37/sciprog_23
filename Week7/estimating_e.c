#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int n)
{
    if (n < 0)
    {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return -1;
    }
    else if (n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main(void)
{
    int i, order;
    double *eTerms, e;

    // Get the polynomial order from the user
    printf("Enter the polynomial order: ");
    scanf("%d", &order);

    eTerms = (double *)malloc(order * sizeof(double));

    // Calculate and display each term of the series
    for (i = 0; i < order; i++)
    {
        eTerms[i] = pow(1, i) / (double)factorial(i);
        printf("e term for order %d is %1.15lf\n", i + 1, eTerms[i]);
    }

    // Calculate the value of e by summing up the terms
    e = 0.0;
    for (i = 0; i < order; i++)
    {
        e += eTerms[i];
    }

    // Display the calculated value of e
    printf("The calculated value of e is: %1.15lf\n", e);

    // Provide an explanation for the observed behavior
    printf("The estimate gets worse for higher order polynomials because as the order increases, "
           "the terms become smaller and the precision errors in floating-point arithmetic become more significant.\n");

    // Free the dynamically allocated memory
    free(eTerms);

    // Calculate the actual value of e using the math library
    double actualE = exp(1.0);

    // Display the difference between the calculated and actual values of e
    printf("The difference between calculated and actual e is: %1.15lf\n", fabs(e - actualE));

    return 0;
}
