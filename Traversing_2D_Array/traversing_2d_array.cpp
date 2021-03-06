#include <iostream>
#include <vector>

using namespace std;


int Number_Of_Ways(int n, int m){
  vector<int> Soln_Matrix;
  Soln_Matrix.resize(min(n, m));

  for(int i = 0; i < min(n,m); i++) Soln_Matrix[i] = 1;

  for(int j = 1; j < max(n,m); j++){
    for(int i = 1; i < min(n,m); i++){
      Soln_Matrix[i] = Soln_Matrix[i] + Soln_Matrix[i - 1];
    }
  }


  return Soln_Matrix[min(n,m) - 1];
}

int main(){
  
  cout << "The number of ways of traversing a 5 x 5 matrix is: " << Number_Of_Ways(5, 5);
  return 0;
}
