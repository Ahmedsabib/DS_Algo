#include <bits/stdc++.h>
using namespace std;
// Time Complexity - 
// Best case - O(n log n)
// Average case - O(n log n)
// Worst case - O(n * n)

// Space Complexity - O(log n)

vector<int> quick_sort(vector<int> a) {
  if ((int)a.size() <= 1) {
    return a;
  }
  int pivot = rand()%(int)a.size();
  vector<int> b, c;
  for (int i = 0; i < (int)a.size(); ++i) {
    if (i == pivot) {
      continue;
    }
    if (a[i] <= a[pivot]) {
      b.push_back(a[i]);
    }
    else {
      c.push_back(a[i]);
    }
  }
  vector<int> sorted_b = quick_sort(b);
  vector<int> sorted_c = quick_sort(c);
  vector<int> sorted_a;
  for (int i = 0; i < (int)sorted_b.size(); ++i) {
    sorted_a.push_back(sorted_b[i]);
  }
  sorted_a.push_back(a[pivot]);
  for (int i = 0; i < (int)sorted_c.size(); ++i) {
    sorted_a.push_back(sorted_c[i]);
  }
  return sorted_a;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> ans = quick_sort(a);
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}