#include <iostream>
#include <string>
#include <vector>

using namespace std;

int longest_common_subsequence_length(string &s1, string &s2){
  vector<vector<int>> Soln_Mtx;

  Soln_Mtx.resize(s1.size());
  for(int i = 0; i < Soln_Mtx.size(); i++){
    Soln_Mtx[i].resize(s2.size());
    for(int j = 0; j < Soln_Mtx[i].size(); j++) Soln_Mtx[i][j] = 0;
  }

  
  bool FoundIdenticalChar = false;

  if(s1[0] == s2[0]){
    Soln_Mtx[0][0] = 1;
    FoundIdenticalChar = true;
  }
  
  //Filling in the first row of the solution matrix
  for(int i = 1; i < Soln_Mtx.size(); i++){
    if(s1[i] == s2[0] && !FoundIdenticalChar){
      FoundIdenticalChar = true;
      Soln_Mtx[i][0] = Soln_Mtx[i-1][0] + 1;
    }
    else Soln_Mtx[i][0] = Soln_Mtx[i - 1][0];
  }

  FoundIdenticalChar = false;
  if(s1[0] == s2[0]){
    FoundIdenticalChar = true;
  }
  
  //Filling in the first column of the soltuion matrix
  for(int j = 1; j < Soln_Mtx[0].size(); j++){
    if(s2[j] == s1[0] && !FoundIdenticalChar){
      FoundIdenticalChar = true;
      Soln_Mtx[0][j] = Soln_Mtx[0][j - 1] + 1;
    }
    else Soln_Mtx[0][j] = Soln_Mtx[0][j - 1];
  }

  //Filling in the remaining elements
  for(int i = 1; i < Soln_Mtx.size(); i++){
    for(int j = 1; j < Soln_Mtx[i].size(); j++){
      if(s1[i] == s2[j]) Soln_Mtx[i][j] = Soln_Mtx[i-1][j-1] + 1;
      else Soln_Mtx[i][j] = max(Soln_Mtx[i-1][j], Soln_Mtx[i][j - 1]);
    }
  }

  //Bottom right most element is the answer
  return Soln_Mtx[s1.size() - 1][s2.size() - 1];
}


int main(){
  string str1 = "abcde";
  string str2 = "ace";

  int Answer = longest_common_subsequence_length(str1, str2);
  cout << "The size of the longest common subsequences '" << str1 << "' and '" << str2 << "' is: " << Answer << endl;
}
