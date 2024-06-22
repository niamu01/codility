// you can use includes, for example:
// #include <algorithm>
#include <climits>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A) {
  int maxslice = INT_MIN;
  int ending = INT_MIN;
  bool firstValue = true;

  for (int value : A) {
    if (firstValue) {
      ending = value;
      firstValue = false;
    } else {
      ending = max(value, ending + value);
    }
    maxslice = max(ending, maxslice);
  }

  return maxslice;
}