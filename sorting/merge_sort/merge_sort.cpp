#include <bits/stdc++.h>
using namespace std;
// Time Complexity 
// Best Case - (n log n)
// Average Case - (n log n)
// Worst Case - (n log n)

// Space Complexity - O(n)

// Divide and Conquer method
vector<int> merge_sort(vector<int> a) {
  // base case
  if ((int)a.size() <= 1) {
    return a;
  }
  int mid = (int)a.size()/2;
  vector<int> b, c;
  for (int i = 0; i < mid; ++i) {
    b.push_back(a[i]);
  }
  for (int i = mid; i < (int)a.size(); ++i) {
    c.push_back(a[i]);
  }
  vector<int> sorted_b = merge_sort(b);
  vector<int> sorted_c = merge_sort(c);
  vector<int> sorted_a;
  int l = 0, r = 0;
  for (int i = 0; i < (int)a.size(); ++i) {
    if (l == (int)sorted_b.size()) {
      sorted_a.push_back(sorted_c[r]);
      r++;
    }
    else if (r == (int)sorted_c.size()) {
      sorted_a.push_back(sorted_b[l]);
      l++;
    }
    else if (sorted_b[l] < sorted_c[r]) {
      sorted_a.push_back(sorted_b[l]);
      ++l;
    }
    else {
      sorted_a.push_back(sorted_c[r]);
      ++r;
    }
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
  vector<int> ans = merge_sort(a);
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}