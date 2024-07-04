#include <bits/stdc++.h>
using namespace std;

// Time Complexity - 
// Best case - O(n)
// Average case - O(n * n)
// Worst case - O(n * n)

// Space Complexity - O(1)

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < (n - i - 1); j++) {
      if (a[j] > a[j + 1]) {
        swap(a[j], a[j + 1]);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  return 0;
}