#include "HashMap.hpp"

template <class K, class V>
HashMap<K, V>::Node::Node(K key, V val) : key(key), value(val), next(NULL) {}

template <class K, class V>
HashMap<K, V>::Node::Node() : next(NULL) {}

template <class K, class V>
HashMap<K, V>::HashMap(int capacity)
    : capacity(capacity), v(capacity, new Node()) {}

template <class K, class V>
void HashMap<K, V>::set(K key, V val) {
  int index = hF(key) % capacity;

  Node* n = v[index];
  while (n->next != NULL) {
    n = n->next;
  }

  n->next = new Node(key, val);
}

template <class K, class V>
V HashMap<K, V>::get(K key) {
  int index = hF(key) % capacity;

  Node* n = v[index];

  while (n != NULL) {
    if (n->key == key) {
      return n->value;
    }
    n = n->next;
  }
  throw logic_error("Error: Value for Key not found");
}

template <class K, class V>
bool HashMap<K, V>::isKey(K key) {
  int index = hF(key) % capacity;

  Node* n = v[index];
  n = n->next;

  while (n != NULL) {
    if (n->key == key) {
      return true;
    }
    n = n->next;
  }

  return false;
}

template <class K, class V>
void HashMap<K, V>::remove(K key) {
  if (!isKey(key)) return;

  int index = hF(key) % capacity;
  Node* n = v[index];

  while (n->next->key != key) {
    n = n->next;
  }

  auto temp = n->next;
  n->next = n->next->next;
  delete temp;
}

template HashMap<int, int>::Node::Node(int key, int val);
template HashMap<int, int>::Node::Node();
template HashMap<int, int>::HashMap(int capacity);
template void HashMap<int, int>::set(int key, int val);
template int HashMap<int, int>::get(int key);
template bool HashMap<int, int>::isKey(int key);
template void HashMap<int, int>::remove(int key);
