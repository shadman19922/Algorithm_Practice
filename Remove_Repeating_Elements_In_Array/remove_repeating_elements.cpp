#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Remove_Elements(vector<int> &Inputs){
  sort(Inputs.begin(), Inputs.end());
  cout << "The sorted elements are: " << endl;

  int Vectorsize = Inputs.size() - 1;
  int Idx = 0;
  
  while(Idx < Vectorsize){
    if(Inputs[Idx] == Inputs[Idx+1]) Inputs.erase(Inputs.begin() + Idx + 1);
    else Idx++;

    Vectorsize = Inputs.size() - 1;
  }
  
  
}




int main(){

  vector<int> Input_Vector = {2, 4, 8, 4, 1, 2, 9, 5, 3, 8, 5, 1, 2, 9, 3};
  //vector<int> Input_Vector = {2, 2, 2, 2};
  

  
  cout << "The vector has elements: " << endl;
  for(vector<int>::iterator it = Input_Vector.begin(); it != Input_Vector.end(); it++){
    cout << *it << " ";
  }

  cout << "\n";
  
  Remove_Elements(Input_Vector);
  cout << "Repeating elements have been removed, let's see what the resulting array looks like: ";
  for(vector<int>::iterator it = Input_Vector.begin(); it != Input_Vector.end(); it++){
    cout << *it	<< " ";	
  }

  cout << "\n";

  
  return 0;
}
