#include <bits/stdc++.h>
using namespace std;
const int limit = 1e7 + 7;
// Linear Sieve
// Time Complexity O(n log log n)
// can be used until 10^7
vector<long long> lp(limit + 1);
vector<long long> primes;
void linear_sieve() {
  for (int i = 2; i <= limit; ++i) {
    if (lp[i] == 0) {
      lp[i] = i;
      primes.push_back(i);
    }
    for (int j = 0; j < (int)primes.size() && primes[j] <= lp[i] && i * primes[j] <= limit; ++j) {
      lp[i * primes[j]] = primes[j];
    }
  }
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  linear_sieve();
  long long n;
  cin >> n;
  for (int i = 0; i < (int)primes.size(); ++i) {
    if (primes[i] > n) {
      break;
    }
    cout << primes[i] << ' ';
  }
  cout << '\n';
  return 0;
}