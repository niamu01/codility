// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purpo
// cout << "this is a debug message" << endl;

void rotateArray(vector<int> &A, int K) {
  while (K--) {
    int e = A.back();
    A.pop_back();
    A.insert(A.begin(), e);
  }
  return;
}
vector<int> solution(vector<int> &A, int K) {
  int arrayLength = A.size();

  if (arrayLength == 0) {
    return A;
  }

  K %= arrayLength;
  rotateArray(A, K);
  return A;
}