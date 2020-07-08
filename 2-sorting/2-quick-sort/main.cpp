#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void quickSort(vector<int>& v, int l, int r) {
  if (l >= r) {
    return;
  }

  int pivot = (rand() % (r - l + 1)) + l;
  int x = v[pivot];

  swap(v[pivot], v[r]);

  int j = l;
  for (int i = l; i < r; ++i) {
    if (v[i] < x) {
      swap(v[i], v[j++]);
    }
  }

  swap(v[j], v[r]);
  quickSort(v, l, j - 1);
  quickSort(v, j + 1, r);
}

void quickSort(vector<int>& v) { quickSort(v, 0, v.size() - 1); }

int main() {
  vector<int> v = {1, 8, 3, 2, 2, 7, 9, 5};

  quickSort(v);

  for (int n : v) {
    cout << n << " ";
  }
  cout << endl;
  return 0;
}
