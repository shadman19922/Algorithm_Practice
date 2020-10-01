#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b){
  return (a.second < b.second);
}

int MinCameras(vector<pair<int, int>> &Intervals){
  sort(Intervals.begin(), Intervals.end(), sortbysec);

  int endpoint = Intervals[0].second;
  int numcameras = 1;

  for(int i = 1; i < Intervals.size(); i++){
    if(Intervals[i].first > endpoint){ //If the start point of the ith interval is past the current end point
      numcameras++;                   //Need an extra camera
      endpoint = Intervals[i].second; //Also, need a new end point 
    } 
  }

  return numcameras;

}


int main(){

  int NRobots;
  cin >> NRobots;

  vector<pair<int,int>> Segments;

  for(int n = 0; n < NRobots; n++){
    int x1, x2;  
    cin >> x1 >> x2;

    if(x1 >= x2){
      cout << "Invalid Segment" << endl;
      n--;
    }
    
    else Segments.push_back(make_pair(x1, x2));

  }


  int answer = MinCameras(Segments);
  cout << answer << endl;

  
  return 0;
}
