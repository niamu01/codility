// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int X, int Y, int D) {
  if (X == Y) {
    return 0;
  }

  int dis = Y - X;
  int answer = dis / D;

  if (dis % D > 0) {
    answer++;
  }

  return answer;
}