#include <functional>
#include <vector>

using namespace std;

#pragma once

template <class K, class V>
class HashMap {
 private:
  class Node {
   public:
    K key;
    V value;
    Node* next;
    Node(K key, V val);
    Node();
  };
  int capacity;
  hash<K> hF;
  vector<Node*> v;

 public:
  HashMap(int capacity = 107);
  void set(K key, V val);
  V get(K key);
  bool isKey(K key);
  void remove(K key);
};
