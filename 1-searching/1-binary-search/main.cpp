#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int binarySearch(vector<int> v, int n) {
  int l = 0, r = v.size() - 1;

  while (l < r) {
    int m = l + (r - l) / 2;
    if (v[m] > n) {
      r = m - 1;
    } else if (v[m] < n) {
      l = m + 1;
    } else {
      return m;
    }
  }

  return -1;
}

int main() {
  vector<int> v = {2, 5, 6, 9, 13, 15, 15, 28, 30};

  cout << binarySearch(v, 14) << endl;
  cout << binarySearch(v, 28) << endl;
  cout << binary_search(v.begin(), v.end(), 14) << endl;
  cout << lower_bound(v.begin(), v.end(), 14) - v.begin() << endl;
  cout << lower_bound(v.begin(), v.end(), 15) - v.begin() << endl;
  cout << lower_bound(v.begin(), v.end(), 16) - v.begin() << endl;
  cout << upper_bound(v.begin(), v.end(), 14) - v.begin() << endl;
  cout << upper_bound(v.begin(), v.end(), 15) - v.begin() << endl;
  cout << upper_bound(v.begin(), v.end(), 34) - v.begin() << endl;

  return 0;
}
