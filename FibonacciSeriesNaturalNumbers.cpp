#include <stdio.h>
void fibonacci(int n) {          // Function to print Fibonacci series
    int a = 0, b = 1, c;
    int i;
    printf("Fibonacci Series: ");
    for (i = 1; i <= n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Please enter a positive number.\n");
    } else {
        fibonacci(n);
    }
    return 0;
}
