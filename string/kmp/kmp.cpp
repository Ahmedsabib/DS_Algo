#include <bits/stdc++.h>

using namespace std;

// Time Complexity - O(m + n)
vector<int> prefix_function(string s) {
  int n = (int)s.size();
  vector<int> pi(n, 0);
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) {
      ++j;
    }
    pi[i] = j;
  }
  return pi;
}

int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  string s = "na";
  vector<int> prefix = prefix_function(s);
  string t = "apnacollege";
  int pos = -1;
  int i = 0, j = 0;
  while (i < (int)t.size()) {
    if (t[i] == s[j]) {
      ++j;
      ++i;
    }
    else {
      if (j != 0) {
        j = prefix[j - 1];
      }
      else {
        ++i;
      }
    }
    if (j == (int)s.size()) {
      pos = i - (int)s.size();
      break;
    }
  }
  cout << pos << '\n';
  return 0;
}