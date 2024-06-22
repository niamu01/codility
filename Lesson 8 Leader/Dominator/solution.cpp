// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
  int c;

  // 맞춰볼 숫자가 있는 상황인지 확인하기 위해 size 선언
  int size = 0;
  for (int a : A) {
    if (size == 0) {
      c = a;
      size = 1;
    } else {
      if (c == a) {
        size++;
      } else {
        size--;
      }
    }
  }
  // The dominator of array A is the value that occurs in more than half of the
  // elements of A.
  int count = 0;
  int index;

  for (int i = 0; i < A.size(); i++) {
    if (A[i] == c) {
      count++;
      index = i;
    }
  }

  if (count > A.size() / 2) return index;

  return -1;
}