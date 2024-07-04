#include <bits/stdc++.h>
using namespace std;
double binary_search_bisection(long long n) {
  double low = 0.0, high = n, mid;
  while (high - low > 0.00000001) { // for (int i = 0; i < 100; ++i)
    mid = low + (high - low)/2;
    if (mid * mid > n) {
      high = mid;
    }
    else {
      low = mid;
    }
  }
  return mid;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  long long n;
  cin >> n;
  cout << fixed << setprecision(10) << binary_search_bisection(n) << '\n';
  return 0;
}