#include <stdio.h>

int main() {
    double x = 0.0, Error = 0.000001, xnew;  
    int iteration = 0;
    
	printf("\tOne-point Method\n");
	
	if (x == 0){
		x = 0.000001;
	}
	
    do {
        xnew = x;
        
        x = 0.5 * (x + 7.0 / x);
        iteration++;
        
        printf("Iteration %d: x = %.6f\n", iteration, x);
            
    } while (fabs(x - xnew) / xnew > Error && iteration < 100);
    
    printf("Result: %.6f\n", x);
    printf("Error : %.6f\n",fabs(x - xnew) / xnew);
    
}
