#include <stdio.h>
int factorial(int n) { // Recursive function to find factorial
if(n == 0 || n == 1)
return 1;
else
return n * factorial(n - 1);
}
int main() {
int n;
printf("Enter a positive integer: ");
scanf("%d", &n);
if(n < 0)
printf("Factorial not defined for negative numbers.\n");
else
printf("Factorial of %d = %d\n", n, factorial(n));
return 0;
}
