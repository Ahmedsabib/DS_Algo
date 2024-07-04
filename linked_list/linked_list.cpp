#include <bits/stdc++.h>
using namespace std;
class node {
public:
  int data;
  node *next;
};
class LinkedList {
public:
  node *head;
  int sz;
  LinkedList() {
    head = NULL;
    sz = 0;
  }
  // Creates a new node with data = value and next = NULL
  node* CreateNewNode(int value) {
    node *newnode = new node;
    newnode->data = value;
    newnode->next = NULL;
    return newnode;
  }
  // Insert new value at head
  void InsertAtHead(int value) {
    ++sz;
    node *a = CreateNewNode(value);
    if (head == NULL) {
      head = a;
      return;
    }
    // If head is not NULL
    a->next = head;
    head = a;
  }
  // Prints the linked list
  void Traverse() {
    node *a = head;
    while (a != NULL) {
      cout << a->data << ' ';
      a = a->next;
    }
    cout << '\n';
  }
  // Search for single value
  int SearchDistinctValue(int value) {
    node *a = head;
    int index = 0;
    while (a != NULL) {
      if (a -> data == value) {
        return index;
      }
      a = a->next;
      ++index;
    }
    return -1;
  }
  // Search all possible occurance
  void SearchAllValue(int value) {
    node* a = head;
    int index = 0;
    while (a != NULL) {
      if (a->data == value) {
        cout << value << " is found at index " << index << '\n';
      }
      a = a->next;
      ++index;
    }
  }
  int getSize() {
    // O(N) [Not necessary]
    // int sz = 0;
    // node *a = head;
    // while (a != NULL) {
    //   sz++;
    //   a = a->next;
    // }
    // return sz;

    // O(1) [Optimized]
    return sz;
  }
  // O(N)
  void InsertAtAnyIndex(int index, int value) {
    if (index < 0 || index > sz) {
      return;
    }
    if (index == 0) {
      InsertAtHead(value);
      return;
    }
    ++sz;
    node *a = head;
    int cur_index = 0;
    while (cur_index != index - 1) {
      a = a->next;
      ++cur_index;
    }
    node *newnode = CreateNewNode(value);
    newnode->next = a->next;
    a->next = newnode;
  }
  // O(1)
  void DeleteAtHead() {
    if (head == NULL) {
      return;
    }
    --sz;
    node *a = head;
    head = a->next;
    delete a;
  }
  // O(N)
  void DeleteAnyIndex(int index) {
    if (index < 0 || index > sz - 1) {
      return;
    }
    if (index == 0) {
      DeleteAtHead();
      return;
    }
    --sz;
    node *a = head;
    int cur_index = 0;
    while (cur_index != index - 1) {
      a = a->next;
      cur_index++;
    }
    node *b = a->next;
    a->next = b->next;
    delete b;
  }
  void InsertAfterValue(int value,int data) {
    node *a = head;
    while (a != NULL) {
      if (a->data == value) {
        break;
      }
      a = a->next;
    }
    if (a == NULL) {
      cout << value << "doesn't exist in the linked list\n";
      return;
    }
    ++sz;
    node *newnode = CreateNewNode(data);
    newnode->next = a->next;
    a->next = newnode;
  }
  void ReversePrint2(node* a) {
    if (a == NULL) {
      return;
    }
    ReversePrint2(a->next);
    cout << a->data << ' ';
  }
  void ReversePrint() {
    ReversePrint2(head);
  }
};
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  LinkedList l;
  l.Traverse();
  l.InsertAtHead(10);
  l.Traverse();
  l.InsertAtHead(30);
  l.Traverse();
  l.InsertAtHead(20);
  l.Traverse();
  l.InsertAtHead(30);
  l.Traverse();
  cout << "10 is found at " << l.SearchDistinctValue(10) << '\n';
  cout << "5 is found at " << l.SearchDistinctValue(50) << '\n';
  cout << "30 is found at " << l.SearchDistinctValue(30) << '\n';
  cout << l.getSize() << '\n';
  l.InsertAtAnyIndex(1, 100);
  l.InsertAtAnyIndex(4, 200);
  l.Traverse();
  cout << l.getSize() << '\n';
  l.DeleteAtHead();
  l.Traverse();
  cout << l.getSize() << '\n';
  l.DeleteAnyIndex(2);
  l.Traverse();
  cout << l.getSize() << '\n';
  l.InsertAfterValue  (20, 100);
  l.Traverse();
  cout << l.getSize() << '\n';
  l.ReversePrint();
  cout << '\n';
  l.Traverse();
  return 0;
}