#include <bits/stdc++.h>
using namespace std;
// binary to decimal conversion
int binaryToDecimal(int n) {
  int d = 0, ans = 0;
  while (n > 0) {
    int res = n%10;
    n /= 10;
    ans += res * (1 << d);
    ++d;
  }
  return ans;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  cout << binaryToDecimal(n) << '\n';
  return 0;
}