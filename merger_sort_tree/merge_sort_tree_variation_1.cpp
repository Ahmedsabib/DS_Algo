/**

Problem Statement:
We are given an array a1,a2,a3...an and an integer q. The i th of the next q
lines has three integers li, ri ,xi. The answer for this query is how many aj
such that li ≤ j ≤ ri and aj < x.

**/

/**

Solutions:
Let's create a merge sort tree where each node has a sorted vector containing all elements in the range of this node.
Now we can answer the query recursively like a segment tree. For some node if [lnode, rnode] is outside [li,ri]
its answer is obviously 0. If its entirely contained, we can do binary search on the vector to find how many elements
satisfy the conditions. If neither of the previous conditions are satisfied, we take the answer of the right child + 
the answer of the left child. Time complexity for building the merge sort tree is O(nlogn) because we go through each
element logn times, and the time complexity for answering the queries is O(qlog2n) because in each query we visit logn
nodes at most, doing binary search in each one in O(logn).

**/

// Code: Merge Sort Tree
// Time Complexity O(qlog^2n)

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e5 + 5;

int n, q, a[maxn];
vector<int> tree[4 * maxn];

// build merge sort tree O(log n)
void build(int node, int start, int end) {
  // if range length is 1 there's only one element to add and no children
  if (start == end) {
    tree[node].push_back(a[start]);
    return;
  }
  int mid = (start + end)/2;
  build(node * 2, start, mid);
  build(node * 2 + 1, mid + 1, end);
  // merge
  int i = 0, j = 0;
  // use two pointers to merge the two vectors in O(r-l+1)
  while (i < (int)tree[node * 2].size() && j < (int)tree[node * 2 + 1].size()) {
    if (tree[node * 2][i] < tree[node * 2 + 1][j]) tree[node].push_back(tree[node * 2][i++]);
    else tree[node].push_back(tree[node * 2 + 1][j++]);
  }
  while (i < (int)tree[node * 2].size()) tree[node].push_back(tree[node * 2][i++]);
  while (j < (int)tree[node * 2 + 1].size()) tree[node].push_back(tree[node * 2 + 1][j++]);
  return;
}

// query O(log^2 n)
int query(int node, int start, int end, int l, int r, int val) {
  //if outside -> 0
  if (start > r || end < l) return 0;
  // if inside do binary search
  if (start >= l && end <= r) {
    // step - 1:
    int low = 0, high = tree[node].size() - 1, ans = 0;
    while (low <= high) {
      int mid = (low + high)/2;
      if (tree[node][mid] < val) {
        ans = mid + 1;
        low = mid + 1;
      }
      else {
        high = mid - 1;
      }
    }
    return ans;
    // step 2:
    // return lower_bound(tree[node].begin(), tree[node].end(), val) - tree[node].begin();
  }
  int mid = (start + end)/2;
  return query(node * 2, start, mid, l, r, val) + query(node * 2 + 1, mid + 1, end, l, r, val);
}

int32_t main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  build(1, 1, n);
  cin >> q;
  while (q--) {
    int l, r, x;
    cin >> l >> r >> x;
    cout << query(1, 1, n, l, r, x) << '\n';
  }
  return 0;
}