#include <bits/stdc++.h>

using namespace std;

#define int long long

class Node {
public:
  int data;
  Node *left, *right;
  Node(int val) {
    this->data = val;
    left = NULL;
    right = NULL;
  }
};

// Preorder traversal
void preorderTraversal(Node* node) {
  if (node == NULL) return;
  cout << node->data << "->";
  preorderTraversal(node->left);
  preorderTraversal(node->right);
}

// Postorder traversal
void postorderTraversal(Node* node) {
  if (node == NULL) return;
  postorderTraversal(node->left);
  postorderTraversal(node->right);
  cout << node->data << "->";
}

// Inorder traversal
void inorderTraversal(Node* node) {
  if (node == NULL) return;
  inorderTraversal(node->left);
  cout << node->data << "->";
  inorderTraversal(node->right);
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  Node* root = new Node(1);
  root->left = new Node(12);
  root->right = new Node(9);
  root->left->left = new Node(5);
  root->left->right = new Node(6);

  cout << "Inorder traversal ";
  inorderTraversal(root);

  cout << "\nPreorder traversal ";
  preorderTraversal(root);

  cout << "\nPostorder traversal ";
  postorderTraversal(root);

  return 0;
}