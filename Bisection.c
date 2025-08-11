#include <stdio.h>
#include <math.h>

double f(double x) {
    return pow(x, 4) - 13;
}

int main() {
    double xl = 1.5, xr = 2.0, xm = 0, xm_old = 0, fm, fl;
    double error = 0.000001, approx_error = 100.0;
    int iter = 0, max_iter = 1000;
    
    printf("Bisection Method\n");
    printf("Iteration\txl\t\txr\t\txm\t\tf(xm)\t\tError(%%)\n");
    printf("--------------------------------------------------------------------\n");
    
    do {
        xm_old = xm;
        xm = (xl + xr) / 2;
        fm = f(xm);
        fl = f(xl);
        
        if (iter > 0) {  
            approx_error = fabs((xm - xm_old) / xm) * 100.0;
        }
        
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\t", iter + 1, xl, xr, xm, fm);
        if (iter > 0) {
            printf("%.6f\n", approx_error);
        } else {
            printf("N/A\n");
        }
        
        if (fl * fm < 0) {
            xr = xm;    
        } else {
            xl = xm;    
        }
        
        iter++;
        
        if (iter >= max_iter) {
            break;
        }
        
    } while (iter == 1 || approx_error > error ); 
    
    printf("\nFinal result:\n");
    printf("Root approximation = %.6f\n", xm);
    printf("Relative error = %.6f%%\n", approx_error);
    printf("Function value at root = %.6f\n", fm);
  
}
