#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

/*long long max_dot_product(vector<int> a, vector<int> b) {
  long long result = 0;
  int n=a.size();
  for (size_t i = 0; i < n; i++) {
    size_t max_a=a[0];
    size_t iter_max_a=0;
    for (size_t i=1; i < a.size();i++){
      if(a[i]>max_a){
	max_a=a[i];
        iter_max_a=i;}
    }
    size_t max_b=b[0];
    size_t iter_max_b=0;
    for(size_t i=1; i < b.size();i++){
      if(b[i]>max_b){
	max_b=b[i];
        iter_max_b=i;}
    }
    result += ((long long) a[iter_max_a]) * b[iter_max_b];
    a.erase(a.begin()+iter_max_a);
    b.erase(b.begin()+iter_max_b);
  }
  return result;
}
*/
long long max_dot_product(vector<int> a,vector<int> b){
    long long result=0;
    int n=a.size();
    for(size_t i=0;i<n;i++){
      std::vector<int>::iterator max_a,max_b;
      max_a=std::max_element(a.begin(),a.end());
      max_b=std::max_element(b.begin(),b.end());
      result+=((long long) *(max_a))*(*max_b);
      //std::cout<< "max_a= "<<*max_a<<" max_b= "<<*max_b<<std::endl;
      //int iter_max_a=std::distance(a.begin(),max_a);
      //int iter_max_b=std::distance(b.begin(),max_b);
      //a.erase(std::remove(a.begin(),a.end(),),a.end());
      //b.erase(std::remove(b.begin(),b.end(),),b.end());
      a.erase(a.begin()+(std::distance(a.begin(),max_a)));
      b.erase(b.begin()+(std::distance(b.begin(),max_b)));
      //std::cout<<"size"<<a.size()<<std::endl;
    }
    return result;
 }
int main() {
  size_t n;//size_t: unsigned integral type
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
  return 0;
}
