#include <stdio.h>

int add(int *a, int *b, int *c) {
    return (*a + *b + *c);
}

int main() {
    int x, y, z;
    
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);

    int sum = add(&x, &y, &z);

    printf("The sum of %d, %d, and %d is: %d\n", x, y, z, sum);

    return 0;
}
