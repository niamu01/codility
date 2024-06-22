// you can use includes, for example:
// #include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(string& S) {
  // stack
  vector<char> stack;
  int flag = 0;

  for (const char& e : S) {
    if (e == '(' || e == '{' || e == '[') stack.push_back(e);
    if (e == ')' || e == '}' || e == ']') {
      if (stack.empty()) return 0;
      if (stack.back() == '(' && e == ')') flag = 1;
      if (stack.back() == '{' && e == '}') flag = 1;
      if (stack.back() == '[' && e == ']') flag = 1;

      if (flag == 1) {
        stack.pop_back();
        flag = 0;
      }
    }
  }

  if (stack.size() == 0) return 1;
  return 0;
}