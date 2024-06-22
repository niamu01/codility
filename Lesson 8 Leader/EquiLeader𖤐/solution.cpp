// you can use includes, for example:
// #include <algorithm>
#include <climits>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int findLeader(const vector<int>& A) {
  int size = 0;
  int c = 0;
  for (int a : A) {
    if (size == 0) {
      c = a;
      size = 1;
    } else if (c == a) {
      size++;
    } else {
      size--;
    }
  }

  int count = 0;
  for (int a : A) {
    if (a == c) {
      count++;
    }
  }

  if (count > A.size() / 2) return c;
  return INT_MAX;  // not found leader
}

int solution(vector<int>& A) {
  int leader = findLeader(A);

  if (leader == INT_MAX) {
    return 0;  // 미리 예외처리
  }

  int totalLeaderCount = 0;

  int size = A.size();
  vector<int> leaderCount(size, 0);

  // 총 leader의 개수를 누적합으로 구해준다.
  for (int i = 0; i < size; i++) {
    if (A[i] == leader) {
      totalLeaderCount++;
    }
    leaderCount[i] = totalLeaderCount;
  }

  int equiLeaders = 0;

  // 나누기를 기준으로 왼쪽과 오른쪽의 leader 개수를 비교한다.
  for (int i = 0; i < size - 1; i++) {
    int left = leaderCount[i];
    int right = totalLeaderCount - left;
    int sizeLeft = i + 1;
    int sizeRight = size - sizeLeft;

    // 왼쪽과 오른쪽의 leader 개수가 크기의 절반 이상이면 equiLeader로 판단한다.
    if (left > sizeLeft / 2 && right > sizeRight / 2) {
      equiLeaders++;
    }
  }

  return equiLeaders;
}
