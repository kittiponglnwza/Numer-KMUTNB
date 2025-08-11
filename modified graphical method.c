#include <stdio.h>

double f(double x) {
    return 43 * x - 180;  
}

int main() {
    double start = 0, end = 10, step = 1;
    double x, fx1, fx2;
    double y, z;

    printf("Graphical method\n");

    x = start;
    do {
        fx1 = f(x);
        fx2 = f(x + step);

        printf("x = %.2f\tf(x) = %.2f\n", x, fx1);

        if (fx1 * fx2 < 0) {
            y = x;
            z = x + step;
            printf("Root is between %.2f and %.2f\n", y, z);
            break;
        }

        x += step;

    } while (x <= end); 

    double step_1 = 0.000001;
    double x1 = y;

    do {
        fx1 = f(x1);
        fx2 = f(x1 + step_1);

        if (fx1 * fx2 < 0) {
            printf("Approximate root: %.6f (f(x) = %.6f)\n", x1, fx1);
            break;
        }

        x1 += step_1;
    } while (x1 <= z);

}

