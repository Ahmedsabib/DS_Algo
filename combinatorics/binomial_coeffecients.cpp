#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;

/**
 * Description: Binomial Coeffecient (nCr)
 * Source: https://usaco.guide/gold/combo?lang=cpp
 * Verification: https://cses.fi/problemset/task/1079/
**/

int fact[maxn], inv[maxn];

int binpow(int a, int b, int m) {
  a %= m;
  int res = 1;
  while (b > 0) {
    if (b&1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}

void factors() {
  fact[0] = fact[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    fact[i] = fact[i - 1]%mod * i;
    fact[i] %= mod;
  }
}

void mod_inv() {
  inv[maxn - 1] = binpow(fact[maxn - 1], mod - 2, mod);
  for (int i = maxn - 1; i >= 1; --i) {
    inv[i - 1] = inv[i]%mod * i;
    inv[i - 1] %= mod;
  }
}

int ncr(int n, int k) {
  if (k > n) return 0;
  return (fact[n] * inv[k]%mod * inv[n - k]%mod)%mod;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  factors();
  mod_inv();

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    int a, b;
    cin >> a >> b;
    cout << ncr(a, b) << '\n';
  }
  return 0;
}