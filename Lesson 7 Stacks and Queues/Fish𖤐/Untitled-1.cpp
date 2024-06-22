#include <iostream>
#include <vector>
using namespace std;
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

int main() {
  vector<int> A = {4, 3, 2, 1, 5};
  vector<int> B = {0, 1, 0, 0, 0};
  cout << solution(A, B) << endl;  // 2
  return 0;
}