#include <bits/stdc++.h>
using namespace std;
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
// when Ax + By = gcd(A, B)
int d, x, y;
void extended_gcd(int a, int b) {
  if (b == 0) {
    d = a;
    x = 1;
    y = 0;
  }
  else {
    extended_gcd(b, a%b);
    long long temp = x;
    x = y;
    y = temp - (a/b)*y;
  }
}
// Time Complexity O(max(A, M))
// when M is not prime
// when (A * B)%M = 1, gcd(A, M) = 1 (A, M are co-prime)
long long mod_inverse(long long a, long long m) {
  extended_gcd(a, m);
  return (x%m + m)%m;
  // when M is prime ->
  // return binpow(a, m - 2, m);
}
// Modular Arithmetic Inverse using Fermat's Law
// When M is prime
// A^M = A^(M - 2) % M
long long mod_inv(long long a, long long m) {
  return binpow(a, m - 2, m);
}  
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long a, m;
  cin >> a >> m;
  long long l  = mod_inverse(a, m); // (1/a)%m
  long long r  = mod_inv(a, m); // (1/a)%m
  cout << l << ' ' << r << '\n';
  return 0;
}