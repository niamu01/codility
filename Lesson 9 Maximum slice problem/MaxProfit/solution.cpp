// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
  // 저점에 사서 고점에 팔기
  // 이익 반환
  int size = A.size();

  if (size < 2) return 0;

  int e = 0;
  int s = 0;

  for (int i = 1; i < size; i++) {
    int profix = A[i] - A[i - 1];
    e = max(e + profix, 0);
    s = max(e, s);
  }

  return s;
}