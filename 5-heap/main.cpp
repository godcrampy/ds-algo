#include <iostream>
#include <vector>

#include "MaxHeap.hpp"

using namespace std;

int main() {
  MaxHeap m({4, 7, 9, 1, 5, 12, 7, 2});
  // m.insert(4);
  // m.insert(7);
  // m.insert(9);
  // m.insert(1);
  // m.insert(5);
  // m.insert(12);
  // m.insert(7);
  // m.insert(2);
  // m.remove();
  auto v = m.getHeap();
  for (auto i : v) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}