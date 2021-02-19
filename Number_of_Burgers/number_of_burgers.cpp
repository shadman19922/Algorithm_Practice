#include<iostream>
#include<vector>


using namespace std;

vector<int> Burgers(int tomatoSlices, int cheeseSlices){
  if(cheeseSlices >= tomatoSlices) return {-1, -1};
  if(tomatoSlices % 2 != 0) return {-1, -1}; //
  //cout << "Made it past the first two exit conditions" << endl;

  //Solution obtained by solving simultaneuos equations
  int nJumbos = (tomatoSlices/2) - cheeseSlices ; //Number of Jumbo burgers
  int nSmall = (2*cheeseSlices) - (tomatoSlices/2); //Number of small burgers
  
  vector<int>Burgers = {nJumbos, nSmall};
  return Burgers;
}

int main(){
  int NtomatoSlices = 7;
  int NcheeseSlices = 17;
  
  vector<int> SomeBurgers = Burgers(NtomatoSlices, NcheeseSlices);
  cout << "The output array is: [" << SomeBurgers[0] << ", " << SomeBurgers[1] << "]" << endl;
  return 0;
}
