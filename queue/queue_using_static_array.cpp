#include <bits/stdc++.h>
using namespace std;

const int maxn = 500;

class Queue {
public:
  int a[maxn];
  int l, r;
  int sz;
  Queue() {
    l = 0;
    r = -1;
    sz = 0;
  }
  // O(1)
  void enqueue(int value) {
    if (sz == maxn) {
      cout << "Queue is full\n";
      return;
    }
    r++;
    if (r == maxn) {
      r = 0;
    }
    a[r] = value;
    ++sz;
  }
  // O(1)
  void dequeue() {
    if (sz == 0) {
      cout << "Queue is empty\n";
      return;
    }
    ++l;
    if (l == maxn) {
      l = 0;
    }
    --sz;
  }
  // O(1)
  int front() {
    if (sz == 0) {
      cout << "Queue is empty\n";
      return -1;
    }
    return a[l];
  }
  // O(1)
  int size() {
    return sz;
  }
};

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  Queue q;
  q.enqueue(5);
  q.enqueue(6);
  q.enqueue(7);
  cout << q.size() << '\n';
  cout << q.front() << '\n';
  q.dequeue();
  cout << q.front() << '\n';
  q.dequeue();
  cout << q.size() << '\n';

  return 0;
}