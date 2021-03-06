#include <iostream>
#include <vector>

using namespace std;

void Improved_Merge(vector<int> &a, vector<int> &b){
  int i = a.size() - 1; //Index to keep track of elements in a
  int j = b.size() - 1; //Index to keep track of elements in b

  
  a.resize(a.size() + b.size());

  cout << "Here's the a in which all the elements will be merged into. Assume zeroes are just empty blocks" << endl;

  for(int idx = 0; idx < a.size(); idx++){
    cout << a[idx] << " ";
  }

  int write_idx = a.size() - 1;
  
  cout << "\n";
  while(i >= 0 && j >= 0){
    if(a[i] >= b[j]){
      //a.insert(a.begin() + write_idx, a[i]);
      a[write_idx--] = a[i--];
	//i--;
	//write_idx--;
    }

    else{ //a[i] < b[j]
      //a.insert(a.begin() + write_idx, b[j]);
      a[write_idx--] = b[j--];
	//j--;
	//write_idx--;
    }
    
  }

  /*
  while(i >= 0){
    a.insert(a.begin() + write_idx, a[i]);
    i--;
    write_idx--;
    }*/

  while(j >= 0){
    //a.insert(a.begin() + write_idx, b[j]);
    a[write_idx--] = b[j--];
      //j--;
      //write_idx--;
  }  
  
}

int main(){

  vector<int> vect1 = {9, 10, 14};
  vector<int> vect2 = {3, 8, 12, 15};

  Improved_Merge(vect1, vect2);

  cout << "The result of the Merge is: " << endl;
  for(int i = 0; i < vect1.size(); i++) cout << vect1[i] << " ";
  cout << "\n";

  return 0;

  
  return 0;
}
