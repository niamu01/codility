// you can use includes, for example:
// #include <algorithm>
#include <climits>
#include <cmath>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
  // area: A*B
  // perimeter: 2(A*B)
  int minimum = INT_MAX;

  for (int A = 1; A <= sqrt(N); ++A) {
    if (N % A == 0) {
      int B = N / A;
      int perimeter = 2 * (A + B);
      minimum = min(minimum, perimeter);
    }
  }

  return minimum;
}