#include <iostream>

int get_change(int m) {
  int n_ten=m/10;
  int n_five=(m%10)/5;
  int n_one=m%5;
  return n_ten+n_five+n_one;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
