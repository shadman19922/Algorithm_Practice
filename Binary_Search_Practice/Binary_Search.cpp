#include <iostream>
#include <vector>

using namespace std;

int BinarySearch(const vector<int> &a, int low, int high, int key){
  if(high < low) return (low-1);

  int mid = (low+high)/2;
  
  
  if(key == a[mid]) return mid;

  else if(key < a[mid]) return BinarySearch(a, low, mid - 1, key);
  else return BinarySearch(a, mid+1, high, key);
}

int main(){

  const vector<int> SomeNumbers = {3, 5, 8, 20, 20, 50, 60};
  cout << BinarySearch(SomeNumbers, 0, SomeNumbers.size() - 1, 2) << endl;
  cout << BinarySearch(SomeNumbers, 0, SomeNumbers.size() - 1, 3) << endl;
  cout << BinarySearch(SomeNumbers, 0, SomeNumbers.size() - 1, 4) << endl;
  cout << BinarySearch(SomeNumbers, 0, SomeNumbers.size() - 1, 20) << endl;
  cout << BinarySearch(SomeNumbers, 0, SomeNumbers.size() - 1, 90) << endl;
  
  
  return 0;
}

