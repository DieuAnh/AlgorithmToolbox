#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  return -1;
}


int get_majority_element_moore_voting_algorithm(vector<int> &a, int left, int right) {
  int count=0,majorityElement;
  for(int i=0;i<a.size();++i){
    if(count==0)
      majorityElement=a[i];
    if(a[i]==majorityElement)
      count++;
    else
      count--;
  }
  count=0;
  for(int i=0;i<a.size();++i){
    if(a[i]==majorityElement)
      count++;
    if(count>a.size()/2)
      return 1;//majorityElement;
  }
  return 0;//-1;
}
int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element_moore_voting_algorithm(a, 0, a.size()) ) << '\n';
}
