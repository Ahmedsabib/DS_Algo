#include <bits/stdc++.h>

using namespace std;

#define int long long

// The graph represented as an adjacency list (0-indexed)
vector<vector<int>> neighbors{{1, 2}, {0}, {0, 3, 4}, {2}, {2}};
vector<int> starting(neighbors.size());
vector<int> ending(neighbors.size());
int timer = 0;

void euler_tour(int at, int prev) {
  starting[at] = timer++;
  for (int n : neighbors[at]) {
    if (n != prev) { euler_tour(n, at); }
  }
  ending[at] = timer;
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    // TODO: make sure all variable get reset.
  }
  return 0;
}
