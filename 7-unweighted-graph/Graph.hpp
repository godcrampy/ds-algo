#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../9-disjoint-set/DisjointSet.hpp"

using namespace std;

#pragma once

class Graph {
 public:
  class Node {
   public:
    int val;
    unordered_set<Node*> children;

    Node(int val = 0);
    void addChild(Node* n);
    void removeChild(Node* n);
    void clearChildren();
    bool isChild(Node* n);
  };

  vector<Node*> g;
  Graph(vector<vector<bool>> matrix);
  void printGraph();
  vector<int> bfs(int start);
  vector<int> dfs(int start);
  bool containsCycleBFS();
  bool containsCycleDFS();
  bool containsCycleDS();
  vector<pair<int, int>> getEdgesUndirected();
  bool containsCycleDFSDirected();
  bool containsCycleBFSDirected();
  vector<int> topologicalSortStack();
  vector<int> topologicalSortQueue();
  vector<pair<int, int>> getBridges();

 private:
  unordered_map<Node*, int> _nodeToIndex();
  void _topologicalSortStackUtil(int i, vector<int>& res, vector<bool>& visited,
                                 unordered_map<Node*, int>& nti);
  void _bridgeUtil(int i, vector<bool>& visited, vector<int>& parent,
                   vector<int>& low, vector<int>& disc,
                   vector<pair<int, int>>& res);
};