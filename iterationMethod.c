#include <stdio.h>
#include <math.h>

double g(double x) {
    return (x * x + 2) / 3;  
}


double fixedPointIteration(double x0, double tolerance, int maxIter) {
    double x1;
    int iter = 0;

    
    while (iter < maxIter) {
        
        x1 = g(x0);

        
        printf("Iteration %d: x = %.6f\n", iter + 1, x1);

       
        if (fabs(x1 - x0) < tolerance) {
            printf("Converged after %d iterations.\n", iter + 1);
            return x1;
        }

        
        x0 = x1;
        iter++;
    }

    
    printf("Max iterations reached. Result may not be accurate.\n");
    return x1;
}

int main() {
    double x0, tolerance;
    int maxIter;

    
    printf("Enter initial guess x0: ");
    scanf("%lf", &x0);
    printf("Enter tolerance: ");
    scanf("%lf", &tolerance);
    printf("Enter maximum iterations: ");
    scanf("%d", &maxIter);

    double root = fixedPointIteration(x0, tolerance, maxIter);
    printf("Root is: %.6f\n", root);

    return 0;
}
