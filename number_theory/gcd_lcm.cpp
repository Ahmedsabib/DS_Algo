#include <bits/stdc++.h>
using namespace std;
long long lcm(long long a, long long b) {
  return a / gcd(a, b) * b;
}
// Time Complexity O(log min(a, b))
// recursive method
long long gcd(long long a, long long b) {
  return b ? gcd(b, a%b) : a;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long a, b;
  cin >> a >> b;
  cout << gcd(a, b) << '\n';
  cout << lcm(a, b) << '\n';
  return 0;
}