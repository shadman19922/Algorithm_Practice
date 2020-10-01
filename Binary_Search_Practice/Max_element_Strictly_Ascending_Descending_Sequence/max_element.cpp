#include <iostream>
#include <vector>

using namespace std;

int Max_Element(vector<int> &Input){

  int left = 0;
  int right = Input.size() - 1;

  while(left < right - 1){
    int middle = left + (right - left)/2;

    if(Input[left] <= Input[right]) left = middle;
    else right = middle;
  }

  if(Input[left] > Input[right]) return left;
  else return right;
}


int main(){

  vector<int> Some_Numbers = {1, 3, 5, 10, 13, 12, 11};

  cout << "Here's a sequence of strictly ascending and strictly descending numbers concatenated:  "<< endl;

  for(int i = 0; i < Some_Numbers.size(); i++){
    cout << Some_Numbers[i] << " " << endl;
  }

  cout << "\n";
  
  int Result = Max_Element(Some_Numbers);
  cout << "The max element is " << Some_Numbers[Result] << " at location " << Result << endl;
  
  
  
  return 0;
}
