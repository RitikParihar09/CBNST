#include <stdio.h>
#include <math.h>

#define ERROR 0.00001
#define MAX_STEP 100

double f(double x) {
    return x * cos(x) - pow(x, 2);
}

double fd(double x) {
    return cos(x) - x * sin(x) - 2 * x; // Correct derivative calculation
}

int main() {
    double x0, x;

    printf("Enter initial approximation: ");
    scanf("%lf", &x0);

    int i = 0;
    while (i < MAX_STEP) {
        double derivative = fd(x0);

        // Check for zero derivative to avoid division by zero
        if (fabs(derivative) < 1e-10) {
            printf("Derivative is zero. No solution found.\n");
            return -1; // Exit with an error code
        }

        x = x0 - (f(x0) / derivative);
        printf("Value of root at iteration %d: %lf, f(x) = %lf\n", i + 1, x, f(x));

        // Check for convergence
        if (fabs(f(x)) < ERROR) {
            printf("Root is: %lf, f(x) = %lf\n", x, f(x));
            break; // Exit loop if root is found
        }

        x0 = x; // Update for next iteration
        i++;
    }

    return 0;
}
