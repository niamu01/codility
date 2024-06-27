// you can use includes, for example:
// #include <algorithm>
#include <cmath>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
  int result = 0;
  int sqrtN = static_cast<int>(sqrt(N));

  for (int i = 1; i <= sqrtN; ++i) {
    if (N % i == 0) {
      if (i == N / i) {
        result += 1;
      } else {
        result += 2;
      }
    }
  }

  return result;
}