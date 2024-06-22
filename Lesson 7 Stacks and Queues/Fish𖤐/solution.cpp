// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
  vector<int> v;
  int alive = 0;
  for (int i = 0; i < B.size(); i++) {
    if (B[i] == 1) {
      v.push_back(A[i]);
    } else {
      // if 와 while 순서 변경
      while (!v.empty()) {
        if (A[i] < v.back())
          break;
        else {
          v.pop_back();
          // alive++;
        }
      }
      if (v.empty()) {
        alive++;
      }
    }
  }
  return alive + v.size();
}