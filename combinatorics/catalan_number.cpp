#include <bits/stdc++.h>

using namespace std;

#define int long long

/**
 * Description: Catalan Numbers
 * Source: https://cp-algorithms.com/combinatorics/catalan-numbers.html
 * Verification: https://www.spoj.com/problems/SKYLINE/
 * Time Complexity: O(N * N)
 * Space Complexity: O(N)
**/

const int maxn = 1e3 + 5;
const int mod = 1e6;

int cat[maxn];

void catalans() {
  cat[0] = cat[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    cat[i] = 0;
    for (int j = 0; j < i; ++j) {
      cat[i] += (cat[j] * cat[i - j - 1])%mod;
      if (cat[i] >= mod) cat[i] -= mod;
    }
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  catalans();

  int n;
  while (cin >> n && n > 0) cout << cat[n] << '\n';
  return 0;
}