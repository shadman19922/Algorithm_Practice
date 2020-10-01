#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


vector<int> Distinct_Summands(int x){

  int TotPrize = x;  
  vector<int> Prizes;
  int current_remainder, previous_remainder;
  int counter = 1;

  previous_remainder = TotPrize;
  bool StillAtIt = true;
  
  while(StillAtIt){

    //Prizes.push_back(counter);
    current_remainder = previous_remainder - counter;

    if(current_remainder > counter){
      Prizes.push_back(counter);
      counter++;
      previous_remainder = current_remainder;
    }

    else{
      Prizes.push_back(previous_remainder);
      StillAtIt = false;
    }
    
  }
  
  return Prizes; 
}

int main(){
  
  vector<int> Summands = Distinct_Summands(3);

  for(int i = 0; i < Summands.size(); i++){
    cout << Summands[i] << " ";
  }

  cout << "\n";
  

}
