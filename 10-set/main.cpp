#include <iostream>

#include "Set.hpp"

using namespace std;

int main() {
  Set s;
  cout << s.size << endl;
  s.insert(5);
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(4);
  s.insert(0);
  cout << s.find(1) << endl;
  cout << s.find(5) << endl;
  cout << s.find(0) << endl;
  cout << s.find(7) << endl;
  cout << s.size << endl;
  s.erase(5);
  cout << s.size << endl;
  cout << s.find(5) << endl;
  cout << s.find(1) << endl;
  cout << s.find(0) << endl;
  cout << s.find(7) << endl;
}