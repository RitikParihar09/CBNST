#include <stdio.h>

float f(float x, float y) {
    return x + y;  
}
int main() {
    float x0, y0, h, x_end;
    printf("Enter the initial value of x (x0): ");
    scanf("%f", &x0);
    printf("Enter the initial value of y (y0): ");
    scanf("%f", &y0);
    printf("Enter the step size (h): ");
    scanf("%f", &h);
    printf("Enter the end value of x (x_end): ");
    scanf("%f", &x_end);
    float x=x0;
    float y=y0;
    while(x<x_end){
        printf("%.4f  %.4f\n",x,y);
        y=y+h*f(x,y);
        x+=h;
    }
}