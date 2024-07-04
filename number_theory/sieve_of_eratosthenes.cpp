#include <bits/stdc++.h>
using namespace std;
const int limit = 1e9 + 7;
// Sieve of Eratosthenes
// Time Complexity O(n log log n)
// can be used until 10^9
vector<bool> is_prime(limit+1, true); // define every number as prime
vector<long long> primes; // for storing the primes
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
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  sieve_of_eratosthenes();
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