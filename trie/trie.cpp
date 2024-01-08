#include<bits/stdc++.h>

using namespace std;

struct node {
  bool endmark;
  node* next[26 + 1];
  node() {
    endmark = false;
    for (int i = 0; i < 26; i++) {
      next[i] = NULL;
    }
  }
} * root;

void insert(string str, int len) {
  node* curr = root;
  for (int i = 0; i < len; i++) {
    int id = str[i] - 'a';
    if (curr->next[id] == NULL) {
      curr->next[id] = new node();
    }
    curr = curr->next[id];
  }
  curr->endmark = true;
}

bool search(string str, int len) {
  node* curr = root;
  for (int i = 0; i < len; i++) {
    int id = str[i] - 'a';
    if (curr->next[id] == NULL) {
      return false;
    }
    curr = curr->next[id];
  }
  return curr->endmark;
}

void del(node* cur) {
  for (int i = 0; i < 26; i++) {
    if (cur->next[i]) {
      del(cur->next[i]);
    }
  }
  delete (cur);
}

int main() {
  cout << "ENTER NUMBER OF WORDS" << '\n';
  root = new node();
  int num_word;
  cin >> num_word;
  for (int i = 1; i <= num_word; i++) {
    string str;
    cin >> str;
    insert(str, (int)str.size());
  }
  cout << "ENTER NUMBER OF QUERY" << '\n';
  int query;
  cin >> query;
  for (int i = 1; i <= query; i++) {
    string str;
    cin >> str;
    if (search(str, (int)str.size())) {
      cout << "FOUND\n";
    }
    else {
      cout << "NOT FOUND\n";
    }
  }
  del(root); // deleted the trie
  return 0;
}
