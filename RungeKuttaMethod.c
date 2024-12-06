#include <stdio.h>
#include <math.h>

double f(double x, double y) {
    return x + pow(y, 2); 
}

int main() {
    double x0, y0, xend, k, k1, k2, k3, k4;
    int n;

    printf("Enter initial value of x (x0): ");
    scanf("%lf", &x0);
    printf("Enter initial value of y (y0): ");
    scanf("%lf", &y0);
    printf("Enter end value of x (xend): ");
    scanf("%lf", &xend);
    printf("Enter number of steps (n): ");
    scanf("%d", &n);

    double h = (xend - x0) / n;

    for (int i = 0; i < n; i++) {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h * 0.5, y0 + k1 * 0.5);
        k3 = h * f(x0 + h * 0.5, y0 + k2 * 0.5);
        k4 = h * f(x0 + h, y0 + k3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6.0; 
        y0 = y0 + k;
        x0 = x0 + h;
    }
    
    printf("The final value of y at x = %lf is %lf\n", xend, y0);

    return 0;
}
