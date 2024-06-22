// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int>& A) {
  int maxCounter = N + 1;
  vector<int> v(N, 0);

  int currentMax = 0;
  int lastUpdate = 0;

  for (int i = 0; i < A.size(); i++) {
    int target = A[i];

    if (target == maxCounter) {
      lastUpdate = currentMax;
    } else {
      if (v[target - 1] < lastUpdate) {
        v[target - 1] = lastUpdate + 1;
      } else {
        v[target - 1]++;
      }

      currentMax = max(currentMax, v[target - 1]);
    }
  }
  for (int i = 0; i < N; i++) {
    if (v[i] < lastUpdate) {
      v[i] = lastUpdate;
    }
  }
  return v;
}