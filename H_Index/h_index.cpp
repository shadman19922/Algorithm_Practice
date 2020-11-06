#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int h_index(vector<int> &Input){
  sort(Input.begin(), Input.end()); //Sorting the input vector

  int idx = Input.size() - 1;
  int counter = 0;
  
  while(counter < Input[idx]){
    if(Input[idx] > ++counter){
      idx--;
      //counter++;
    }

    else if(Input[idx] <= counter) return Input[idx]; 
    

  }

  return Input[idx];

  
}

int main(){

  //vector<int> Some_Numbers = {1, 4, 1, 4, 2, 1, 3, 5, 6};
  vector<int> Some_Numbers = {4, 1, 2, 3, 4, 5, 6, 5, 8};

  
  int Result = h_index(Some_Numbers);

  cout << "The h-index of the given sequence of numbers is: " << Result << endl;
  
  
  return 0;
}
