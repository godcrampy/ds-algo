#include <stdexcept>
#include <vector>
#pragma once

using namespace std;

class DisjointSet {
 private:
  class Subset {
   public:
    int parent;
    int rank;

    Subset(int parent = 0, int rank = 0);
  };

  vector<Subset> dS;

 public:
  int capacity;

  DisjointSet(int capacity);
  void join(int a, int b);
  int find(int a);
};