#include <stdio.h>
int sumOfCubes(int n) {// Function to calculate sum of cubes
int sum = 0;
for(int i = 1; i <= n; i++) {
sum += i * i * i;
}
return sum;
}
int main() {
int n;
printf("Enter a positive number: ");
scanf("%d", &n);
int result = sumOfCubes(n);
printf("Sum of cubes of first %d natural numbers is: %d\n", n, result);
return 0;
}
