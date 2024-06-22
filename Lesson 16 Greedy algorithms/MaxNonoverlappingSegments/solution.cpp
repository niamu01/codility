// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A, vector<int> &B) {
  int N = A.size();
  if (N == 0) return 0;

  vector<pair<int, int>> v(N);

  for (int i = 0; i < A.size(); i++) {
    v[i] = make_pair(B[i], A[i]);
  }
  sort(v.begin(), v.end());  // 끝나는 지점을 기준으로 정렬

  // for (auto& e:v){
  //     cout << e.first << " " << e.second<< endl;
  // }

  int count = 1;

  int last = v[0].first;
  for (int i = 1; i < N; i++) {
    if (v[i].second > last) {  // 2번째 선 부터 시작지점이 겹치지 않으면 선택
      count++;
      last = v[i].first;
    }
  }

  return count;
}
