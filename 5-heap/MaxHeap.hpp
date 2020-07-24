#include <climits>
#include <cstddef>
#include <stdexcept>
#include <vector>

using namespace std;

#pragma once

class MaxHeap {
 private:
  vector<int> h;
  void shiftUp();
  void shiftDown();
  void shiftDown(int i);
  void heapify();

 public:
  MaxHeap();
  MaxHeap(vector<int> v);
  int getMax();
  void insert(int x);
  int remove();
  vector<int> getHeap();
};