#include <iostream>
#include <vector>

using namespace std;

int Min_Cost(vector<int> & Days, vector<int> & Costs){

  vector<int> Solution_Array(Days[Days.size() - 1] + 1, 0);
  //Solution_Array.resize(Days[Days.size() - 1] + 1);

  Solution_Array[0] = 0;
  //Solution_Array[1] = Costs[0];

  int dayidx = 0;
  //int currenttravelday = Days[dayidx];
  int lasttravelledday = 0;
  
  for(int idx = 1; idx < Solution_Array.size(); idx++){
    if(idx != Days[dayidx]){
      Solution_Array[idx] = Solution_Array[idx - 1]; //If I'm not travelling on a day, the cumulative cost of tickets does not rise
      continue;
    }

    else{ //idx == currenttravelday. Basically if I'm travelling on a day listed in the Days array
      Solution_Array[idx] = Solution_Array[idx - 1] + Costs[0]; //I'd at least have to buy a daily pass

      if(idx - lasttravelledday <= 7){ //But I can also look up 7 day passes and see if I can save
	int temp_cost = Solution_Array[idx - 7] + Costs[1];
	if (temp_cost < Solution_Array[idx]) Solution_Array[idx] = temp_cost;
      }

      if(idx - lasttravelledday <= 30){ //And also for 30 day passes!!
	int temp_cost =	Solution_Array[idx - 30] + Costs[2];
        if (temp_cost < Solution_Array[idx]) Solution_Array[idx] = temp_cost;
      }

      lasttravelledday = idx;
      dayidx++;
    }//End of else conditional
    
  } //End of loop over solution array

  /*
  cout << "Here are the elements of the solution array: " << endl;
  for(int idx = 0; idx < Solution_Array.size(); idx++) cout << Solution_Array[idx] << " ";
  cout << "\n";
  */
  
  return Solution_Array[Solution_Array.size() - 1];
  
}

int main(){
  
  //vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
  //vector<int> costs = {2, 7, 15};

  vector<int> days = {1, 2, 3, 8, 12, 15};
  vector<int> costs = {2, 3, 15};

  
  int answer = Min_Cost(days, costs);

  cout << "The minimum cost is: " << answer << endl;
  
  return 0;
}
