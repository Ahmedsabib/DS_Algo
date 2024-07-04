#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e6 + 5;

/**
 * Description: Derangement
 * Source: https://usaco.guide/gold/combo?lang=cpp
 * Verification: https://judge.yosupo.jp/problem/montmort_number_mod
**/

int dar[maxn];

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n, m;
  cin >> n >> m;
  dar[1] = 0;
  dar[2] = 1;
  cout << dar[1] << ' ' << dar[2] << ' ';
  for (int i = 3; i <= n; ++i) {
    dar[i] = (dar[i - 2]%m + dar[i - 1]%m) * (i - 1);
    dar[i] %= m;
    cout << dar[i] << ' ';
  }
  cout << '\n';
  return 0;
}