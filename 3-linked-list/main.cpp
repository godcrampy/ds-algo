#include <iostream>

#include "SinglyLinkedList.hpp"

using namespace std;

int main(int argc, char const *argv[]) {
  SinglyLinkedList sll;
  sll.push(11);
  sll.push(22);
  sll.push(33);
  sll.push(44);
  sll.removeAtIndex(4);
  sll.printList();
  cout << sll.size() << endl;
  return 0;
}
