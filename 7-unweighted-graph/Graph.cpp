#include "Graph.hpp"

Graph::Node::Node(int val) : val(val) {}

void Graph::Node::addChild(Node* n) { children.insert(n); }

void Graph::Node::removeChild(Node* n) { children.erase(n); }

void Graph::Node::clearChildren() { children.clear(); }

bool Graph::Node::isChild(Node* n) {
  return children.find(n) != children.end();
}

Graph::Graph(vector<vector<bool>> matrix) {
  g.clear();
  for (int i = 0; i < matrix.size(); ++i) {
    g.push_back(new Node(i));
  }

  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[i].size(); ++j) {
      if (matrix[i][j]) {
        g[i]->children.insert(g[j]);
      }
    }
  }
}

void Graph::printGraph() {
  for (int i = 0; i < g.size(); ++i) {
    cout << g[i]->val << ": ";
    for (auto n : g[i]->children) {
      cout << n->val << " ";
    }
    cout << endl;
  }
}

vector<int> Graph::bfs(int start) {
  if (start >= g.size() || start < 0)
    throw logic_error("Error: Start index out of range");
  queue<Node*> q;
  unordered_set<Node*> visited;
  vector<int> res;

  q.push(g[start]);
  visited.insert(g[start]);

  while (!q.empty()) {
    Node* top = q.front();
    q.pop();
    res.push_back(top->val);

    for (auto node : top->children) {
      if (visited.find(node) == visited.end()) {
        visited.insert(node);
        q.push(node);
      }
    }
  }

  return res;
}

vector<int> Graph::dfs(int start) {
  if (start >= g.size() || start < 0)
    throw logic_error("Error: Start index out of range");
  stack<Node*> q;
  unordered_set<Node*> visited;
  vector<int> res;

  q.push(g[start]);
  visited.insert(g[start]);

  while (!q.empty()) {
    Node* top = q.top();
    q.pop();
    res.push_back(top->val);

    for (auto node : top->children) {
      if (visited.find(node) == visited.end()) {
        visited.insert(node);
        q.push(node);
      }
    }
  }

  return res;
}

unordered_map<Graph::Node*, int> Graph::_nodeToIndex() {
  unordered_map<Node*, int> res;
  for (int i = 0; i < g.size(); ++i) {
    res[g[i]] = i;
  }
  return res;
}

vector<pair<int, int>> Graph::getEdgesUndirected() {
  // assumes undirected graph
  vector<pair<int, int>> res;

  for (int i = 0; i < g.size(); ++i) {
    for (auto n : g[i]->children) {
      if (g[i]->val <= n->val) {
        res.push_back({g[i]->val, n->val});
      }
    }
  }

  return res;
}

bool Graph::containsCycleBFS() {
  int n = g.size();
  if (n == 0) return false;
  auto nti = _nodeToIndex();
  // -1 => not visited,
  // 0 => visited and in queue
  // 1 => visited and popped off queue
  vector<int> visited(n, -1);
  queue<Node*> q;
  q.push(g[0]);
  visited[0] = 0;

  while (!q.empty()) {
    auto node = q.front();
    int index = nti[node];
    q.pop();
    visited[index] = 1;

    for (auto n : node->children) {
      int i = nti[n];
      // self loop
      if (i == index) return true;
      if (visited[i] == 0) return true;
      if (visited[i] == -1) {
        visited[i] = 0;
        q.push(n);
      }
    }
  }

  return false;
}

bool Graph::containsCycleDFS() {
  int n = g.size();
  if (n == 0) return false;
  auto nti = _nodeToIndex();
  // -1 => not visited,
  // 0 => visited and in stack
  // 1 => visited and popped off stack
  vector<int> visited(n, -1);
  stack<Node*> q;
  q.push(g[0]);
  visited[0] = 0;

  while (!q.empty()) {
    auto node = q.top();
    int index = nti[node];
    q.pop();
    visited[index] = 1;

    for (auto n : node->children) {
      int i = nti[n];
      // self loop
      if (i == index) return true;
      if (visited[i] == 0) return true;
      if (visited[i] == -1) {
        visited[i] = 0;
        q.push(n);
      }
    }
  }

  return false;
}

