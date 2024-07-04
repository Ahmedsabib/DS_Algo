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
  int rev;
  Deque() {
    head = NULL;
    tail = NULL;
    sz = 0;
    rev = 0;
  }
  node* CreateNewNode(int value) {
    node* newnode = new node;
    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
  }
  void InsertAtTail(int value) {
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
  void InsertAtHead(int value) {
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
  // pushback O(1)
  void push_back(int value) {
    if (rev == 0) {
      InsertAtTail(value);
    }
    else {
      InsertAtHead(value);
    }
  }
  // pushfront O(1)
  void push_front(int value) {
    if (rev == 0) {
      InsertAtHead(value);
    }
    else {
      InsertAtTail(value);
    }
  }
  void DeleteLast() {
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
    --sz;
  }
  void DeleteFirst() {
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
  // popback O(1)
  void pop_back() {
    if (rev == 0) {
      DeleteLast();
    }
    else {
      DeleteFirst();
    }
  }
  // popfront O(1)
  void pop_front() {
    if (rev == 0) {
      DeleteFirst();
    }
    else {
      DeleteLast();
    }
  }
  // front O(1)
  int front() {
    if (sz == 0) {
      cout << "Deque is empty\n";
      return -1;
    }
    if (rev == 0) {
      return head->data;
    }
    else {
      return tail->data;
    }
  }
  // back O(1)
  int back() {
    if (sz == 0) {
      cout << "Deque is empty\n";
      return -1;
    }
    if (rev == 0) {
      return tail->data;
    }
    else {
      return head->data;
    }
  }
  void reverse_deque() {
    if (rev == 0) {
      rev = 1;
    }
    else {
      rev = 0;
    }
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