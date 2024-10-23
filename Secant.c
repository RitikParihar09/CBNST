#include <stdio.h>
#include <math.h>
#define error 0.00001
#define maxStep 100
double f(double x)
{
    return x - cos(x);
}
int main()
{
    double x0, x1, x, f0, f1, f2;

    printf("Enter first approximation: ");
    scanf("%lf", &x0);

    printf("Enter second approximation: ");
    scanf("%lf", &x1);

    int i = 0;
    while (i < maxStep)
    {
        x = ((x0 * f(x1)) - (x1 * f(x0))) / (f(x1) - f(x0));
        printf("Value of root at iteration %d: %lf\n", i + 1, x);

        if (fabs(f(x)) < error)
        {
            printf("Root is : %lf \n", x);
            break;
        }
        x0 = x1;
        x1 = x;

        i++;
    }

    return 0;
}