#include <algorithm>
#include <vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool canNailedAllPlanks(vector<int> &A, vector<int> &B, vector<int> &C,
                        int max) {
  int plank = A.size();
  int maxPosition =
      *max_element(C.begin(), C.end());  // C의 최대값을 기반으로 최대 위치 계산

  // 못 위치에 따른 개수 누적합
  vector<int> prefixNails(maxPosition + 1, 0);

  for (int i = 0; i < max; i++) {  // 못 위치 설정
    prefixNails[C[i]] = 1;
  }

  for (int i = 1; i <= maxPosition; i++) {  // 누적합 계산
    prefixNails[i] += prefixNails[i - 1];
  }

  for (int i = 0; i < plank;
       i++) {  // 누적합-누적합 (판자가 모두 고정되었는지 확인)
    if (prefixNails[B[i]] - prefixNails[A[i] - 1] == 0) return false;
  }

  return true;
}

int solution(vector<int> &A, vector<int> &B, vector<int> &C) {
  // 중간값 J를 통해 J개의 못으로 모든 판자를 박을 수 있는지 확인(이진탐색)
  int left = 1;
  int right = C.size();
  int result = -1;

  // 이진탐색
  while (left <= right) {
    int mid = left + (right - left) / 2;

    if (canNailedAllPlanks(A, B, C, mid)) {
      result = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return result;
}