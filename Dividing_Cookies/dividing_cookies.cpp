#include<iostream>
#include<vector>

using namespace std;

int NumberofWaystoDivide(int nPeople, int nCookies){
  vector<vector<int>> Solution_Matrix;
  Solution_Matrix.resize(nCookies);
  for(int i = 0; i < Solution_Matrix.size(); i++) Solution_Matrix[i].resize(nPeople);
  
  for(int i = 0; i < Solution_Matrix.size(); i++) Solution_Matrix[i][0] = 1;
  for(int j = 1; j < Solution_Matrix[0].size(); j++) Solution_Matrix[0][j] = j+1;

  for(int i = 1; i < Solution_Matrix.size(); i++){ //Begin loop over i
    for(int j = 1; j < Solution_Matrix[1].size(); j++){ //Begin loop over j

      Solution_Matrix[i][j] = Solution_Matrix[i - 1][j] + Solution_Matrix[i][j - 1]; //Filling in the answers

    }//End loop over j
  }// End loop over i

  return Solution_Matrix[nCookies - 1][nPeople - 1];
}

int main(){

  int NumPeople = 5;
  int NumCookies = 10;

  int Answer = NumberofWaystoDivide(5, 10);
  
  cout << "The number of possible ways to divide " << NumCookies << " cookies between " << NumPeople << " people is: " << Answer << endl;
  
  return 0;
}
