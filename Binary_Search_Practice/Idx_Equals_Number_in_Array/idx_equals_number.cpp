#include <iostream>
#include <vector>

using namespace std;

int IdxEqualToEntry(vector<int> &Input){

  int l = 0;
  int r = Input.size() - 1;

  while (l < r){
    int m = l + (r - l)/2;
    int result;

    result = m - Input[m];

    if(result == 0) return m;
    else if(result > 0){
      l = m + 1;
    }
    else{
      r = m;
    }
    
  }

  return -1;
}

int main(){

  vector<int> Some_Numbers = {-2, 0, 2, 3, 6, 7, 9};
  int Result = IdxEqualToEntry(Some_Numbers);

  cout << Result << endl;
  
  return 0;
}

