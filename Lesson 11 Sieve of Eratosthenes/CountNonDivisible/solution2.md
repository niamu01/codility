```cpp
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A) {
  int N = A.size();
  unordered_map<int, int> count;

// 1
  for (int i : A) {
    count[i]++;
  }

// 2
  vector<int> divisors(2 * N + 1, 0);
  for (auto &[i, count] : count) {
    for (int j = i; j <= 2 * N; j += i) {
      divisors[j] += count;
    }
  }

// 3
  vector<int> answer;
  for (int i : A) {
    answer.push_back(N - divisors[i]);
  }

  return answer;
}
```

A = {3, 1, 2, 3, 6} <br>
N = A.size() = 5 <br>
예상 출력 값: [2, 4, 3, 2, 0] <br>

> 💡 3은 2를 반환한다. 이 계산을 두 번할 필요 없다. <br>

1. count 라는 이름의 map 에 몇 번 언급되었는지 기록해준다. <br>
```cpp
count = {
	{3, 2},
	{1, 1},
	{2, 1},
	{6, 1},
}
```

2. divisors 라는 vector 에 전체(N)의 2배되는 칸을 마련한다 (인덱스 0번째 칸은 사용 x) <br>
> Q. 왜 2배칸을 마련하는가? <br>
A. each element of array A is an integer within the range [1..2 * N].
```cpp
divisors = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
```
이 칸에 인덱스 숫자의 약수의 개수를 담는다. <br>

예를들어, divisors[4] 에는 `3, 1, 2, 3, 6` 중 에서 `1` 에서 한 번, `2`에서 한 번 추가하여 총 2가 담길 것이다. <br>

> 💡 위에서 언급했듯, <br>
3에 대한 계산을 두 번 하지 않기 위해 우리는 count라는 map을 만들어 활용하였다. <br>

divisors[6] 에는, `3, 1, 2, 3, 6` 중 에서 <br>
`3` 에서 두 번, <br>
`1` 에서 한 번, <br>
`2` 에서 한 번, <br>
`6` 에서 한 번 <br>
담겨 총 5를 가지게 될 것이다. <br>

이 과정 이후의 divisors 의 상태는 다음과 같을 것이다.
```cpp
divisors = {0, 1, 2, 3, 2, 1, 5, 1, 2, 3, 2}
```

3. 이제 `N - divisors[i]` 가 구하려던 약수가 아닌 수들의 개수이다. (전체 - 약수의 개수)