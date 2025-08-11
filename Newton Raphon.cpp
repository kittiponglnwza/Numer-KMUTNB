#include <stdio.h>
#include <math.h>

int main() {
    double x0 = 2.0, x1;
    double error, agree = 0.000001;
    int iteration = 0, i = 0;
    
    printf("Initial I=%d X0=%.1f\n", i, x0);
    
    do {
        double sqrt7 = sqrt(7);
        x1 = 0.5 * (x0 + (7 / x0));
        iteration++;
        i++;
        
        printf("Iteration %d : X%d = %.1f\n", iteration, i, x1);
        
        error = fabs((x1 - sqrt7) / x1);
        printf("Error = %.1f\n", error);
        
        x0 = x1;
        
    } while (error > agree);
    
    printf("Result of sqrt7 = %.6f\n", x1);
    
    return 0;
}
