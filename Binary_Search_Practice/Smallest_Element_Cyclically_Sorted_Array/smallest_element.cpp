#include <iostream>
#include <vector>

using namespace std;


int smallest_element_idx(vector<int> &Input){

  int left = 0;
  int right = Input.size() - 1;

  while(left < right - 1){
    int middle = left + (right - left)/2;
    if(Input[middle] < Input[right]) right = middle;
    else if (Input[middle] > Input[left]) left = middle;
  }

  return right;

}

int main(){
  
  vector<int> Some_Numbers = {345, 350, 355, 101, 104, 108, 110, 120, 250};
  cout << "Here are the entries of a cyclically sorted array: " << endl;

  for(int i = 0; i < Some_Numbers.size(); i++){
    cout << Some_Numbers[i] << " ";
  }

  cout << "\n";
    
  int Result = smallest_element_idx(Some_Numbers);

  cout << "The smallest element is: " << Some_Numbers[Result] << " at location: " << Result << endl;
  
  return 0;
}
