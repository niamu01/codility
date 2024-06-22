// you can use includes, for example:
// #include <algorithm>
#include <iostream>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
using namespace std;

int findMaxZeros(const string& S) {
  int maxZeros = 0;
  int count = 0;
  bool counting = false;

  for (char c : S) {
    if (c == '1') {
      if (counting) {
        maxZeros = max(maxZeros, count);
        count = 0;
      } else {
        counting = true;
      }
    } else if (counting) {
      count++;
    }
  }

  return maxZeros;
}

int solution(int N) {
  string binary = "";
  for (int i = N; i > 0; i /= 2) {
    int b = i % 2;

    if (b == 1) {
      binary = '1' + binary;
    } else {
      binary = '0' + binary;
    }
  }

  return findMaxZeros(binary);
}