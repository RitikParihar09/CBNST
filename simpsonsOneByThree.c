#include <stdio.h>

double f(double x) {
    return 1/(1+x*x); 
}


double SimpsonOneByThree(double a, double b, int n) {
    double h = (b - a) / n; 
    double sum = f(a) + f(b); 
    if (n % 2 != 0) {
        printf("Number of subintervals (n) must be even for Simpson's 1/3 rule.\n");
        return -1; 
    }
 
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x); 
        } else {
            sum += 4 * f(x); 
        }
    }

    return (h / 3) * sum; 
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

    double result = SimpsonOneByThree(a, b, n);
    if (result != -1) {
        printf("The integral of the function using Simpson's 1/3 rule is: %.6f\n", result);
    }
    return 0;
}
