#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 7;
int phi[maxn];
// Time Complexity - O(n log log n)
void phi_1_to_n() {
  for (int i = 0; i <= maxn; ++i) {
    phi[i] = i;
  }
  for (int i = 2; i <= maxn; ++i) {
    if (phi[i] == i) {
      for (int j = i; j <= maxn; j += i) {
        phi[j] -= phi[j]/i;
      }
    }
  }
}
// sum of coprimes until n
int sum_of_coprimes_untill_n(int n) {
  return (phi[n]/2) * n;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  phi_1_to_n();
  int n;
  cin >> n;
  for (int i = 2; i < 13; ++i) {
    cout << phi[i] << ' ';
  }
  cout << '\n';
  cout << sum_of_coprimes_untill_n(n) << '\n';
  return 0;
}