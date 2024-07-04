#include <bits/stdc++.h>
using namespace std;
// Time Complexity O(log n)
// Space Complexity O(1)
int binary_search(vector<int> array, int value) {
  int low = 0, high = (int)array.size() - 1;
  int mid;
  while (low <= high) {
    mid = low + (high - low)/2;
    if (array[mid] == value) {
      return mid;
    }
    if (array[mid] < value) {
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }
  return -1;
}
int main(int argc, char const *argv[]) {
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int ind = binary_search(a, m);
  cout << ind + 1 << '\n';
  return 0;
}