#include<stdio.h>
int sumOfSquares(int n){ // Function to calculate Sum of Squares
int sum = 0;
for(int i = 0;i <= n; i++){
sum += i * i;
}
return sum;
}
int main(){
int n ;
printf("Enter a positive number: ");
scanf("%d", &n);
int result = sumOfSquares(n);
printf("Sum of squares of first %d natural numbers is: %d\n",n,result);
return 0;
}