bool Graph::containsCycleDS() {
  int n = g.size();
  DisjointSet ds(n);
  auto edges = getEdgesUndirected();

  for (auto p : edges) {
    if (ds.find(p.first) == ds.find(p.second)) return true;
    ds.join(p.first, p.second);
  }

  return false;
}

bool Graph::containsCycleDFSDirected() {
  int n = g.size();
  if (n == 0) return false;
  auto nti = _nodeToIndex();
  // -1 => not visited,
  // 0 => visited and in stack
  // 1 => visited and popped off stack
  vector<int> visited(n, -1);
  stack<Node*> s;
  s.push(g[0]);
  visited[0] = 0;

  while (!s.empty()) {
    Node* top = s.top();
    bool inserted = false;
    for (auto n : top->children) {
      int i = nti[n];
      // self loop
      if (n == top) return true;
      if (visited[i] == 0) return true;
      if (visited[i] == -1) {
        visited[i] = 0;
        s.push(n);
        inserted = true;
        break;
      }
    }

    if (!inserted) {
      visited[nti[top]] = 1;
      s.pop();
    }
  }

  return false;
}

bool Graph::containsCycleBFSDirected() {
  return topologicalSortQueue().size() != g.size();
}

void Graph::_topologicalSortStackUtil(int i, vector<int>& res,
                                      vector<bool>& visited,
                                      unordered_map<Node*, int>& nti) {
  visited[i] = true;
  for (auto n : g[i]->children) {
    int index = nti[n];
    if (!visited[index]) {
      _topologicalSortStackUtil(index, res, visited, nti);
    }
  }

  res.push_back(i);
}

vector<int> Graph::topologicalSortStack() {
  int n = g.size();
  vector<int> res;
  vector<bool> visited(n, false);
  auto nti = _nodeToIndex();
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      _topologicalSortStackUtil(i, res, visited, nti);
    }
  }

  reverse(res.begin(), res.end());
  return res;
}

vector<int> Graph::topologicalSortQueue() {
  vector<int> res;
  int n = g.size();
  int indegree[n];
  fill_n(indegree, n, 0);
  auto nti = _nodeToIndex();
  for (auto n : g) {
    for (auto c : n->children) {
      indegree[nti[c]]++;
    }
  }

  queue<int> q;
  for (int i = 0; i < n; ++i) {
    if (indegree[i] == 0) q.push(i);
  }

  while (!q.empty()) {
    int top = q.front();
    q.pop();
    res.push_back(top);

    for (auto child : g[top]->children) {
      int i = nti[child];
      indegree[i]--;
      if (indegree[i] == 0) q.push(i);
    }
  }

  return res;
}

void Graph::_bridgeUtil(int i, vector<bool>& visited, vector<int>& parent,
                        vector<int>& low, vector<int>& disc,
                        vector<pair<int, int>>& res) {
  static int time = 0;
  static auto nti = _nodeToIndex();
  visited[i] = true;
  disc[i] = low[i] = ++time;
  for (auto n : g[i]->children) {
    int j = nti[n];

    if (!visited[j]) {
      parent[j] = i;
      _bridgeUtil(j, visited, parent, low, disc, res);

      low[i] = min(low[i], low[j]);
      if (low[j] > disc[i]) {
        res.push_back({i, j});
      }

    } else if (j != parent[i]) {
      low[i] = min(low[i], disc[j]);
    }
  }
}

vector<pair<int, int>> Graph::getBridges() {
  int n = g.size();
  vector<bool> visited(n, false);
  vector<int> parent(n, -1), low(n, 0), disc(n, 0);
  vector<pair<int, int>> res;
  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      _bridgeUtil(i, visited, parent, low, disc, res);
    }
  }

  return res;
}