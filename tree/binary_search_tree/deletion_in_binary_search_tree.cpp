#include <bits/stdc++.h>

using namespace std;

// Complexity for deletion
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
  void Delete(int value) {
    node* cur = root;
    node* prev = NULL;
    while (cur != NULL) {
      if (value > cur->value) {
        prev = cur;
        cur = cur->right;
      }
      else if (value < cur->value) {
        prev = cur;
        cur = cur->left;
      }
      else {
        break;
      }
    }
    if (cur == NULL) {
      cout << "Value is not present in BST\n";
      return;
    }
    // Case 1: both child is NULL
    if (cur->left == NULL && cur->right == NULL) {
      if (prev->left != NULL && prev->left->value == cur->value) {
        prev->left = NULL;
      }
      else {
        prev->right = NULL;
      }
      delete cur;
      return;
    }
    // Case 2: node has only one child
    if (cur->left == NULL && cur->right != NULL) {
      if (prev->left != NULL && prev->left->value == cur->value) {
        prev->left = cur->right;
      }
      else {
        prev->right = cur->right;
      }
      delete cur;
      return;
    }
    if (cur->left != NULL && cur->right == NULL) {
      if (prev->left != NULL && prev->left->value == cur->value) {
        prev->left = cur->left;
      }
      else {
        prev->right = cur->left;
      }
      delete cur;
      return;
    }
    // Case 3: node has two child
    node *tmp = cur->right;
    while (tmp->left != NULL) {
      tmp = tmp->left;
    }
    int saved = tmp->value;
    Delete(saved);
    cur->value = saved;
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

  // Case 1
  bst.Delete(8);
  bst.BFS();

  cout << '\n';

  // Case 2
  bst.Delete(7);
  bst.BFS();

  // Case 3
  bst.Delete(6);
  bst.BFS();
  
  return 0;
}