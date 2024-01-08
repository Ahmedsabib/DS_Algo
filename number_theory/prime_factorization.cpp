#include <bits/stdc++.h>
using namespace std;
const int limit = (int)1e6 + 5;
vector<bool> is_prime(limit + 1, true);
vector<long long> primes;
void sieve_of_eratosthenes() {
  // Finding out the primes in simple way
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i * i <= limit; ++i) {
    if (is_prime[i]) {
      for (int j = i * i; j <= limit; j += i) {
        is_prime[j] = false;
      }
    }
  }
  // assigning values to an vector
  for (int i = 2; i <= limit; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
    }
  }
}
// Method 1
// faster process
// Time Complexity O(sqrt(n)/ln(sqrt(n)) + log2(n))
vector<long long> primes_factors(long long n) {
  vector<long long> factors;
  int root = sqrt(n);
  for (int i = 0; i < (int)primes.size() && primes[i] <= root; ++i) { // PI(n) ~= sqrt(n)/ln(sqrt(n))
    if (is_prime[n]) {
      break;
    }
    if (n%primes[i] == 0) {
      while (n%primes[i] == 0) { // log2(n)
        n /= primes[i];
        factors.push_back(primes[i]);
      }
      root = sqrt(n);
    }
  }
  if (n != 1) {
    factors.push_back(n);
  }
  return factors;
}
// Method 2
// a bit slow process for big integers
vector<long long> prime_divisors(long long n) {
  vector<long long> divisor;
  while (n%2 == 0) {
    divisor.push_back(2);
    n /= 2;
  }
  for (long long d = 3; d * d <= n; d += 2) {
    while (n%d == 0) {
      divisor.push_back(d);
      n /= d;
    }
  }
  if (n > 1) {
    divisor.push_back(n);
  }
  return divisor;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  sieve_of_eratosthenes();
  long long n;
  cin >> n;
  vector<long long> div = prime_divisors(n);
  vector<long long> div2 = primes_factors(n);
  for (auto& x: div) {
    cout << x << ' ';
  }
  cout << '\n';
  for (auto& x: div2) {
    cout << x << ' ';
  }
  cout << '\n';
  return 0;
}