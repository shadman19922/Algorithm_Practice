#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int Reverse_Digits(int Target){
  int counter1 = 1;
  int counter2 = 10;

  vector<int> Target_Digits;

  int ADigit; //Will be used to hold the individual Digits in Target
  ADigit = Target % counter2;
  Target_Digits.push_back(ADigit);

  counter1 *= 10;
  counter2 *= 10;
  
  while (Target >= counter2){
    int AnotherDigit = Target % counter2;
    ADigit = AnotherDigit / counter1;
    Target_Digits.push_back(ADigit);
    counter1 *= 10;
    counter2 *= 10;
  }

  ADigit = Target/counter1;
  Target_Digits.push_back(ADigit);

  reverse(Target_Digits.begin(), Target_Digits.end());

  int reversed_digit = 0;
  
  for(int idx = 0, counter = 1; idx < Target_Digits.size(); idx++, counter *= 10){
    reversed_digit += Target_Digits[idx] * counter;
  }

  return reversed_digit;
  
}


int main(){

  int ANumber = 123123123;
  cout << "The target integer is: " << ANumber << endl;

  int Reversed_Number = Reverse_Digits(ANumber);

  cout << "The target integer, with reversed digits: " << Reversed_Number << endl;
  
  return 0;
}
