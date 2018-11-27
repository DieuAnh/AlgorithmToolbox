#include <iostream>

long long  get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_pisano_period(long long m){
  long long a=0, b=1, c=a+b;
  for(int i=0;i<m*m;i++){
    c=(a+b)%m;
    a=b;
    b=c;
    if(a==0 && b==1) return i+1;
  }
}
void test_solution(long long m){
  for(int n=0;n<m;++n)
    std::cout<<"n="<<n<<' '<<get_pisano_period(n)<<std::endl;
}

long long get_fibonacci_huge_fast(long long n,long long m){
  long long remainder=n%get_pisano_period(m);
  
  long long first=0;
  long long second=1;
  long long res=remainder;
  for(int i=1;i<remainder;i++){
    res=(first+second)%m;
    first=second;
    second=res;
  }
  return res%m;
}
/*
this is too heavy for memory, instead, i try to use just 3 variables first, second, res to calcul fibonacci of remainder-th
long long get_fibonacci_huge_fast(long long n,long long m){
  long long remainder=n%get_pisano_period(m);
  long long F[n];
  F[0]=0;
  F[1]=1;
  for(int i=2;i<=remainder;++i){
    F[i]=(F[i-1]+F[i-2])%m;
  }
  return F[remainder]%m;
}
*/
int main() {
  long long n;
  long long m;
  std::cin >> n >> m;
  //test_solution(m);
  //std::cout << get_pisano_period(m) << std::endl;
  std::cout << get_fibonacci_huge_fast(n,m)<<'\n';
  return 0;
}
