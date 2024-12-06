#include <stdio.h>

double f(double x) {
    return (1/x); 
}


double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n; 
    double sum = f(a) + f(b); 

 
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += 2 * f(x);
    }

    return (h / 2) * sum; 
}

int main() {
    double a, b;
    int n;

    printf("Enter the lower limit (a): ");
    scanf("%lf", &a);
    printf("Enter the upper limit (b): ");
    scanf("%lf", &b);
    printf("Enter the number of subintervals (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Number of subintervals must be greater than zero.\n");
        return 1;
    }

    double result = trapezoidalRule(a, b, n);
    printf("The integral of the function using the trapezoidal rule is: %.6f\n", result);

    return 0;
}
