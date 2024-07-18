// you can use includes, for example:
// #include <algorithm>
#include <unordered_map>
#include <vector>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

using namespace std;

vector<int> solution(vector<int> &A) {
  int N = A.size();
  unordered_map<int, int> count;

  // 1
  for (int i : A) {
    count[i]++;
  }

  // 2
  vector<int> divisors(2 * N + 1, 0);
  for (auto &[i, count] : count) {
    for (int j = i; j <= 2 * N; j += i) {
      divisors[j] += count;
    }
  }

  // 3
  vector<int> answer;
  for (int i : A) {
    answer.push_back(N - divisors[i]);
  }

  return answer;
}