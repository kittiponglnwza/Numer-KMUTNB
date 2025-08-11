#include<stdio.h>
#include<math.h>
int main(){
    double x0=2.0, x1=3.0, x2, f0, f1, error;
    int i=0;
    
    do{
        f0 = x0*x0 - 7;
        f1 = x1*x1 - 7;
        x2 = x1 - f1*(x1-x0)/(f1-f0);
        error = fabs((x2-x1)/x2);
        printf("Iteration %d: x = %.6f\n", ++i, x2);
        x0=x1; x1=x2;
    }while(i<4 && error>0.000001);
    
    printf("Result: sqrt(7) = %.6f\n", x2);
    return 0;
}
