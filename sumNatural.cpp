#include<stdio.h>
int sumNatural(int n){ //Function of calculate Sum of 'n' Natural Numbers
int sum = 0;
for(int i = 0; i<=n;i++){
sum += i;
}
return sum;
}
int main(){
int n;
printf("Enter a positive number: ");
scanf("%d",&n);
int result = sumNatural(n);
printf("Sum of first %d natural numbers is %d\n", n , result);
return 0;
}
