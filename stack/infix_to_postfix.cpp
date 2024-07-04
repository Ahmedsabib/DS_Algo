#include <bits/stdc++.h>

using namespace std;

int prec(char ch) {
  if (ch == '+' || ch == '-') {
    return 0;
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);

  string s;
  cin >> s;
  stack<int> st;
  string ans = "";
  for (int i = 0; i < (int)s.size(); ++i) {
    char now = s[i];
    if (now >= 'a' && now <= 'z') {
      ans += now;
    }
    else {
      while ((int)s.size() && prec(st.top()) >= prec(now)) {
        ans += st.top();
        st.pop();
      }
      st.push(now);
    }
    while ((int)st.size()) {
      ans += st.top();
      st.pop();
    }
    cout << ans << '\n';
  }
  return 0;
}