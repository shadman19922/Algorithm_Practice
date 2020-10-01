#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int> &a, int l, int m, int r){

  //Creating two vectors to hold each half
  vector<int> LeftHalf, RightHalf;
  int n1 = (m - l + 1); //Number of elements in the Left subdivision
  int n2 = r - m; //Number of elements in the Right Subdivision
  LeftHalf.resize(n1);
  RightHalf.resize(n2); 


  int idx1, idx2; //Indices for each subvector;
  int idxmain = l; //Index used to access elements out the main vector
  ////Copying the elements into the subvectors
  //Left Half
  for(idx1 = 0; idx1 < LeftHalf.size(); idx1++){
    LeftHalf[idx1] =  a[idxmain];
    idxmain++;
  }

  //Right Half
  for(idx2 = 0; idx2 < RightHalf.size(); idx2++){
    RightHalf[idx2] = a[idxmain];
    idxmain++;
  }

  idx1 = 0;
  idx2 = 0; //Resetting the indices
  idxmain = l;

  //Comparing the left most elements of each subvector and changing the elements of the main vector in order of ascending number from both vectos together
  while(idx1 < n1 && idx2 < n2){
    //If the left most elements of the left vector is less
    if(LeftHalf[idx1] <= RightHalf[idx2]){
      a[idxmain] = LeftHalf[idx1];
      idx1++; idxmain++;
    }

    //If the right most element of the right vector is less
    else{
      a[idxmain] = RightHalf[idx2];
      idx2++; idxmain++;
    }
  }

  //If there are elements stil left in the left vector
  while(idx1 < n1){
    a[idxmain] = LeftHalf[idx1];
      idx1++; idxmain++;
  }

  while(idx2 < n2){
    a[idxmain] = RightHalf[idx2];
    idx2++; idxmain++;
  }
  
} //End of Merge Function


void MergeSort(vector<int> &a, int l, int r){
  if(r > l){
    int m = (l + r)/2; //Finding the middle point of the array
  MergeSort(a, l, m); //Sorting the left half of the array
  MergeSort(a, m+1, r); //Sorting the right half of the array
  Merge(a, l, m, r);
  }
}



int main(){

  vector<int> SomeNumbers = {3, 5, 1, 3, 8, 3, 9, 10, 12, 8, 1, 5, 9, 12};
  cout << "The elements in the unsorted array are: " << endl;
  for(int i = 0; i < SomeNumbers.size(); i++) cout << SomeNumbers[i] << " ";
  cout << "\n";
  
  MergeSort(SomeNumbers, 0, SomeNumbers.size() - 1);

  cout << "The elements in the sorted array are: " <<	endl;
  for(int i = 0; i < SomeNumbers.size(); i++) cout << SomeNumbers[i] << " ";
  cout << "\n";
    
  return 0;
}
