#include <bits/stdc++.h>
using namespace std;
// decimal to binary conversion
int decimalToBinary(int n) {
  int d = 1, ans = 0;
  while (n > 0) {
    int res = n%2;
    n /= 2;
    ans += res * d;
    d *= 10;
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  cout << decimalToBinary(n) << '\n';
  return 0;
}