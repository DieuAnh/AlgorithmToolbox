#include <iostream>
#include <vector>

using std::vector;

int DPchange(int money)
{
  vector<int> MinNumCoins(money);
  MinNumCoins[0]=0;
  MinNumCoins[1]=1;
  int coins[3];
  coins[0]=1;
  coins[1]=5;
  coins[2]=6;
  for(int m=1;m<=money;++m){
    long MinNumCoins[m];
    for (int i=0;i<3;++i){
      if(m>=coins[i]){
	std::cout << "loop in-in"<< "m=" <<m << " and coins["<<i<<"]="<<coins[i] <<std::endl; 
	long NumCoins=MinNumCoins[m-coins[i]];
	if(NumCoins<MinNumCoins[m]){
	  MinNumCoins[m]=NumCoins;
	}
	std::cout<< "MinNumCoins[" <<m<<"]="<<MinNumCoins[m]<< "and NumCoins="<< NumCoins<<std::endl;
      }
    }
    std::cout << "loop in" << std::endl;
  }
  return MinNumCoins[money];
}

int main()
{
  int money;
  std::cin >> money;
  int MinNumCoins = DPchange(money);
  std::cout << MinNumCoins << std::endl;
}
