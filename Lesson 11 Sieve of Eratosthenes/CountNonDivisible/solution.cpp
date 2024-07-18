// you can use includes, for example:
// #include <algorithm>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool isDivisor(int target, int divide) { return target % divide != 0; }
vector<int> solution(vector<int> &A) {
  // 전체 배열에서 약수가 아닌 수의 개수를 배열로 반환
  vector<int> answer;

  for (int e : A) {
    int count = 0;
    for (int a : A) {
      if (isDivisor(e, a)) {
        count++;
      }
    }
    answer.push_back(count);
  }

  return answer;
}