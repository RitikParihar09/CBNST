#include <stdio.h>

void main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    
    float x[n], y[n][n];  // y[n][n] is used for backward difference table

    // Input x and y values
    for (int i = 0; i < n; i++) {
        printf("Enter x and y for point %d: ", i + 1);
        scanf("%f %f", &x[i], &y[i][0]); // Store y[i][0] as the initial y value
    }

    // Calculate backward differences
    for (int j = 1; j < n; j++) {
        for (int i = n-1; i >=j; i--) {
            y[i][j] = y[i][j - 1] - y[i-1][j - 1];
        }
    }

    // Print the backward difference table
    printf("\nForward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        printf("%f ", x[i]);
        for (int j = 0; j <=i; j++) {
            printf("| %f ", y[i][j]); // Only print valid differences
        }
        printf("\n");
    }
    
    float value;
    printf("Enter the value of x for interpolation: ");
    scanf("%f", &value);
    
    // Newton backward Interpolation formula
    float result = y[n-1][0]; // Initialize result with the first term
    float u = (value - x[n-1]) / (x[1] - x[0]); // Calculate u for interpolation
    float u_term = u; // Initialize u_term to u
    float fact = 1; // Initialize factorial

    // Calculate the interpolated value using the Newton backward Formula
    for (int i = 1; i < n; i++) {
        // u_term is updated to (u * (u-1) * ... * (u-(i-1)))
        u_term *= (u + (i - 1)); 
        fact *= i; // Update factorial
        result += (u_term * y[n-1][i]) / fact; // Add to result
    }

    printf("The interpolated value at x = %f is: %f\n", value, result);
}
