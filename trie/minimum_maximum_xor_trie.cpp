#include <bits/stdc++.h>

using namespace std;

struct Trie {
  static const int B = 31;
  struct node {
    node* next[2];
    int sz;
    node() {
      next[0] = next[1] = NULL;
      sz = 0;
    }
  } *root;
  Trie() {
    root = new node();
  }
  void insert(int val) {
    node* cur = root;
    cur -> sz++;
    for (int i = B - 1; i >= 0; --i) {
      int b = (val >> i) & 1;
      if (cur -> next[b] == NULL) {
        cur -> next[b] = new node();
      }
      cur = cur -> next[b];
      cur -> sz++;
    }
  }
  int query(int x, int k) { // number of values s.t. val ^ x < k
    node* cur = root;
    int ans = 0;
    for (int i = B - 1; i >= 0; --i) {
      if (cur == NULL) break;
      int b1 = (x >> i) & 1, b2 = (k >> i) & 1;
      if (b2 == 1) {
        if (cur -> next[b1]) {
          ans += cur -> next[b1] -> sz;
        }
        cur = cur -> next[!b1];
      }
      else {
        cur = cur -> next[b1];
      }
    }
    return ans;
  }
  int get_max(int x) { // returns maximum of val ^ x
    node* cur = root;
    int ans = 0;
    for (int i = B - 1; i >= 0; --i) {
      int k = (x >> i) & 1;
      if (cur -> next[!k]) {
        cur = cur -> next[!k];
        ans <<= 1;
        ++ans;
      }
      else {
        cur = cur -> next[k];
        ans <<= 1;
      }
    }
    return ans;
  }
  int get_min(int x) {
    node* cur = root;
    int ans = 0;
    for (int i = B - 1; i >= 0; --i) {
      int k = (x >> i) & 1;
      if (cur -> next[k]) {
        cur = cur -> next[k];
        ans <<= 1;
      }
      else {
        cur = cur -> next[!k];
        ans <<= 1;
        ++ans;
      }
    }
    return ans;
  }
  void del(node* cur) {
    for (int i = 0; i < 2; ++i) {
      if (cur -> next[i]) {
        del(cur -> next[i]);
      }
    }
    del(cur);
  }
} t;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  int tests;
  cin >> tests;
  for (int cases = 0; cases < tests; ++cases) {
    int n, k;
    cin >> n >> k;
    int cur = 0;
    long long ans = 1LL * n * (n + 1)/2;
    t.insert(cur);
    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      cur ^= x;
      ans -= t.query(cur, k);
      t.insert(cur);
    }
    cout << ans << '\n';
  }
  return 0;
}