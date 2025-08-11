#include <stdio.h>

double find_det(double m[3][3]) {
	
    double det = 0.0;
    det += m[0][0] * m[1][1] * m[2][2];
    det += m[0][1] * m[1][2] * m[2][0];
    det += m[0][2] * m[1][0] * m[2][1];
    
    det -= m[0][2] * m[1][1] * m[2][0];
    det -= m[0][0] * m[1][2] * m[2][1];
    det -= m[0][1] * m[1][0] * m[2][2];
    return det;
}

double det3x3(double m[3][3]) {
    return find_det(m);
}

int main() {
    
    double A[3][3] = {{-2,3,1}, {3,4,-5}, {1,-2,1}};
    double b[3] = {9, 0, -4};
    
    double detA = det3x3(A);
    printf("det(A) = %.0f\n", detA);
    
    double A1[3][3] = {{9,3,1}, {0,4,-5}, {-4,-2,1}};
    double x1 = det3x3(A1) / detA;
      
    double A2[3][3] = {{-2,9,1}, {3,0,-5}, {1,-4,1}};
    double x2 = det3x3(A2) / detA;
    
    double A3[3][3] = {{-2,3,9}, {3,4,0}, {1,-2,-4}};
    double x3 = det3x3(A3) / detA;
    
    printf("x1 = %.2f\nx2 = %.2f\nx3 = %.2f\n", x1, x2, x3);
    
    return 0;
}
