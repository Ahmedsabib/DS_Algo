#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
vector<vector<int>> ans;

bool solution_found(int ind, vector<int> state) {
  return ind == n;
}

vector<int> get_candidate(vector<int> state) {
  map<int, int> taken;
  for (auto& x: state) taken[x] = 1;
  vector<int> candidates;
  for (int i = 1; i <= n; ++i) {
    if (taken.count(i) == 0) candidates.push_back(i);
  }
  return candidates;
}

void backtrack(int ind, vector<int> state) {
  // base case handling
  if (solution_found(ind, state)) {
    ans.push_back(state);
    return;
  }
  // loop over the candidates
  vector<int> candidates = get_candidate(state);
  for (auto& candidate: candidates) {
    // add candidate to state
    state[ind] = candidate;
    // backtrack(state)
    backtrack(ind + 1, state);
    // remove candidate from state
    state[ind] = 0;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n;
  vector<int> initial_state(n);
  backtrack(0, initial_state);
  for (auto& rows: ans) {
    for (auto& cols: rows) {
      cout << cols << ' ';
    }
    cout << '\n';
  }
  return 0;
}