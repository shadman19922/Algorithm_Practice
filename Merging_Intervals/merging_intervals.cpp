#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval{
  int StartPoint, EndPoint;
  //Constructor
  Interval (int left, int right): StartPoint(left), EndPoint(right) {}
};

vector<int> IntervalsCovered(vector<Interval> & BusyTimes, Interval NewInterval){
  //Note that intervals in BusyTimes are disjoint and Sorted in order.

  int leftidx = -1, rightidx = -1; //Holds the index of the left most and right most interval that

  //Pick out the rane of indices that will be merged
  for(int i = 0; i < BusyTimes.size(); i++){
    if(BusyTimes[i].EndPoint >= NewInterval.StartPoint && leftidx == -1) leftidx = i;
    if(NewInterval.EndPoint < BusyTimes[i].EndPoint  && BusyTimes[i].StartPoint <= NewInterval.EndPoint && rightidx == -1) rightidx = i;  
  }

  int leftLimit, rightLimit;

  if(BusyTimes[leftidx].StartPoint <= NewInterval.StartPoint) leftLimit = BusyTimes[leftidx].StartPoint;
  else leftLimit = NewInterval.StartPoint;

  if(BusyTimes[rightidx].EndPoint >= NewInterval.EndPoint) rightLimit = BusyTimes[rightidx].EndPoint;
  else rightLimit = NewInterval.EndPoint;
  
  vector<int> Answer = {leftidx, rightidx};
  return Answer;
  /*  
  BusyTimes.erase(BusyTimes.begin() + leftidx, BusyTimes.begin() + rightidx);
  Interval UnionInterval(leftLimit, rightLimit);
  BusyTimes.insert(BusyTimes.begin() + leftidx, UnionInterval);
  */
}

void MergeInterval(vector<Interval> & BusyTimes, Interval NewInterval){
  //Note that intervals in BusyTimes are disjoint and Sorted in order.
  int leftidx = -1, rightidx = -1; //Holds the index of the left most and right most interval that
  //Pick out the rane of indices that will be merged                                                                                                                                                        
  for(int i = 0; i < BusyTimes.size() && rightidx == -1; i++){
    if(BusyTimes[i].EndPoint >= NewInterval.StartPoint && leftidx == -1) leftidx = i;
    if(NewInterval.EndPoint < BusyTimes[i].EndPoint  && BusyTimes[i].StartPoint <= NewInterval.EndPoint && rightidx == -1) rightidx = i;
  }

  int leftLimit, rightLimit;

  if(BusyTimes[leftidx].StartPoint <= NewInterval.StartPoint) leftLimit = BusyTimes[leftidx].StartPoint;
  else leftLimit = NewInterval.StartPoint;
  
  if(BusyTimes[rightidx].EndPoint >= NewInterval.EndPoint) rightLimit = BusyTimes[rightidx].EndPoint;
  else rightLimit = NewInterval.EndPoint;

  BusyTimes.erase(BusyTimes.begin() + leftidx, BusyTimes.begin() + rightidx + 1);
  cout << "Old Intervals have been removed." << endl;

  for(int i = 0; i < BusyTimes.size(); i++) cout << "[" << BusyTimes[i].StartPoint << ", " << BusyTimes[i].EndPoint << "] ";
    
  
}
  
int main(){
  
  //Example 1
  vector<Interval> GardenerTime;
  /*
  //Example 1
  GardenerTime.push_back(Interval(-4, -1));
  GardenerTime.push_back(Interval(0, 2));
  GardenerTime.push_back(Interval(3, 6));
  GardenerTime.push_back(Interval(7, 9));
  GardenerTime.push_back(Interval(11, 12));
  GardenerTime.push_back(Interval(14, 17));

  Interval AnotherTime(1, 8);
  */
  //Example 2
  GardenerTime.push_back(Interval(-7, -3));
  GardenerTime.push_back(Interval(-1, 1));
  GardenerTime.push_back(Interval(4, 8));
  GardenerTime.push_back(Interval(9, 12));

  Interval AnotherTime(0, 5);
  

  /* //Example 3
  GardenerTime.push_back(Interval(-10, -7));
  GardenerTime.push_back(Interval(-4, -1));
  GardenerTime.push_back(Interval(2, 3));
  GardenerTime.push_back(Interval(4, 7));
  GardenerTime.push_back(Interval(9, 12));

  Interval AnotherTime(-6, 5);
  */
  cout << "The Gardener's time schedule is: " << endl;
  for(int i = 0; i < GardenerTime.size(); i++) cout << "[" << GardenerTime[i].StartPoint << ", " << GardenerTime[i].EndPoint << "] ";

  cout << "A new schedule is added: [" << AnotherTime.StartPoint << ", " << AnotherTime.EndPoint << "]" << endl;
  
  vector<int> Result = IntervalsCovered(GardenerTime, AnotherTime);
  cout << "The interval to be merged is the range: " << Result[0] << " and " << Result[1] << endl;


  MergeInterval(GardenerTime, AnotherTime);
  
  cout << "The new schedule is: " << endl;
  for(int i = 0; i < GardenerTime.size(); i++) cout << "[" << GardenerTime[i].StartPoint << ", " << GardenerTime[i].EndPoint << "] ";
  
  return 0;
}
