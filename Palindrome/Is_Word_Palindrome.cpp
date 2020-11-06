#include<iostream>
#include<unordered_map>

using namespace std;

bool IsStringPalindrome(string& Input){
  unordered_map<char, int> char_count;// Mapping that holds the character count of each unique character in the string

  bool IsPalindrome = true;
  
  for(int idx = 0; idx < Input.length(); idx++){
    char s = Input[idx];
    if(char_count.find(s) == char_count.end()) char_count[s] = 1;
    else char_count[s]++;
  }

  bool IsCharCountEven = (Input.size() % 2 == 0); //Checks to see if char count is even or not
  
  //If the char count is even, for the input letter to be a palindrome, each unique character must have even frequency
  if(IsCharCountEven){
    for(unordered_map<char, int>::iterator itr = char_count.begin(); itr != char_count.end(); itr++){
      if(itr->second % 2 != 0){
	IsPalindrome = false;
	break;
      }
    }
    
  }

  //If the char count is odd, Only one unique character can have odd frequency, Every other unique character must have odd frequency
  else{
    int chars_w_odd_freq = 0;
    for(unordered_map<char, int>::iterator itr = char_count.begin(); itr != char_count.end(); itr++){
      if(itr->second % 2 != 0){
	if (chars_w_odd_freq == 0) chars_w_odd_freq++;
	else{
	  IsPalindrome = false;
	  break;
	}

      }

    }
    
  }
  
  return IsPalindrome;
  
}

int main(){

  string RandomString = "code";
  bool IsRandomStringPalinDrome = IsStringPalindrome(RandomString);

  cout << "Random String for this case is: " << RandomString << endl;
  cout << "This random string is a Palindrome: " << boolalpha << IsRandomStringPalinDrome << endl;
  
  
  return 0;
}
