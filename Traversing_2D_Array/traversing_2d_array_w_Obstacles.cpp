#include<iostream>
#include<vector>

using namespace std;

int Number_of_Ways(vector<vector<int>> & Obstacles){
  vector<vector<int>> Solution_Matrix;
  Solution_Matrix.resize(Obstacles.size());
  for(int i = 0; i < Solution_Matrix.size(); i++) Solution_Matrix[i].resize(Obstacles[0].size()); //Now I have a full allocated matrix

  bool ObstacleFound = false;

  Solution_Matrix[0][0] = 1; //The robot starts from the origin

  //Filling up the first row of the solution matrix
  for(int i = 1; i < Solution_Matrix[0].size(); i++){
    if(Obstacles[0][i] == 1) Solution_Matrix[0][i] = 0;
    else Solution_Matrix[0][i] = Solution_Matrix[0][i - 1];
  }

  //And the first column
  for(int j = 1; j < Solution_Matrix.size(); j++){
    if(Obstacles[j][0] == 1) Solution_Matrix[j][0] = 0;
    else Solution_Matrix[j][0] = Solution_Matrix[j - 1][0];
  }

  for(int i = 1; i < Solution_Matrix[0].size(); i++){
    for(int j = 1; j < Solution_Matrix.size(); j++){
      if(Obstacles[i][j] == 1) Solution_Matrix[i][j] = 0;
      else Solution_Matrix[i][j] = Solution_Matrix[i][j - 1] + Solution_Matrix[i - 1][j];
    }
  }

  return Solution_Matrix[Solution_Matrix.size() - 1][Solution_Matrix[0].size() - 1];
}

int main(){
  //vector<vector<int>> Obstacle_Course = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
  vector<vector<int>> Obstacle_Course = {{0, 1}, {0, 0}};
  
  int Answer = Number_of_Ways(Obstacle_Course);

  cout << "The number of ways the robot can reach the endpoint is: " << Answer << endl;
  
  return 0;
}
