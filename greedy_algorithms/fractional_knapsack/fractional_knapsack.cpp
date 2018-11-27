#include <iostream>
#include <vector>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  
  std::vector<int> A(weights.size());
  for(int i=0;i<weights.size();++i){
    A[i]=0;
  }
  double V=0;
  int n=weights.size();
  for(int i=0;i<n;++i){
    if(capacity==0)
      return V;
    //int get_iter_max=max_vi_wi((vector<int>) weights,(vector<int>) values);
    double max=0;
    int iter_max=10;
    for(int i=0;i<n;++i){
      if(weights[i]>0 && (double) values[i]/weights[i]>max){
	max=(double)values[i]/weights[i];
	iter_max=i;
      }
    }
    double a=0;
    if(weights[iter_max]<capacity)
      a=weights[iter_max];
    else
      a=capacity;
    V=V+a*values[iter_max]/weights[iter_max];
    weights[iter_max]=weights[iter_max]-a;
    A[iter_max]=A[iter_max]+a;
    capacity=capacity-a;
  }
  return V;
}


int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
