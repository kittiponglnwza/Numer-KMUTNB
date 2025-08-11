#include <stdio.h>

int main() {
    double a[3][4] = {
        {-2, 3, 1, 9},
        { 3, 4, -5, 0},
        { 1, -2, 1, -4}
    };
    
    int i;

    for (i = 0; i < 4; i++) { // R1 = 1 (R1 = R1 / -2)
        a[0][i] /= -2;
    }

    double factor;

    factor = a[1][0]; // R2 = R2 - 3*R1
    for (i = 0; i < 4; i++) {
        a[1][i] -= factor * a[0][i];
    }

    factor = a[2][0]; // R3 = R3 - 1*R1
    for (i = 0; i < 4; i++) {
        a[2][i] -= factor * a[0][i];
    }

    factor = a[1][1];
    for (i = 0; i < 4; i++) {
        a[1][i] /= factor;
    }

    factor = a[2][1];
    for (i = 0; i < 4; i++) {
        a[2][i] -= factor * a[1][i];
    }

    factor = a[2][2];
    for (i = 0; i < 4; i++) {
        a[2][i] /= factor;
    }

    double z = a[2][3];
    double y = a[1][3] - a[1][2] * z;
    double x = a[0][3] - a[0][2] * z - a[0][1] * y;

    printf("x = %.0f\ny = %.0f\nz = %.0f\n", x, y, z);
	return 0;
}

