// you can use includes, for example:
#include <algorithm>
#include <numeric>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

bool division(vector<int> &A, int max, int K) {
  int cur = 0;
  int count = 1;

  for (int a : A) {
    if (cur + a > max) {
      cur = a;
      count++;
      if (count > K) {
        return false;
      }
    } else {
      cur += a;
    }
  }
  return true;
}

int solution(int K, int M, vector<int> &A) {
  // M이 최대값

  // K개의 블록으로 배열 자르기 (k=3이어도 [],[],[0:N]으로 잘라도 됨)
  // 블록의 인자들을 다 더했을 때의 값이 가장 작은 경우를 구하기
  // 그 작은 합을 반환

  // 아무튼 k개만큼 자르는게 좋음 (빈배열x)

  // each element of array A is an integer within the range [0..M].
  int lower = *max_element(A.begin(), A.end());  // 나눠진 배열의 최소합
  int upper = accumulate(A.begin(), A.end(), 0);  // 나눠진 배열의 최대합

  int result = upper;

  while (lower <= upper) {
    int mid =
        lower + (upper - lower) / 2;  // 나눠진 배열의 중간값 (이진탐색용pivot)
    if (division(A, mid, K)) {  // 합이 mid보다 작은 배열로 나누면 k개보다 적음
      result = mid;     // k개로 나누기 성공했으니 갱신
      upper = mid - 1;  // 이진탐색
    } else {            // k개보다 많게 나눠야하면
      lower = mid + 1;  // 이진탐색
    }
  }

  return result;
}
