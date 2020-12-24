#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Class to keep track of event time and type (start/end)
struct Time{
  //public:
  int time;
  bool IsEnd;
};

//Class to hold a job structure
struct ScheduledJob{
  //public:
  Time StartTime;
  Time EndTime;

  int Profit;

  int GetStartTime(){return StartTime.time;}
  int GetEndTime(){return EndTime.time;}
  
  ScheduledJob(int st, int et, int pr){
    Profit = pr;
    StartTime.time = st;
    StartTime.IsEnd = false;

    EndTime.time = et;
    EndTime.IsEnd = true;
  }
  
};

//Sorting funnction for sorting ScheduledJobs
bool SortByTime(ScheduledJob &a, ScheduledJob &b){
  if(a.GetEndTime() == b.GetEndTime()) return a.GetStartTime() < b.GetStartTime();
  else return a.GetEndTime() < b.GetEndTime();
}

//Find the first instance of a job with end time K
int JobLocation(vector<ScheduledJob>& SortedJobs, int K){
  int l = 0;
  int r = SortedJobs.size() - 1;

  int m = l + (r - l)/2;
  int BinSearchIdx = -1;

  //First Binary Search
  while(l <= r && BinSearchIdx == -1){
    if(SortedJobs[m].EndTime.time == K) BinSearchIdx = m;

    else if (K < SortedJobs[m].EndTime.time){
      r = m - 1;
    }
    
    else{ // K > SortedJobs[m].EndTime.time
      l = m + 1;
    }
    
    m = l + (r - l)/2;
  }//End of first binary search

  if(BinSearchIdx == -1) return -1; //If Bin seach index isn't allocated by this point, the element does not exist
  
  l = 0;
  r = BinSearchIdx;

  //Secondary binary search to narrow down on the first occurence of the event with endtime K
  while(l < r - 1){
    m = l + (r - l)/2;
    if(K > SortedJobs[m].EndTime.time) l = m + 1;
    else if(K == SortedJobs[m].EndTime.time) r = m;
    else cout << "DaFuq??!!" << endl;
  }

  //l now holds the index of first occurence
  return r;
}

//////////////////////Main Function
int MaximizeProfit_FromJobs(vector<int> &StartTimes, vector<int> &EndTimes, vector<int> &Profits){
  if(StartTimes.size() != Profits.size()) return -1;
  if(EndTimes.size() != Profits.size()) return -1;


  vector<ScheduledJob> ListedJobs;
  for(int i = 0; i < StartTimes.size(); i++) ListedJobs.push_back(ScheduledJob(StartTimes[i], EndTimes[i], Profits[i]));
  sort(ListedJobs.begin(), ListedJobs.end(), SortByTime);//Sorts the jobs

  int MaxTime = ListedJobs[ListedJobs.size() - 1].GetEndTime(); // Grabs the last possible time in the jobs
  //cout << "The maximum time is: "<< MaxTime << endl;
  
  vector<int> Solution_Array(MaxTime + 1, 0); //Dynamic Programming array used for soltuion building. Extra element (+1) so that I can 1-index this
  int max_profit = 0;
  Solution_Array[0] = 0;

  for(int Hour = 1; Hour <= MaxTime; Hour++){//Hour is the index to keep track of time
    int FirstJobEndingAtHour = JobLocation(ListedJobs, Hour); //Find the first job stored in Jobs that ends at time Hour
    if(FirstJobEndingAtHour == -1){
      Solution_Array[Hour] = max_profit;
      continue;
    }
        
    for(int Job = FirstJobEndingAtHour; ListedJobs[Job].GetEndTime() == Hour; Job++){
      max_profit = max(max_profit, Solution_Array[ListedJobs[Job].GetStartTime()] + ListedJobs[Job].Profit);
    }
    Solution_Array[Hour] = max_profit;
  }
  
  return Solution_Array[Solution_Array.size() - 1];
}




int main(){
  //An example
  vector<int> sTimes = {3, 2, 1, 4};
  vector<int> eTimes = {7, 4, 5, 6};
  vector<int> Monies = {60, 30, 60, 40};
  
  int MaxMoney = MaximizeProfit_FromJobs(sTimes, eTimes, Monies);
  cout << "The maximum amount of money made is: " << MaxMoney << endl;
  
  return 0;
}
