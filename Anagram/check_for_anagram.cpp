#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool IsAnagram(string &s1, string &s2){
  bool IsItAnagram = true;
  
  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());
  
  int idx1 = 0;
  int idx2 = 0;

  while (idx1 < s1.size() && idx2 < s2.size() && IsItAnagram == true){
    if (s1[idx1] != s2[idx2]){
      IsItAnagram = false;
    }
    
    else{
      idx1++;
      idx2++;
    }
  }
  
  
  return IsItAnagram;

}



int main(){

  string A_string = "peanut";
  string B_string = "nutpea";

  bool AreTheseAnagrams = IsAnagram(A_string, B_string);
  if(AreTheseAnagrams == true) cout << "YES" << endl;
  else cout << "NO" << endl;
  
  
  return 0;
}
