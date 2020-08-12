#include "Set.hpp"

Set::Node::Node(int val) : val(val), left(NULL), right(NULL) {}

Set::Set() : size(0), root(NULL) {}

Set::Node* Set::insert(Node* root, int val) {
  if (root == NULL) {
    ++size;
    return new Node(val);
  }
  if (root->val == val) {
    return root;
  }
  if (root->val > val) {
    root->left = insert(root->left, val);
  } else {
    root->right = insert(root->right, val);
  }
  return root;
}

void Set::insert(int val) { root = insert(root, val); }

bool Set::find(int val) {
  auto it = root;
  while (it) {
    if (it->val == val) return true;
    if (it->val > val)
      it = it->left;
    else
      it = it->right;
  }
  return false;
}

Set::Node* Set::erase(Node* root, int val) {
  if (root == NULL) return NULL;

  if (root->val > val) {
    root->left = erase(root->left, val);
    return root;
  }

  if (root->val < val) {
    root->right = erase(root->right, val);
    return root;
  }

  if (root->left == NULL && root->right == NULL) {
    --size;
    return NULL;
  }

  if (root->left == NULL || root->right == NULL) {
    --size;
    return root->left == NULL ? root->right : root->left;
  }

  int next = getMin(root->right);
  root->val = next;
  root->right = erase(root->right, next);
  return root;
}

int Set::getMin(Node* root) {
  if (root == NULL) return INT_MAX;
  return min(root->val, getMin(root->left));
}

void Set::erase(int val) { root = erase(root, val); }