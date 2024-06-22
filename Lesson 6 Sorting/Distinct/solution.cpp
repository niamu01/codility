// you can use includes, for example:
// #include <algorithm>
#include <unordered_set>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int>& A) {
  std::unordered_set<int> s;

  for (const auto& e : A) s.insert(e);

  return s.size();
}