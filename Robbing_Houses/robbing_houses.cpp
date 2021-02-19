#include<iostream>
#include<vector>

using namespace std;

int Maximum_Loot(vector<int>& HouseVals){
  if(HouseVals.size() == 0) return 0;
  if(HouseVals.size() == 1) return HouseVals[0];
  if(HouseVals.size() == 2) return max(HouseVals[0], HouseVals[1]);
  
  int Max_Loot = 0;
  int TotalLoot1 = HouseVals[0];
  int TotalLoot2 = HouseVals[1];

 
  
  for(int i = 2; i < HouseVals.size(); i++){
    //int tmp = TotalLoot1;
    Max_Loot = max(HouseVals[i] + TotalLoot1, TotalLoot2);
    TotalLoot1 = TotalLoot2;
    TotalLoot2 = Max_Loot;
  }

  return Max_Loot;
  
}

int main(){
  vector<int> HouseValues = {1, 2, 3, 1};
  int Answer = Maximum_Loot(HouseValues);
  
  cout << "The maximum loot that can be obtained from houses is: " << Answer << endl;
}
