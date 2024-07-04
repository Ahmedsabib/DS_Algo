#include <bits/stdc++.h>

using namespace std;

#define int long long

// Time Complexity - 
// Best case - O(n * n)
// Average case - O(n * n)
// Worst case - O(n * n)

// Space Complexity - O(1)

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (a[j] < a[i]) {
        swap(a[i], a[j]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  return 0;
}