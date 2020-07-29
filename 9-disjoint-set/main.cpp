#include <iostream>

#include "DisjointSet.hpp"

using namespace std;

int main() {
  DisjointSet ds(10);

  ds.join(2, 1);
  ds.join(4, 3);
  ds.join(8, 4);
  ds.join(9, 3);
  ds.join(6, 5);
  cout << ds.find(9) << endl;
  cout << ds.find(8) << endl;
  cout << ds.find(2) << endl;
  return 0;
}