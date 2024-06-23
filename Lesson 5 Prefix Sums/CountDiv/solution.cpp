// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int K) {
  int first = ((A % K) == 0) ? A : (A / K + 1);

  if (first > B) return 0;

  return (B / K) - ((A > 0) ? (A - 1) / K : -1);
}
