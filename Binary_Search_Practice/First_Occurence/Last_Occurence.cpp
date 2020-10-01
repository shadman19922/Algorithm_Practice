//Even though I lable the script 'last occurence', the aim is to find the index of the first element greater than the key
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Regular_Binary_Search(vector<int> &input, int Target){
  int l = 0;
  int r = input.size() - 1;

  while(l <= r){
    int m = l + (r-l)/2;

    if(input[m] < Target) l = m + 1;
    else if(input[m] > Target) r = m - 1;
    else return m;
  }

  return -1;
  
}

int Last_Element(vector<int> &input, int Target){
  int left = Regular_Binary_Search(input, Target);
  int right = input.size() - 1;

  if(left == -1) return -1;
  
  while(right > left + 1){
    int middle = left + (right - left)/2;

    if(input[middle] == Target) left = middle;
    else if(input[middle] > Target) right = middle - 1;
    else cout << "Dafuq??" << endl;
  }

  return left;
  
}


int main(){

  //vector<int> Some_Numbers = {1, 2, 3, 4, 5};
  vector<int> Some_Numbers = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
  //vector<int> Some_Numbers = {10, 10, 10, 12, 12};

  cout << "Here are some numbers: " << endl;

  for(int i = 0; i < Some_Numbers.size(); i++){
    cout << Some_Numbers[i] << " ";
  }
  cout << "\n";

  int A_Number = -10;
  int Key = Last_Element(Some_Numbers, A_Number);

  cout << "The last occurence of "  << A_Number <<  " is located in idx " << Key << endl;
  return 0;
}
