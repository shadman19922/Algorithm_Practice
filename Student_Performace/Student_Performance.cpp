#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void upgrade_performance(vector<int> &Grades){
  vector<int> WhichGrades;
  WhichGrades.resize(Grades.size());
  WhichGrades[0] = 0;
  WhichGrades[WhichGrades.size() - 1] = 0;

  bool GradesNotChanged = false;

  while(!GradesNotChanged){

    GradesNotChanged = true;
    
    for(int idx = 1; idx < Grades.size() - 1; idx++){
      if(Grades[idx - 1] < Grades[idx] && Grades[idx] > Grades[idx + 1]) {WhichGrades[idx] = -1; GradesNotChanged = false;}
      else if(Grades[idx - 1] > Grades[idx] && Grades[idx] < Grades[idx + 1]) {WhichGrades[idx] = 1; GradesNotChanged = false;}
      else WhichGrades[idx] = 0;
    }
    
    for(int idx = 1; idx < Grades.size() - 1; idx++){
      if(WhichGrades[idx] == 1) Grades[idx] += 10;
      else if(WhichGrades[idx] == -1) Grades[idx] -= 10;
      else continue;
    }
    
  }
  
}

int main(){

  vector<int> StudentGrades = {200, 10, 150, 50, 70, 90, 130, 40, 80, 120};
  for(int i = 0; i < StudentGrades.size(); i++){
    cout << StudentGrades[i] << " ";
  }

  cout << "\n Now the students will study and study until they no longer improve" << endl;

  upgrade_performance(StudentGrades);

  cout << "Final Scores are: " << endl;
  for(int i = 0; i < StudentGrades.size(); i++){
    cout << StudentGrades[i] << " ";
  }

  cout << "\n";

    
  return 0;
}
