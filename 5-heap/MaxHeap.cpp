#include "MaxHeap.hpp"

MaxHeap::MaxHeap() {}

MaxHeap::MaxHeap(vector<int> v) {
  h = v;
  heapify();
}

void MaxHeap::heapify() {
  int from = (h.size() - 2) / 2;
  while (from--) {
    shiftDown(from);
  }
}

void MaxHeap::shiftUp() {
  int i = h.size() - 1;
  while (i != 0 && h[(i - 1) / 2] < h[i]) {
    swap(h[i], h[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

void MaxHeap::shiftDown() {
  int i = 0;
  int n = h.size();
  while (2 * i + 1 < n) {
    int left = h[2 * i + 1];
    int right = 2 * i + 2 < n ? h[2 * i + 2] : INT_MIN;
    if (h[i] > max(left, right)) break;

    if (left > right) {
      swap(h[2 * i + 1], h[i]);
      i = 2 * i + 1;
    } else {
      swap(h[2 * i + 2], h[i]);
      i = 2 * i + 2;
    }
  }
}

void MaxHeap::shiftDown(int i) {
  int n = h.size();
  while (2 * i + 1 < n) {
    int left = h[2 * i + 1];
    int right = 2 * i + 2 < n ? h[2 * i + 2] : INT_MIN;
    if (h[i] > max(left, right)) break;

    if (left > right) {
      swap(h[2 * i + 1], h[i]);
      i = 2 * i + 1;
    } else {
      swap(h[2 * i + 2], h[i]);
      i = 2 * i + 2;
    }
  }
}

int MaxHeap::getMax() {
  if (h.size() == 0) throw logic_error("Error: Cannot get max from empty heap");
  return h[0];
}

int MaxHeap::remove() {
  if (h.size() == 0)
    throw logic_error("Error: Cannot remove max from empty heap");
  int res = h[0];
  swap(h[0], h[h.size() - 1]);
  h.pop_back();
  shiftDown();
  return res;
}

void MaxHeap::insert(int x) {
  h.push_back(x);
  shiftUp();
}

vector<int> MaxHeap::getHeap() { return h; }
