// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
  int N = A.size();
  long long sum = (long long)(N + 1) * (N + 2) / 2;

  for (int e : A) {
    sum -= e;
  }

  return (int)sum;
}