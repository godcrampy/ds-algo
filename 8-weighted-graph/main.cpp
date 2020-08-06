#include <vector>

#include "WGraph.hpp"

using namespace std;

void printVector(vector<int> v);
void printVector(vector<pair<int, int>> v);
void printVector(vector<WGraph::Edge> v);
void printVector(vector<vector<int>> v);

int main() {
  vector<vector<int>> m = {
      // {0, 2, 0, 1, 0}, {2, 0, 4, 2, 0}, {0, 4, 0, 5, 1},
      // {1, 2, 5, 0, 2}, {0, 0, 1, 2, 0},
      {0, 2, 0, 1, 0}, {0, 0, 4, 2, 0}, {0, 0, 0, 0, 0},
      {0, 0, 5, 0, 2}, {0, 0, 1, 0, 0},
  };
  WGraph g(m);
  g.printGraph();
  printVector(g.krushkalsMST());
  cout << endl;
  printVector(g.dijkstras(0));
  printVector(g.bellmanFord(0));
  printVector(g.floydWarshall());
  // printVector(g.bfs(0));
  // printVector(g.dfs(0));
  return 0;
}

void printVector(vector<int> v) {
  for (int i : v) {
    cout << i << " ";
  }
  cout << endl;
}

void printVector(vector<pair<int, int>> v) {
  for (auto i : v) {
    cout << "(" << i.first << ": " << i.second << ") ";
  }
  cout << endl;
}

void printVector(vector<WGraph::Edge> v) {
  for (auto i : v) {
    i.printEdge();
  }
}

void printVector(vector<vector<int>> v) {
  for (auto i : v) {
    printVector(i);
  }
}