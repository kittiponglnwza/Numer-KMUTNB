#include <stdio.h>
#include <math.h>

double f(double x){
    return pow(x, 4) - 13;
}

int main(){
    double xl = 1.5, xr = 2.0, error = 0.000001, approx_error = 100.0;
    double xm = 0, fl, fr, fm, xm_old = 0;  
    int i = 1, max_iter = 1000;
    
    printf("Iteration\txl\t\txr\t\txm\t\tf(xm)\t\tError(%%)\n");
    printf("--------------------------------------------------------------------\n");
    
    do {
        xm_old = xm;
        fl = f(xl);
        fr = f(xr);
        
        xm = (xl * fr - xr * fl) / (fr - fl);
        fm = f(xm);
        
        
        if (i > 1) {  
            approx_error = fabs((xm - xm_old) / xm) * 100.0;
        }
        
        printf("%d\t\t%.6f\t%.6f\t%.6f\t%.6f\t", i, xl, xr, xm, fm);
        if (i > 1) {
            printf("%.6f\n", approx_error);
        } else {
            printf("N/A\n");
        }
        
        if (fl * fm < 0) {
            xr = xm;   
        } else {
            xl = xm;   
        }
        
        i++;
        
        
    } while (i <= 2 || approx_error > error * 100.0); 
    
    printf("\nFinal result:\n");
    printf("Root approximation = %.6f\n", xm);
    printf("Relative error = %.6f%%\n", approx_error);
    

}
