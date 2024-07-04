#include <bits/stdc++.h>

using namespace std;

#define int long long

// Edit Distance (Memoization)
// Time Complexity O(3 ^ n)
// Space Complexity O(n * m)

int edit_distance(string s, string t, int n, int m) {
  if (n == 0) return m;
  if (m == 0) return n;
  if (s[n - 1] == t[m - 1]) {
    return edit_distance(s, t, n - 1, m - 1);
  }
  return 1 + min({edit_distance(s, t, n, m - 1), // insert
    edit_distance(s, t, n - 1, m), // remove
    edit_distance(s, t, n - 1, m - 1) // replace
  });
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  string s, t;
  cin >> s >> t;
  int n = (int)s.size();
  int m = (int)t.size();
  cout << edit_distance(s, t, n , m) << '\n';
  return 0;
}