#include <iostream>

#include "HashMap.hpp"

using namespace std;

int main() {
  HashMap<int, int> hm;
  hm.set(42, 2);
  hm.set(12, 42);
  hm.set(37, 14);
  hm.set(43, 29);

  cout << hm.get(37) << endl;
  cout << hm.isKey(43) << endl;
  hm.remove(43);
  cout << hm.isKey(43) << endl;
  // Expect throw logic_error
  cout << hm.get(43) << endl;
  return 0;
}
