#include <bits/stdc++.h>

using namespace std;

// Complexity for Searching
// Best Case - O(log n)
// Avarage Case - O(log n)
// Worst Case - O(n)

class node {
public:
  int value;
  node* left;
  node* right;
};

class BST {
public:
  node *root;
  BST() {
    root = NULL;
  }
  node* CreateNewNode(int value) {
    node *newnode = new node;
    newnode->value = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
  }
  void BFS() {
    if (root == NULL) {
      return;
    }
    queue<node*> q;
    q.push(root);
    while (!q.empty()) {
      node* a = q.front();
      q.pop();
      int p = -1, l = -1, r = -1;
      if (a->left != NULL) {
        l = a->left->value;
        q.push(a->left);
      }
      if (a->right != NULL) {
        r = a->right->value;
        q.push(a->right);
      }
      cout << "Node id = " << a->value << " Left child = " << l;
      cout << " Right child = " << r << " Parent id = " << p << '\n';
    }
  }
  void Insert(int value) {
    node* newnode = CreateNewNode(value);
    if (root == NULL) {
      root = newnode;
      return;
    }
    node* cur = root;
    node* prev = NULL;
    while (cur != NULL) {
      if (newnode->value > cur->value) {
        prev = cur;
        cur =   cur->right;
      }
      else {
        prev = cur;
        cur = cur->left;
      }
    }
    if (newnode->value > prev->value) {
      prev->right = newnode;
    }
    else {
      prev->left = newnode;
    }
  }
  bool Search(int value) {
    node* cur = root;
    while (cur != NULL) {
      if (value > cur->value) {
        cur = cur->right;
      }
      else if (value < cur->value) {
        cur = cur->left;
      }
      else {
        return true;
      }
    }
    return false;
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  BST bst;
  bst.Insert(6);
  bst.Insert(4);
  bst.Insert(3);
  bst.Insert(5);
  bst.Insert(7);
  bst.Insert(8);

  bst.BFS();
  cout << bst.Search(1) << '\n';
  cout << bst.Search(7) << '\n';
  
  return 0;
}