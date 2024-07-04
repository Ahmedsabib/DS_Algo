/**
 * Description: Digit DP
 * Problem Link: https://usaco.org/index.php?page=viewproblem2&cpid=435
 * Solution Source: https://usaco.guide/gold/digit-dp?lang=cpp
**/

#include <bits/stdc++.h>

using namespace std;

#define int long long

// namespace FileIO template taken from bqi343
inline namespace FileIO {
  void setIn(string s) { freopen(s.c_str(), "r", stdin); }
  void setOut(string s) { freopen(s.c_str(), "w", stdout); }
  void setIO(string s = "") {
    cin.tie(0)->sync_with_stdio(0);  // unsync C / C++ I/O streams
    cout << fixed << setprecision(12);
    // cin.exceptions(cin.failbit);
    // throws exception when do smth illegal
    // ex. try to read letter into int
    if ((int)(s.size())) setIn(s + ".in"), setOut(s + ".out");  // for old USACO
  }
}

int dp[19][50][2][2]; // dp[pos][k][under][started]
string num;

// reset the dp array to it's initial values
void reset() {
  for (int i = 0; i < 19; ++i) {
    for (int j = 0; j < 50; ++j) {
      for (int k = 0; k < 2; ++k) {
        for (int l = 0; l < 2; ++l) {
          dp[i][j][k][l] = -1;
        }
      }
    }
  }
}

/**
 * Calculate the number of sequences whose digits consist of at least half targ.
 * If targ2 is not -1, then calculate the number of sequences whose digits are
 * exactly half targ and half targ2.
 * pos the starting position
 * k counter for the number of the target digit targ
 * under if the current sequence is smaller than the given upperbound
 * started if the sequence has any digit other than leading zeros
**/
int solve_dp(int pos, int k, bool under, bool started, int target1, int target2) {
  // base case: the sequence has reached the maximal length
  if (pos == (int)num.size()) {
    // edge case: the sequence only contains zeros, i.e. did not start
    if (!started) return 0;
    /**
     * If we are interested in finding out weather the sequence contains
     * exactly half digits of target and half digits of target2
    **/
    if (target2 != -1) {
      if (k == 20) return 1;
      else return 0;
    }
    /**
     * Otherwise, the sequence is interesting if at least half
     * of the digits are our target number target
    **/
    if (k >= 20) return 1;
    else return 0;
  }
  if (dp[pos][k][under][started] != -1) return dp[pos][k][under][started];
  int ans = 0;
  for (int i = 0; i <= 9; ++i) {
    int digit_dif = num[pos] - '0';
    /**
     * If the sequence will be larger than the upperbound, then we
     * can terminate
    **/
    if (!under && i > digit_dif) break;
    /**
     * If the new digit is smaller than the one in the upperbound, then any
     * child sequence can't be larger than than upperbound as this digit is
     * more significant than any following one
    **/
    bool is_under = under;
    if (i < digit_dif) is_under = true;
    // the sequence has started if any digits until pos is other than 0
    bool is_started = started || i != 0;
    /**
     * If we want to count how many sequences have exactly half digits of
     * targ and half of targ2, then any other number than targ or targ2
     * doesn't matter
    **/
    if (is_started && target2 != -1 && i != target1 && i != target2) continue;
    /**
     * The count for target digit targ is increased by one if i is targ, or
     * decreased by one otherwise.
    **/
    int new_k = k;
    if (is_started) {
      if (target1 == i) new_k = k + 1;
      else new_k = k - 1;
    }
    ans += solve_dp(pos + 1, new_k, is_under, is_started, target1, target2);
  }
  return dp[pos][k][under][started] = ans;
}

int cnt_interest(int ubound) {
  num = to_string(ubound);
  int ans = 0;
  for (int i = 0; i <= 9; ++i) {
    reset();
    ans += solve_dp(0, 20, false, false, i, -1);
  }
  /**
   * If a sequence's digits consist of exactly half i and half j, then it will
   * be counted twice. We have to subtract duplicates to avoid overcount.
  **/
  int duplicates = 0;
  for (int i = 0; i <= 9; ++i) {
    for (int j = 0; j <= 9; ++j) {
      reset();
      duplicates += solve_dp(0, 20, false, false, i, j);
    }
  }
  return ans - (duplicates/2);
}

int32_t main() {
  // setIO("odometer");

  int x, y;
  cin >> x >> y;
  cout << cnt_interest(y) - cnt_interest(x - 1) << '\n';
  return 0;
}