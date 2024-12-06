#include <stdio.h>
#include <math.h>
double f(double x) {
    return sqrt(x); 
}


double simpsonsThreeEighthRule(double a, double b, int n) {
    if (n % 3 != 0) {
        printf("Number of subintervals (n) must be a multiple of 3 for Simpson's 3/8 rule.\n");
        return -1; 
    }

    double h = (b - a) / n; 
    double sum = f(a) + f(b); 

    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * f(x); 
        } else {
            sum += 3 * f(x);
        }
    }

    return (3 * h / 8) * sum; 
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

    double result = simpsonsThreeEighthRule(a, b, n);
    if (result != -1) {
        printf("The integral of the function using Simpson's 3/8 rule is: %.6f\n", result);
    }
   return 0;
}
