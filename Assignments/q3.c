#include <stdio.h>

int subtract(int x, int y) {
    while (y != 0) {
        unsigned borrow = (~x) & y;
        x = x ^ y;
        y = borrow << 1;
    }
    return x;
}

int main() {
    int a = 15, b = 6;
    printf("The difference is %d\n", subtract(a, b));
    return 0;
}
