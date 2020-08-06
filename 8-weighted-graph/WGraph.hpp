#include <algorithm>
#include <climits>
#include <iostream>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../9-disjoint-set/DisjointSet.hpp"

#pragma once

using namespace std;

class WGraph {
 public:
  class Node {
   public:
    int val;
    // cannot use unorderd_set due to hashing problem
    set<pair<Node*, int>> children;

    Node(int val = 0);
    void addChild(Node* n, int distance);
    void removeChild(Node* n);
    void clearChildren();
    bool isChild(Node* n);
  };

  class Edge {
   public:
    int from;
    int to;
    int distance;
    Edge(int from, int to, int distance);
    void printEdge();
  };

  vector<Node*> g;
  WGraph(vector<vector<int>> matrix);
  void printGraph();
  vector<WGraph::Edge> getEdgesDirected();
  vector<WGraph::Edge> getEdgesUndirected();
  vector<WGraph::Edge> krushkalsMST();
  vector<WGraph::Edge> primsMST();
  vector<int> dijkstras(int start);
  vector<int> bellmanFord(int start);
  vector<vector<int>> floydWarshall();

 private:
  int _getNextNode(vector<int>& next, vector<bool>& visited);  // prims util
  unordered_map<Node*, int> _nodeToIndex();
};
