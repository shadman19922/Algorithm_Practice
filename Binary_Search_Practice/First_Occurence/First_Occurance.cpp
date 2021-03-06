#include <iostream>
#include <vector>

using namespace std;

int Regular_Binary_Search(const vector<int>& input, int Target){
  int l = 0; //Index to the left most element
  int r = input.size() - 1; //Index to the right most element

  //int m = l + (r-l)/2; //index to middle element

  while(l <= r){
    int m = l + (r-l)/2;

    if(input[m] > Target) r = m - 1;
    else if(input[m] < Target) l = m + 1;
    else return m; //input[m] == target
  }

  return -1;
  
}


int Search_First_Element(const vector<int>& input, int Target){
  int right = Regular_Binary_Search(input, Target); //Find an index with the Target element. Either this is the first occurence of Target or The first occurence is to the left of this 
  if(right == -1) return -1;

  int left = 0;
  int middle = left + (right - left)/2;

  //if(right == -1) return -1;
  
  while(left < right - 1){
    int middle = left + (right - left)/2;

    if(input[middle] == Target) right = middle;
    else if(input[middle] < Target) left = middle + 1;
    else cout << "Dafuq???" << endl;
  }

  return left;
}


int main(){

  //const vector<int> Some_Numbers = {-14, -10, 2, 108, 108, 243, 285, 285, 285, 401};
  const vector<int> Some_Numbers = {-20, -20, -13, -7, 0, 0, 8, 12, 14, 14, 14, 19, 19, 22, 22};
  
  cout << "We have a vector with " << Some_Numbers.size() - 1 << " Indices"  << endl;
  cout << "Here's the vector of numbers: " << endl;
  for(int it = 0; it < Some_Numbers.size(); it++){
    cout << Some_Numbers[it] << " ";
  }

  cout << "\n";
  int Number = -13;
  int Answer = Search_First_Element(Some_Numbers, Number);

  cout << "The first occurence of " << Number << " is at idx: " << Answer << endl;
  return 0;
}

