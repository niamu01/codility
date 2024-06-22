// you can use includes, for example:
// #include <algorithm>
#include <unordered_map>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A) {
  unordered_map<int, int> m = {};

  for (const auto& e : A) {
    m.insert(make_pair(e, 0));
    m[e]++;
  }

  for (const auto& e : m) {
    if (e.second % 2 == 1) {
      return e.first;
    }
  }

  return 0;
}