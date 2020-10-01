#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
vector<int> Three_Summands(vector<int> &Input, int Target){
  sort(Input.begin(), Input.end());

  int idx_l = 0;
  int idx_r = Input.size() - 1;
  int idx_m = -1;

  vector<int> output = {-1, -1, -1};
  
  while(idx_l < idx_r){ //Outer while loop
    int sum_of_two = Input[idx_l] + Input[idx_r];
    int sum_of_three;
    bool foundSum = false;
    
    if(sum_of_two >= Target) idx_r--; //If the sum of the two current extreme elements is too high, then the right extreme element is too high

    else{
      idx_m = idx_r - 1;
      //if(idx_m == idx_l) idx_l++;
      
      while(idx_m > idx_l){//Innter while loop
	sum_of_three = sum_of_two + Input[idx_m];

	if(sum_of_three == Target){
	  output[0] = Input[idx_l];
	  output[1] = Input[idx_m];
	  output[2] = Input[idx_r];
	  foundSum = true;
	  return output;
	}

	else if (sum_of_three < Target){
	  idx_l++; //If the sum of the three elements falls short of the target, the left extreme element is twoo low
	  sum_of_two = Input[idx_l] + Input[idx_r];
	}

	else{ //sum_of_three > Target
	  idx_m--; //Should move the middle index down a notch if the three element sum is too high
	}
	
      }//End of inner while loop
      
    } //Else conditional statement end for outer while loop

    //if(output[0] == -1) idx_l++;
    if(!foundSum) idx_l++;
    
  }//End of outer while loop

  return output;
  
}
*/
vector<int> Three_Summands(vector<int> &Input, int Target){
  sort(Input.begin(), Input.end());

  int idx_l = 0;
  int idx_r = Input.size() - 1;
  int idx_ml = -1;
  int idx_mr = -1;
  
  vector<int> output = {-1, -1, -1};

  bool foundSum = false;
  
  while(idx_l < idx_r){ //Outer while loop
    int Remainder = Target - Input[idx_l];

    //if(Remainder < 0) idx_r--;

    
    
    idx_ml = idx_l + 1;
    idx_mr = idx_r;

    while(idx_ml < idx_mr){ //Inner while loop
      int sum_of_two = Input[idx_ml] + Input[idx_mr];

      if (sum_of_two < Remainder) idx_ml++;
      else if (sum_of_two > Remainder) idx_mr--;

      else{
	output[0] = Input[idx_l];
	output[1] = Input[idx_ml];
	output[2] = Input[idx_mr];
	foundSum = true;
	return output;
      }
      
    } //End of inner while loop
    
    if(!foundSum) idx_l++;
    
  }//End of outer while loop                                                                                                                                                                                

  return output;

}
    

int main(){

  vector<int> a = {11, 2, 5, 7, 3};
  vector<int> result = Three_Summands(a, 23);

  cout << result[0] << "\n" << result[1] << "\n"  << result[2];
  
  return 0;
}
