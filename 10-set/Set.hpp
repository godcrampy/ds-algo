#include <algorithm>
#include <climits>
#include <cstddef>
#pragma once

using namespace std;

class Set {
 private:
  class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node(int val);
  };
  Node* insert(Node* root, int val);
  Node* erase(Node* root, int val);
  int getMin(Node* root);

 public:
  int size;
  Node* root;
  Set();
  void insert(int val);
  bool find(int val);
  void erase(int val);
};