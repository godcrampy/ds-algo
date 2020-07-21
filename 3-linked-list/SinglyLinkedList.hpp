#include <cstddef>
#include <iostream>

using namespace std;

#pragma once

class SinglyLinkedList {
 private:
  class Node {
   public:
    int val;
    Node* next;

    Node(int val = 0);
  };

  Node* secondLastElement();

 public:
  Node* head;
  Node* tail;

  SinglyLinkedList(Node* head = NULL);
  void push(int val = 0);
  void printList();
  int pop();
  int size();
  void insertAtIndex(int index, int val = 0);
  int removeAtIndex(int index);
};
