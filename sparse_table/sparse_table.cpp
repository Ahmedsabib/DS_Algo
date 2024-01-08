#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int LOG = 17;

int a[MAX_N];
int m[MAX_N][LOG];
int bin_log[MAX_N];

int query(int L, int R) {
  int len = R - L + 1;
  int k = bin_log[len];
  return min(m[L][k], m[R - (1 << k) + 1][k]);
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  int n;
  cin >> n;
  // finding the logarithmic number
  bin_log[1] = 0;
  for (int i = 2; i <= n; ++i) {
    bin_log[i] = bin_log[i/2] + 1;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    m[i][0] = a[i];
  }
  // Preprocessing O(N*log(N))
  for (int k = 1; k < LOG; ++k) {
    for (int i = 0; i + (1 << k) - 1 < n; ++i) {
      m[i][k] = min(m[i][k - 1], m[i + (1 << (k - 1))][k - 1]);
    }
  }
  // answering query
  int q;
  cin >> q;
  while (q--) {
    int L, R;
    cin >> L >> R;
    cout << query(L, R) << '\n';
  }
  return 0;
}