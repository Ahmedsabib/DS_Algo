#include <bits/stdc++.h>
using namespace std;
// Time Complexity - O(n)
// finding if the number is prime
bool is_prime(long long x) {
  if (x < 2) {
    return false;
  }
  for (int d = 2; d * d <= x; ++d) {
    if (x%d == 0) {
      return false;
    }
  }
  return true;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long n;
  cin >> n;
  cout << (is_prime(n)? "YES" : "NO") << '\n';
  return 0;
}