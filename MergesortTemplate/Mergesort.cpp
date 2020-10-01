#include <iostream>
#include <vector>

using namespace std;

//Note that l, m and r refer to vector indices
void Merge(vector<int>& a, int l, int m, int r){
  int i;
  int j;
  int k;

  int n1 = m - l + 1; //Number of elements in the 'left' array
  int n2 = r - m; //Number of elements in the 'right' array

  //Create Temporary vectors
  vector<int> L, R;
  L.resize(n1);
  R.resize(n2);

  //Filling in the temporary vector elements from the main vector
  for(i = 0; i < n1; i++) L[i] = a[l+i];
  for(j = 0; j < n2; j++) R[j] = a[m+1+j];

  i = 0; //First index of first subarray
  j = 0; //Second index of second subarray
  k = l; //Initial index of merged subarray
  //Merging the elements of the two temporary vectors into the main array
  while(i < n1 && j < n2){
    if(L[i] <= R[j]){
      a[k] = L[i];
      i++;
    }

    else{
      a[k] = R[j];
      j++;
    }
    k++;
  }

  //Adding up any elements left in L, if any
  while(i < n1){
    a[k] = L[i];
    i++;
    k++;
  }

  //Adding up any elements left in R, if any
  while(j < n2){
    a[k] = R[j];
    j++;
    k++;
  }
   
}

void MergeSort(vector<int>& a, int l, int r){
  //if (l >= r) return;
  if(l < r){
  int m = (l + r)/2; //Middle point of the input vector
  MergeSort(a, l, m);
  MergeSort(a, m+1, r);

  Merge(a, l, m, r);
  }
}


int main(){
  
  vector<int> SomeNumbers = {3, 5, 1, 6};
  MergeSort(SomeNumbers, 0, SomeNumbers.size() - 1);
  
  for(int i = 0; i < SomeNumbers.size(); i++){
    cout << SomeNumbers.at(i) << " ";
  }
  
  cout << "\n";
  return 0;
}
