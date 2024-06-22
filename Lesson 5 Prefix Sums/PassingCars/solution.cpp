// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
  int N = A.size();

  int west = 0;
  int pass = 0;

  for (int i = N - 1; i >= 0; i--) {
    if (A[i] == 1) west++;
    if (A[i] == 0) pass += west;
    if (pass > 1000000000) return -1;
  }

  return pass;
}