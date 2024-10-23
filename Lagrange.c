#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    
    float x[n], y[n];  // Arrays to store x and y values

    // Input x and y values
    for (int i = 0; i < n; i++) {
        printf("Enter x and y for point %d: ", i + 1);
        scanf("%f %f", &x[i], &y[i]); // Store the y values
    }
    
    float value;
    printf("Enter the value of x for interpolation: ");
    scanf("%f", &value);
    
    float result = 0.0; // Initialize the result
    for (int i = 0; i < n; i++) {
        float term = y[i]; // Start with the y value
        for (int j = 0; j < n; j++) {
            if (i != j) {
                term = term * ((value - x[j]) / (x[i] - x[j])); // Calculate the Lagrange term
            }
        }
        result += term; // Add the term to the result
    }

    // Output the result
    printf("The interpolated value at x = %f is: %f\n", value, result);

    return 0; // Return success
}
