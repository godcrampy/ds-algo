#include <vector>

#include "Graph.hpp"

using namespace std;

void printVector(vector<int> v);
void printVector(vector<pair<int, int>> v);

int main() {
  vector<vector<bool>> m = {

      // {0, 1, 1, 0, 0}, {0, 0, 1, 1, 0}, {0, 0, 0, 0, 0},
      // {0, 0, 0, 0, 1}, {0, 0, 0, 0, 0},
      // {0, 1, 0, 0, 0}, {0, 0, 0, 1, 0}, {1, 1, 0, 0, 0},
      // {0, 0, 0, 0, 1}, {0, 0, 0, 0, 0},
      {0, 1, 0, 0, 0, 0}, {1, 0, 1, 0, 0, 1}, {0, 1, 0, 1, 0, 0},
      {0, 0, 1, 0, 1, 1}, {0, 0, 0, 1, 0, 0}, {0, 1, 0, 1, 0, 0},
  };
  Graph g(m);
  g.printGraph();
  // printVector(g.getEdgesUndirected());
  // printVector(g.bfs(0));
  // printVector(g.dfs(0));
  printVector(g.getBridges());
  // cout << g.containsCycleDFSDirected() << endl;
  // cout << g.containsCycleBFSDirected() << endl;
  // printVector(g.topologicalSortStack());
  // printVector(g.topologicalSortQueue());
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
