#include <iostream>
#include <vector>

using namespace std;

void MergeArrays(vector<int> &a, vector<int> &b){ //a and b are sorted. a has extra space to take in elements from b
  int i = 0; //Index to keep track of elements in a
  int j = 0; //Index to keep track of elements in b

  //a.resize(a.size() + b.size());
  
  while(i < a.size() && j < b.size()){
    if (a[i] >= b[j]){
      a.insert(a.begin() + i, b[j]);
      j++;
      i++;
    }

    else if(a[i] < b[j]) i++;
  }
  /*
  while(j < b.size()){
    a.push_back(b[j]);
    j++;
  }
  */
  
  

}

int main(){

  vector<int> vect1 = {9, 10, 14};
  vector<int> vect2 = {3, 8, 12, 15};

  MergeArrays(vect1, vect2);

  cout << "The result of the Merge is: " << endl;
  for(int i = 0; i < vect1.size(); i++) cout << vect1[i] << " ";
  cout << "\n";
  
  return 0;
}
