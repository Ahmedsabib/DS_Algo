#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
// iterative method
// (a^b)%m
long long binpow(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b&1) {
      res = res * a % m;
    }
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
// Time Complexity O(log n) // n -> b(the power)
// iterative method
// (a^b)
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b&1) {
      res = res * a;
    }
    a = a * a;
    b >>= 1;
  }
  return res;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long a, b;
  cin >> a >> b;
  cout << binpow(a, b) << '\n';
  cout << binpow(a, b, mod) << '\n';
  return 0;
}