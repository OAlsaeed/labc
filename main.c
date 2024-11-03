#include <stdio.h>

int main() {
    int a, b;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    int sum = a + b;           // Calculate sum
    float difference = a - b;    // Calculate difference

    printf("Sum: %d\n", sum);           // Print sum
    printf("Difference: %f\n", difference); // Print difference

    return 0;
}
                   
