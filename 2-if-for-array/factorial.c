#include <stdio.h>

#define DIVISOR 10007

long long factorial(long long input);

int main() {
  long long n = 0;
  scanf("%lld", &n);
  long long result = 0;
  for (long long i = 1; i <= n; i++) {
    result += factorial(i) % DIVISOR;
  }
  
  result =result%DIVISOR;
  printf("%lld",result);
  return 0;
}

long long factorial(long long input){
  long long result=1;
  for (long long i = 1;i <=input;i++){
    result =(result*i)%DIVISOR;
  }
  return result;
}
