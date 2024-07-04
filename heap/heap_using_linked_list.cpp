#include <bits/stdc++.h>

using namespace std;

class Max_Heap {
public:
  vector<int> nodes;
  Max_Heap() {

  }
  // O(log n)
  void up_heapify(int index) {
    while (index > 0 && nodes[index] > nodes[(index - 1)/2]) {
      swap(nodes[index], nodes[(index - 1)/2]);
      index = (index - 1)/2;
    }
  }
  void insert(int x) {
    nodes.push_back(x);
    up_heapify((int)nodes.size() - 1);
  }
  // O(n)
  void Print_Heap() {
    for (int i = 0; i < (int)nodes.size(); ++i) {
      cout << nodes[i] << ' ';
    }
    cout << '\n';
  }
  // O(log n)
  void down_heapify(int index) {
    while (1) {
      int largest = index;
      int l = 2 * index + 1;
      int r = 2 * index + 2;
      if (l < (int)nodes.size() && nodes[largest] < nodes[l]) {
        largest = l;
      }
      if (r < (int)nodes.size() && nodes[largest] < nodes[r]) {
        largest = r;
      }
      if (largest == index) {
        break;
      }
      swap(nodes[index], nodes[largest]);
      index = largest;
    }
  }
  // O(log n)
  void Delete(int index) {
    if (index >= (int)nodes.size());
    swap(nodes[index], nodes[(int)nodes.size() - 1]);
    nodes.pop_back();
    down_heapify(index);
  }
  // O(1)
  int getMax() {
    if ((int)nodes.empty()) {
      cout << "Heap is empty!\n";
      return -1;
    }
    return nodes[0];
  }
  // O(log n)
  int ExtractMax() {
    if ((int)nodes.empty()) {
      cout << "Heap is empty!\n";
      return -1;
    }
    int ret = nodes[0];
    Delete(0);
    return ret;
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  Max_Heap heap;
  heap.insert(4);
  heap.insert(7);
  heap.insert(9);
  heap.insert(1);
  heap.insert(10);
  heap.insert(20);
  heap.insert(30);
  cout << "Max element = " << heap.getMax() << '\n';
  // heap.Print_Heap();
  // heap.Delete(0);
  // heap.Print_Heap();
  cout << "Max element = " << heap.ExtractMax() << '\n';
  cout << "Max element = " << heap.ExtractMax() << '\n';
  
  return 0;
}