#include <bits/stdc++.h>

using namespace std;

#define int long long

int fact[31], dp[35][35], NCR[30][30];

// Bionomial Coeffecient
// nCr using DP
int ncr(int n, int r) {
  if (n == r || r == 0) return 1;
  if (r == 1) return n;
  int &ret = dp[n][r];
  if (~ret) return ret;
  ret = ncr(n - 1, r) + ncr(n - 1, r - 1);
  return ret;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  fact[0] = fact[1] = 1;
  for (int i = 2; i <= 30; ++i) fact[i] = fact[i - 1] * i;
  // Memoization
  memset(dp, -1, sizeof(dp));
  cout << ncr(10, 5) << '\n';

  // Tabulation
  for (int i = 0; i <= 20; ++i) {
    NCR[i][0] = 1;
    NCR[i][i] = 1;
  }
  for (int i = 1; i <= 20; ++i) {
    for (int j = 1; j <= 20; ++j) {
      NCR[i][j] = NCR[i - 1][j] + NCR[i - 1][j - 1];
    }
  }
  cout << NCR[5][5] << '\n';
  return 0;
}
