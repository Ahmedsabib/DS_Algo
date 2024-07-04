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
  // O(n)
  void build_from_array(vector<int> &a) {
    nodes = a;
    int n = (int)nodes.size();
    int last_non_leaf = n/2 - 1;
    for (int i = last_non_leaf; i >= 0; --i) {
      down_heapify(i);
    }
  }
};

// O(n log n)
vector<int> heap_sort(vector<int> a) {
  Max_Heap h;
  h.build_from_array(a);
  vector<int> ans;
  for (int i = 0; i < (int)a.size(); ++i) {
    ans.push_back(h.ExtractMax());
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  vector<int> a = {1, 2, 3, 4, 10, 9, 5, 7};
  vector<int> sorted_a = heap_sort(a);
  for (int i = 0; i < (int)sorted_a.size(); ++i) {
    cout << sorted_a[i] << ' ';
  }
  cout << '\n';
  
  return 0;
}