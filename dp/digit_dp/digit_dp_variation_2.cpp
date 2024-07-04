/**
 * Problem Statement:
 * How many numbers x are there in the range a to b,
 * where the digit d occurs exactly k times in x? There may have several solutions including number theory or combinatorics,
 * but let’s see how we can solve this problem using digit dp.
 * Source: https://codeforces.com/blog/entry/53960
**/
#include <bits/stdc++.h>

using namespace std;

#define int long long

/**
 * Digit DP Problem
**/

vector<int> dig;
int a, b, d, k;
int dp[12][2][12];

int digit_dp(int pos, int is_small, int cnt) {
  if (cnt > k) return 0;
  if (pos == (int)dig.size()) return (cnt == k);
  int &ret = dp[pos][is_small][cnt];
  if (~ret) return ret;
  ret = 0;
  int low = 0, high = dig[pos];
  if (is_small) high = 9;
  for (int i = low; i <= high; ++i) {
    int new_is_small = is_small | (i < high);
    int cnt_d = cnt;
    if (i == d) ++cnt_d;
    int val = digit_dp(pos + 1, new_is_small, cnt_d);
    ret += val;
  }
  return ret;
}

int f(int n) {
  dig.clear();
  while (n) {
    int rem = n%10;
    dig.push_back(rem);
    n /= 10;
  }
  reverse(dig.begin(), dig.end());
  memset(dp, -1, sizeof(dp));
  return digit_dp(0, 0, 0);
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    cout << "Case " << cases + 1 << ": ";
    cin >> a >> b >> d >> k;
    int x = f(b), y = f(a - 1);
    cout << x - y << '\n';
  }
  return 0;
}