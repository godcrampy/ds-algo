#include "WGraph.hpp"

WGraph::Node::Node(int val) : val(val) {}

void WGraph::Node::addChild(Node* n, int distance) {
  children.insert({n, distance});
}

void WGraph::Node::removeChild(Node* n) {
  for (auto it = children.begin(); it != children.end();) {
    if (it->first == n) {
      it = children.erase(it);
    } else {
      ++it;
    }
  }
}

void WGraph::Node::clearChildren() { children.clear(); }

bool WGraph::Node::isChild(Node* n) {
  for (auto it = children.begin(); it != children.end();) {
    if (it->first == n) {
      return true;
    }
    ++it;
  }

  return false;
}

WGraph::Edge::Edge(int from, int to, int distance)
    : from(from), to(to), distance(distance) {}

void WGraph::Edge::printEdge() {
  cout << "{" << from << " " << to << ": " << distance << "}" << endl;
}

WGraph::WGraph(vector<vector<int>> matrix) {
  g.clear();
  for (int i = 0; i < matrix.size(); ++i) {
    g.push_back(new Node(i));
  }

  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[i].size(); ++j) {
      if (matrix[i][j]) {
        g[i]->children.insert({g[j], matrix[i][j]});
      }
    }
  }
}

void WGraph::printGraph() {
  for (int i = 0; i < g.size(); ++i) {
    cout << g[i]->val << ": ";
    for (auto n : g[i]->children) {
      cout << "(" << n.first->val << " " << n.second << ") ";
    }
    cout << endl;
  }
}

vector<WGraph::Edge> WGraph::getEdgesUndirected() {
  // assumes undirected graph
  vector<Edge> res;

  for (int i = 0; i < g.size(); ++i) {
    for (auto n : g[i]->children) {
      if (g[i]->val < n.first->val) {
        Edge e(g[i]->val, n.first->val, n.second);
        res.push_back(e);
      }
    }
  }

  return res;
}

vector<WGraph::Edge> WGraph::getEdgesDirected() {
  // assumes undirected graph
  vector<Edge> res;

  for (int i = 0; i < g.size(); ++i) {
    for (auto n : g[i]->children) {
      Edge e(g[i]->val, n.first->val, n.second);
      res.push_back(e);
    }
  }

  return res;
}

vector<WGraph::Edge> WGraph::krushkalsMST() {
  vector<Edge> edges = getEdgesUndirected();
  vector<Edge> res;

  // sort edges by distance
  sort(edges.begin(), edges.end(),
       [](Edge a, Edge b) { return a.distance < b.distance; });

  int n = g.size();
  DisjointSet ds(n);
  for (Edge e : edges) {
    if (ds.find(e.from) != ds.find(e.to)) {
      res.push_back(e);
      ds.join(e.from, e.to);
    }
  }

  return res;
}

int WGraph::_getNextNode(vector<int>& next, vector<bool>& visited) {
  int nextIndex = -1;
  int minVal = INT_MAX;
  for (int i = 0; i < next.size(); ++i) {
    if (!visited[i] && next[i] < minVal) {
      minVal = next[i];
      nextIndex = i;
    }
  }

  return nextIndex;
}

vector<WGraph::Edge> WGraph::primsMST() {
  vector<Edge> res;
  int n = g.size();
  // weights
  vector<int> next(n, INT_MAX - 1);
  // parent
  vector<int> from(n, -1);
  vector<bool> visited(n, false);
  visited[0] = 0;
  unordered_map<Node*, int> nodePos;
  for (int i = 0; i < g.size(); ++i) {
    nodePos[g[i]] = i;
  }

  int nextIndex = 0;

  while ((nextIndex = _getNextNode(next, visited)) != -1) {
    visited[nextIndex] = true;
    if (from[nextIndex] != -1) {
      Edge e(from[nextIndex], nextIndex, next[nextIndex]);
      res.push_back(e);
    }
    for (auto n : g[nextIndex]->children) {
      int childIndex = nodePos[n.first];
      if (!visited[childIndex] && next[childIndex] > n.second) {
        from[childIndex] = nextIndex;
        next[childIndex] = n.second;
      }
    }
  }

  return res;
}

unordered_map<WGraph::Node*, int> WGraph::_nodeToIndex() {
  unordered_map<Node*, int> res;
  for (int i = 0; i < g.size(); ++i) {
    res[g[i]] = i;
  }
  return res;
}

vector<int> WGraph::dijkstras(int start) {
  int n = g.size();
  vector<bool> visited(n, false);
  vector<int> dist(n, INT_MAX);
  dist[start] = 0;
  auto nti = _nodeToIndex();

  unordered_set<int> s;
  int current = start;

  while (true) {
    visited[current] = true;
    for (auto child : g[current]->children) {
      int i = nti[child.first];
      if (!visited[i]) {
        s.insert(i);
        dist[i] = min(dist[i], dist[current] + child.second);
      }
    }

    s.erase(current);
    if (s.empty()) break;

    int minDistance = INT_MAX;
    int minIndex = -1;
    for (auto i : s) {
      if (minDistance > dist[i]) {
        minDistance = dist[i];
        minIndex = i;
      }
    }

    current = minIndex;
  }

  return dist;
}

vector<int> WGraph::bellmanFord(int start) {
  int n = g.size();
  vector<int> dist(n, INT_MAX);
  dist[start] = 0;
  auto edges = getEdgesDirected();

  for (int i = 1; i < n; ++i) {
    for (auto e : edges) {
      dist[e.to] = min(dist[e.to], dist[e.from] + e.distance);
    }
  }

  return dist;
}

vector<vector<int>> WGraph::floydWarshall() {
  int n = g.size();
  vector<vector<int>> res(n, vector<int>(n, INT_MAX));
  auto edges = getEdgesDirected();

  for (int i = 0; i < n; ++i) {
    res[i][i] = 0;
  }
  for (auto e : edges) {
    res[e.from][e.to] = e.distance;
  }

  for (int k = 0; k < n; ++k) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (res[i][k] != INT_MAX && res[k][j] != INT_MAX)
          res[i][j] = min(res[i][j], res[i][k] + res[k][j]);
      }
    }
  }

  return res;
}
