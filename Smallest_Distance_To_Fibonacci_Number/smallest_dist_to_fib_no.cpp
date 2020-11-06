#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int smallest_distance(int Target){
  vector<int> FibNumbers = {0, 1};
  bool FibNumberFound = false;

  int N = 2;
  
  while(!FibNumberFound){
    int LatestFibNumber = FibNumbers[N - 1] + FibNumbers[N - 2];
    FibNumbers.push_back(LatestFibNumber);

    if(FibNumbers[N] >= Target && FibNumbers[N-1] < Target) FibNumberFound = true;
    else N++;
  }

  if(FibNumbers[N] - Target <= Target - FibNumbers[N-1]) return FibNumbers[N] - Target;
  else return Target - FibNumbers[N-1];
}


int main(){

  int TargetInteger;
  cin >> TargetInteger;
  int Answer = smallest_distance(TargetInteger);
  
  cout << "The Target Integer is: " << TargetInteger << endl;
  cout << "The distance to the nearest fibonacci number is: " << Answer << endl;
  
  return 0;
}
