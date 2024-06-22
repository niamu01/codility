// you can use includes, for example:
// #include <algorithm>
#include <climits>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
  int N = A.size();

  vector<int> dp(N, INT_MIN);

  dp[0] = A[0];

  for (int i = 1; i < N; i++) {
    for (int dice = 1; dice <= 6; dice++) {
      if (i - dice >= 0) {
        dp[i] = max(dp[i], dp[i - dice] + A[i]);
      }
    }
  }

  // for (auto e : dp) {
  //     cout << e << " ";
  // }
  // cout << endl;

  return dp[N - 1];
}