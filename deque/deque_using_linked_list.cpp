#include <bits/stdc++.h>
using namespace std;

class node {
public:
  int data;
  node* prev;
  node* next;
};

class Deque {
public:
  node* head;
  node* tail;
  int sz;
  Deque() {
    head = NULL;
    tail = NULL;
    sz = 0;
  }
  node* CreateNewNode(int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
  }
  // pushback O(1)
  void push_back(int value) {
    node* newnode = CreateNewNode(value);
    if (sz == 0) {
      head = newnode;
      tail = newnode;
      ++sz;
      return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    ++sz;
  }
  // pushfront O(1)
  void push_front(int value) {
    node* newnode = CreateNewNode(value);
    if (sz == 0) {
      head = newnode;
      tail = newnode;
      ++sz;
      return;
    }
    head->prev = newnode;
    newnode->next = head;
    head = newnode;
    ++sz;
  }
  // popback O(1)
  void pop_back() {
    if (sz == 0) {
      cout << "Deque is empty\n";
      return;
    }
    if (sz == 1) {
      delete tail;
      head = NULL;
      tail = NULL;
      --sz;
      return;
    }
    node* a = tail;
    tail = tail->prev;
    delete a;
    tail->next = NULL;
    sz--;
  }
  // popfront O(1)
  void pop_front() {
    if (sz == 0) {
      cout << "Deque is empty\n";
      return;
    }
    if (sz == 1) {
      delete tail;
      head = NULL;
      tail = NULL;
      --sz;
      return;
    }
    node* a = head;
    head = head->next;
    delete a;
    head->prev = NULL;
    --sz;
  }
  // front O(1)
  int front() {
    if (sz == 0) {
      cout << "Deque is empty\n";
      return -1;
    }
    return head->data;
  }
  // back O(1)
  int back() {
    if (sz == 0) {
      cout << "Deque is empty\n";
      return -1;
    }
    return tail->data;
  }
};

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  Deque d;
  d.push_back(5);
  d.push_back(10);
  d.push_back(15);
  cout << "Back : " << d.back() << " Front : " << d.front() << '\n';
  d.push_back(20);
  cout << "Back : " << d.back() << " Front : " << d.front() << '\n';
  d.pop_front();
  cout << "Back : " << d.back() << " Front : " << d.front() << '\n';
  d.pop_back();
  cout << "Back : " << d.back() << " Front : " << d.front() << '\n';

  return 0;
}