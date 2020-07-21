#include "SinglyLinkedList.hpp"

SinglyLinkedList::Node::Node(int val) : val(val), next(NULL) {}

SinglyLinkedList::SinglyLinkedList(Node* head) : head(head) {}

// @works
void SinglyLinkedList::push(int val) {
  Node* node = new Node(val);
  if (head == NULL) {
    head = node;
  } else {
    tail->next = node;
  }
  tail = node;
}

// @works
void SinglyLinkedList::printList() {
  auto i = head;
  while (i != NULL) {
    cout << i->val << " ";
    i = i->next;
  }
  cout << endl;
}

// @works
int SinglyLinkedList::pop() {
  if (head == NULL) {
    throw logic_error("Error: Cannot pop from empty list");
  }

  if (head == tail) {
    int res = head->val;
    head = NULL;
    tail = NULL;
    return res;
  }

  Node* temp = secondLastElement();
  int res = tail->val;
  tail = temp;
  temp->next = NULL;
  return res;
}

// @works
SinglyLinkedList::Node* SinglyLinkedList::secondLastElement() {
  if (head == NULL || head == tail) {
    throw logic_error(
        "Error: List length less than two. cannot fetch second last element");
  }

  Node* temp = head;
  while (temp->next != tail) {
    temp = temp->next;
  }

  return temp;
}

// @works
int SinglyLinkedList::size() {
  auto temp = head;
  int size = 0;
  while (temp != NULL) {
    temp = temp->next;
    ++size;
  }

  return size;
}

// @works
void SinglyLinkedList::insertAtIndex(int index, int val) {
  if (index < 0 || index > size()) {
    throw logic_error("Error: Index out of bounds");
  }
  Node* d = new Node();
  Node* n = new Node(val);
  Node* i = d;
  d->next = head;
  while (index--) {
    i = i->next;
  }
  n->next = i->next;
  i->next = n;

  head = d->next;
}

// @works
int SinglyLinkedList::removeAtIndex(int index) {
  if (index < 0 || index >= size()) {
    throw logic_error("Error: Index out of bounds");
  }
  Node* d = new Node();
  d->next = head;
  Node* i = d;
  while (index--) {
    i = i->next;
  }
  Node* del = i->next;
  int res = del->val;
  i->next = i->next->next;
  delete del;
  head = d->next;
  return res;
}
