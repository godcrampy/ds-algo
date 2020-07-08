#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void mergeSort(vector<int>& v, int l, int r) {
  if (l >= r) {
    return;
  }

  int m = l + (r - l) / 2;
  mergeSort(v, l, m);
  mergeSort(v, m + 1, r);

  vector<int> temp(v.begin() + l, v.begin() + r + 1);

  int i = l, j = m + 1, k = l;
  while (i <= m || j <= r) {
    int a = i <= m ? temp[i - l] : INT_MAX;
    int b = j <= r ? temp[j - l] : INT_MAX;

    if (a < b) {
      v[k++] = temp[i++ - l];
    } else {
      v[k++] = temp[j++ - l];
    }
  }
}

void mergeSort(vector<int>& v) { mergeSort(v, 0, v.size() - 1); }

int main() {
  vector<int> v = {1, 8, 3, 2, 2, 7, 9, 5};

  mergeSort(v);

  for (int n : v) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}
