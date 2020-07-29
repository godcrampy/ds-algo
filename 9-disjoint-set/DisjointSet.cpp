#include "DisjointSet.hpp"

DisjointSet::Subset::Subset(int parent, int rank)
    : parent(parent), rank(rank) {}

DisjointSet::DisjointSet(int capacity) : capacity(capacity), dS(capacity) {
  for (int i = 0; i < capacity; ++i) {
    Subset s(i);
    dS[i] = s;
  }
}

int DisjointSet::find(int a) {
  if (a < 0 || a >= capacity)
    throw logic_error("Error: union index out of range");

  if (dS[a].parent == a) {
    return a;
  }

  return find(dS[a].parent);
}

void DisjointSet::join(int a, int b) {
  if (a < 0 || b < 0 || a >= capacity || b >= capacity)
    throw logic_error("Error: union index out of range");

  int ar = find(a);
  int br = find(b);

  if (dS[ar].rank < dS[br].rank) {
    dS[ar].parent = br;
  } else if (dS[ar].rank > dS[br].rank) {
    dS[br].parent = ar;
  } else {
    dS[br].parent = ar;
    dS[ar].rank++;
  }
}
