#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e6 + 5;

int a[maxn + 5], f[maxn + 5], g[maxn + 5], mp[maxn + 5], mul[maxn];

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) mp[a[i]]++;
  for (int i = 1; i <= maxn; ++i) {
    mul[i] = mp[i];
    for (int j = i + i; j <= maxn; j += i) mul[i] += mp[j];
  }
  // Exclusion DP
  // f[i] = number of pairs with gcd = multiple of i
  // g[i] = number of pairs with gcd = i
  for (int i = 1; i <= maxn; ++i) {
    int val = mul[i];
    f[i] = (val * (val - 1))/2;
  }
  for (int i = maxn; i >= 1; --i) {
    g[i] = f[i];
    for (int j = i + i; j <= maxn; j += i) g[i] -= g[j];
  }
  cout << g[1]<< '\n';
  return 0;
}