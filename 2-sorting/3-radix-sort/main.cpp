#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void radixSort(vector<int> &v) {
  queue<int> zero, one;
  for (int j = 0; j < 31; ++j) {
    // vector to set
    for (int n : v) {
      if ((n & (1 << j)) != 0) {
        one.push(n);
      } else {
        zero.push(n);
      }
    }

    int i = 0;
    while (!zero.empty()) {
      v[i++] = zero.front();
      zero.pop();
    }

    // set to vector
    while (!one.empty()) {
      v[i++] = one.front();
      one.pop();
    }
  }
}

int main() {
  vector<int> v = {1, 8, 3, 2, 2, 7, 9, 5};
  radixSort(v);

  for (int n : v) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}