#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
//this didn't work
//maybe because: 
/*
int fibonacci_sum_fast(long long n){
  if(n<=1)
    return n;
  int F[n];
  F[0]=0;
  F[1]=1;
  int sum=1;
  for(long long i=2;i<=n;++i){
    F[i]=(F[i-1]+F[i-2])%10;
    sum=(sum+F[i])%10;
    std::cout<< F[i]<<' '<<sum<<std::endl;
  }
  return sum;
}
*/
int fibonacci_sum_fast(long long n){
  if(n<=1)
    return n;
  long long F[n];
  F[0]=0;
  F[1]=1;
  for(long long i=2;i<=n+2;++i){
    F[i]=(F[i-1]+F[i-2])%10;
  }
  return (F[n+2]-1)%10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
    return 0;
}
