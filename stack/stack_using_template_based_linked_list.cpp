#include <bits/stdc++.h>
using namespace std;

template <class T>
class node {
public:
  T data;
  node* next;
  node* prev;
};

template <class T>
class DoublyLinkedList {
public:
  node<T>* head;
  int sz = 0;
  DoublyLinkedList() {
    head = NULL;
    sz = 0;
  }
  node<T>* CreateNewNode(int data) {
    node<T> *newnode = new node<T>;
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
  }
  // Inserts a node with given data at head
  // O(1)
  void InsertAtHead(T data) {
    ++sz;
    node<T> *newnode = CreateNewNode(data);
    if (head == NULL) {
      head = newnode;
      return;
    }
    node<T>* a = head;
    newnode->next = a;
    a->prev = newnode;
    head = newnode;
  }
  // O(N)
  void Traverse() {
    node<T>* a = head;
    while (a != NULL) {
      cout << a->data << ' ';
      a = a->next;
    }
    cout << '\n';
  }
  // Deletes the value at head
  // O(1)
  void DeleteAtHead() {
    if (head == NULL) {
      return;
    }
    node<T> *a = head;
    node<T> *b = head->next;
    delete a;
    if (b != NULL) {
      b->prev = NULL;
    }
    head = b;
    --sz;
  }
  // Returns the size of linked list
  // O(1)
  int getSize() {
    return sz;
  }
};

// Stack using doubly linked list
template <class T>
class Stack {
public:
  DoublyLinkedList<T> dl;
  Stack() {

  }
  T top() {
    if (dl.getSize() == 0) {
      cout << "Stack is empty!\n";
      assert(false);
    }
    return dl.head->data;
  }
  void push(T val) {
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
  
  Stack<double> st;
  st.push(3.5);
  st.push(3.6);
  st.push(7.8);
  cout << st.top() << '\n';
  st.pop();
  cout << st.top() << '\n';
  st.pop();
  cout << st.top() << '\n';
  st.pop();

  return 0;
}