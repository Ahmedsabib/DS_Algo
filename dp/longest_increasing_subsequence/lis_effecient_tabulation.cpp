#include <bits/stdc++.h>

using namespace std;

#define int long long

// Longest Increasing Subsequence (LIS)

// Tabulation Method(Bottom Up Approach)
// Time Complexity - O(N * log N)
// Space Complexity - O(N)

const int inf = 1e9 + 7;

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  // Step 1:
  vector<int> dp(n + 1, inf);
  dp[0] = -inf;
  for (int i = 0; i < n; ++i) {
    int ind = upper_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
    if (dp[ind - 1] < a[i] && a[i] < dp[ind]) dp[ind] = a[i];
  }
  int ans = 0;
  for (int i = 0; i <= n; ++i) {
    if (dp[i] < inf) ans = i;
  }
  cout << ans << '\n';

  // Step 2:
  vector<int> dp2;
  for (int i : a) {
    int pos = lower_bound(dp2.begin(), dp2.end(), i) - dp2.begin();
    if (pos == (int)dp2.size()) {
      // we can have a new, longer increasing subsequence!
      dp2.push_back(i);
    } else {
      // oh ok, at least we can make the ending element smaller
      dp2[pos] = i;
    }
  }

  // Step 3: Using Set / Multi Set
  set<int> s;
  for (int i = 0; i < n; ++i) {
    s.insert(a[i]);
    auto it = s.find(a[i]);
    it++;
    if (it != s.end()) s.erase(it);
  }
  return 0;
}