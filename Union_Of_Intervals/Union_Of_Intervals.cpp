#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval{
  int Start, End;
  int StartIsClosed, EndIsClosed;

  //Constructor
  Interval(int left, bool lclosed, int right, bool rclosed): Start(left), StartIsClosed(lclosed), End(right), EndIsClosed(rclosed){}
};

int main(){

  return 0;
}
