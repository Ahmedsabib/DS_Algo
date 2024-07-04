#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 1005;

// Time Complexity - O(N * M)
// Space Complexity - O(N + M)
 
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
 
int n, m, ans = 0;
char grid[maxn][maxn];
int visited[maxn][maxn];
 
bool is_valid(int x, int y) {
  return (x >= 0 && x < n && y >= 0 && y < m);
}
 
void dfs(int x, int y) {
  visited[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    int new_x = x + dx[i];
    int new_y = y + dy[i];
    if (is_valid(new_x, new_y) && !visited[new_x][new_y]) {
      dfs(new_x, new_y);
    }
  }
}
 
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
 
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == '#') {
        visited[i][j] = 1;
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (!visited[i][j]) {
        dfs(i, j);
        ++ans;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}