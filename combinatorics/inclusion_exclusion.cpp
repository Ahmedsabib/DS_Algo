#include <bits/stdc++.h>

using namespace std;

#define int long long

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> a(k);
  int ans = 0;
  for (int i = 0; i < k; ++i) cin >> a[i];
  for (int i = 1; i < (1 << k); ++i) {
    int prod = 1;
    for (int j = 0; j < k; ++j) {
      if (i & (1 << j)) {
        if (prod > n/a[j]) {
          prod = n + 1;
          break;
        }
        prod *= a[j];
      }
    }
    int cnt = n/prod;
    if (__builtin_popcountll(i) & 1) ans += cnt;
    else ans -= cnt;
  }
  cout << ans << '\n';
  return 0;
}