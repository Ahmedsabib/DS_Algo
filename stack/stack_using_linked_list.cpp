#include <bits/stdc++.h>
using namespace std;

class node {
public:
  int data;
  node* next;
  node* prev;
};

class DoublyLinkedList {
public:
  node* head;
  int sz = 0;
  DoublyLinkedList() {
    head = NULL;
    sz = 0;
  }
  node* CreateNewNode(int data) {
    node *newnode = new node;
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
  }
  // Inserts a node with given data at head
  // O(1)
  void InsertAtHead(int data) {
    ++sz;
    node *newnode = CreateNewNode(data);
    if (head == NULL) {
      head = newnode;
      return;
    }
    node* a = head;
    newnode->next = a;
    a->prev = newnode;
    head = newnode;
  }
  // O(N)
  void Traverse() {
    node* a = head;
    while (a != NULL) {
      cout << a->data << ' ';
      a = a->next;
    }
    cout << '\n';
  }
  // Inserts the given data at the given index
  // O(N)
  void Insert(int index, int data) {
    if (index > sz) {
      return;
    }
    if (index == 0) {
      InsertAtHead(data);
      return;
    }
    node* a = head;
    int cur_index = 0;
    while (cur_index != index - 1) {
      a = a->next;
      ++cur_index;
    }
    // a = cur_index - 1
    node* newnode = CreateNewNode(data);
    newnode->next = a->next;
    newnode->prev = a;
    node* b = a->next;
    b->prev = newnode;
    a->next = newnode;
    ++sz;
  }
  // Returns the size of linked list
  // O(1)
  int getSize() {
    return sz;
  }
  // Deletes the value at head
  // O(1)
  void DeleteAtHead() {
    if (head == NULL) {
      return;
    }
    node *a = head;
    node *b = head->next;
    delete a;
    if (b != NULL) {
      b->prev = NULL;
    }
    head = b;
    --sz;
  }
  // Deletes the given index
  // O(N)
  void Delete(int index) {
    if (index >= sz) {
      return;
    }
    node* a = head;
    int cur_index = 0;
    while (cur_index != index) {
      a = a->next;
      ++cur_index;
    }
    node* b = a->prev;
    node* c = a->next;
    if (b != NULL) {
      b->next = c;
    }
    if (c != NULL) {
      c->prev = b;
    }
    delete a;
    if (index == 0) {
      head = c;
    }
    --sz;
  }
  // Reverse the doubly linked list
  // O(N)
  void Reverse() {
    if (head == NULL) {
      return;
    }
    node* a = head;
    int cur_index = 0;
    while (cur_index != sz - 1) {
      a = a->next;
      cur_index++;
    }
    // last index is in a
    node* b = head;
    while (b != NULL) {
      swap(b->next, b->prev);
      b = b->prev;
    }
    head = a;
  }
};

// Stack using doubly linked list
class Stack {
public:
  DoublyLinkedList dl;
  Stack() {

  }
  int top() {
    if (dl.getSize() == 0) {
      cout << "Stack is empty!\n";
      return -1;
    }
    return dl.head->data;
  }
  void push(int val) {
    dl.InsertAtHead(val);
  }
  void pop() {
    if (dl.getSize() == 0) {
      cout << "Stack is empty!\n";
      return;
    }
    dl.DeleteAtHead();
  }
};

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  Stack st;
  st.push(3);
  cout << st.top() << '\n';
  st.push(4);
  cout << st.top() << '\n';
  st.push(5);
  cout << st.top() << '\n';
  st.pop();
  cout << st.top() << '\n';
  st.pop();
  cout << st.top() << '\n';
  st.pop();
  cout << st.top() << '\n';
  return 0;
}