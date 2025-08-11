#include <stdio.h>

void printMatrix(double a[3][4]) {
	
	int i,j;
	
    printf("Matrix:\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
            printf("%8.3f ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    double a[3][4] = {
        {-2, 3, 1, 9},
        { 3, 4, -5, 0},
        { 1, -2, 1, -4}
    };
    
    int i;
    double factor;
    
    // Forward elimination
    for (i = 0; i < 4; i++) { // R1 = R1 / -2
        a[0][i] /= -2;
    }
    printMatrix(a);
    
    factor = a[1][0]; // R2 = R2 - 3*R1
    for (i = 0; i < 4; i++) {
        a[1][i] -= factor * a[0][i];
    }
    printMatrix(a);
    
    factor = a[2][0]; // R3 = R3 - 1*R1
    for (i = 0; i < 4; i++) {
        a[2][i] -= factor * a[0][i];
    }
    printMatrix(a);
	
	factor = a[1][1]; // R2 = R2 / a[1][1]
    for (i = 0; i < 4; i++) {
        a[1][i] /= factor;
    }
    printMatrix(a);
    
    factor = a[2][1]; // R3 = R3 - a[2][1]*R2
    for (i = 0; i < 4; i++) {
        a[2][i] -= factor * a[1][i];
    }
    printMatrix(a);
    
    factor = a[2][2]; // R3 = R3 / a[2][2]
    for (i = 0; i < 4; i++) {
        a[2][i] /= factor;
    }
	printMatrix(a);
    
    // Back elimination (Jordan part)
    factor = a[1][2]; // R2 = R2 - a[1][2]*R3
    for (i = 0; i < 4; i++) {
        a[1][i] -= factor * a[2][i];
    }
    printMatrix(a);
    
    factor = a[0][2]; // R1 = R1 - a[0][2]*R3
    for (i = 0; i < 4; i++) {
        a[0][i] -= factor * a[2][i];
    }
    printMatrix(a);
    
    factor = a[0][1]; // R1 = R1 - a[0][1]*R2
    for (i = 0; i < 4; i++) {
        a[0][i] -= factor * a[1][i];
    }
    printMatrix(a);
    
    // Now matrix is Identity, answers are in last column
    double x = a[0][3];
    double y = a[1][3];
    double z = a[2][3];
    
    printf("x = %.0f\ny = %.0f\nz = %.0f\n", x, y, z);
    return 0;
}
