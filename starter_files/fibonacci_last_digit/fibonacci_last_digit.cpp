#include <iostream>
#include <cassert>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    long previous = 0;
    long current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        long  tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return (current % 10);

}
int get_fibonacci_last_digit_fast(int n){
    int F[n];
    F[0]=0;
    F[1]=1;
    for(int i=2;i<=n;++i){
      F[i]=(F[i-1]+F[i-2])%10;
    }
    return F[n];
}
void test_solution(){
    if(get_fibonacci_last_digit_fast(3)==2)
      std::cout<<"ok"<<'\n';

    if(get_fibonacci_last_digit_fast(10)==5)
      std::cout<<"ok"<<'\n';
    //    assert(get_fibonacci_last_digit_fast(331)==9);
    for(int n=20;n<=200;++n){
      if(get_fibonacci_last_digit_fast(n)==get_fibonacci_last_digit_naive(n)){
	std::cout<<"ok"<<'\n';
      }
      std::cout<<"n="<<n<<" fast: "<<get_fibonacci_last_digit_fast(n)<<' '<<"naive: "<<get_fibonacci_last_digit_naive(n)<<'\n';
      
    }
}
/*int get_fibonacci_last_digit_fast(int n){
    if(n<=1)
      return n;
    int previous =0;
    int current =1;
    
    for(int i=0; i<n-1;++i){
      int tmp_previous=previous%10;
      previous=current%10;
      current=tmp_previous+current;
    }
    return current;
}
*/

int main() {
    int n;
    std::cin >> n;
    int c = get_fibonacci_last_digit_fast(n);
    std::cout << c << '\n';
    //test_solution();
    //std::cout <<get_fibonacci_last_digit_fast(n)<<'\n';
    return 0;
}
