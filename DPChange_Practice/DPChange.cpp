#include <iostream>
#include <vector>

using namespace std;

int DPChange(int money, const vector<int> &coins){
  vector<int> MinNumCoins; //Vector elements hold the number of coins needed to reach the value of index 
  MinNumCoins.resize(money+1);
  MinNumCoins[0] = 0; //One needs 0 coins to reach 0 coints
  
  for(int m = 1; m <= money; m++){
    MinNumCoins[m] = 100000;

    for(int i = 0; i < coins.size(); i++){
      if (m >= coins[i]){
	int NumCoins = MinNumCoins[m - coins[i]] + 1;
	if(NumCoins < MinNumCoins[m]) MinNumCoins[m] = NumCoins;	  
      }
    }

  }

  return MinNumCoins[money];
  
  

}


int main(){

  vector<int>  Coins = {1, 5, 6};

  cout << DPChange(9, Coins) << endl;
  
  return 0;
}
