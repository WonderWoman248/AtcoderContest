#include <bits/stdc++.h>
using namespace std;

bool ok2(string& cs, string& ct) {
  assert(cs.size() == ct.size());
  int n = cs.size();
  int x = count(ct.begin(), ct.end(), 'A')-count(cs.begin(), cs.end(), 'A');
  int y = count(ct.begin(), ct.end(), 'B')-count(cs.begin(), cs.end(), 'B');
  if (x < 0 || y < 0) return 0;
  int cnt = 0;
  for (char& c: cs) {
    if (c == 'C') {
      if (cnt < x) c = 'A';
      else c = 'B';
      cnt++;
    }
  }
  assert(cnt == x+y);
  int d = 0;
  for (int i = 0; i < n; i++) {
    d += (ct[i] == 'B')-(cs[i] == 'B');
    if (d < 0) return 0;
  }
  return 1;
}

bool ok() {
  int n;
  string s, t;
  cin >> n >> s >> t;
  string cs, ct;
  for (int i = 0; i < n; i++) {
    if (t[i] == 'C') {
      if (s[i] != 'C') return 0;
      if (!ok2(cs, ct)) return 0;
      cs = ct = "";
    }
    else {
      cs += s[i];
      ct += t[i];
    }
  }
  if (!ok2(cs, ct)) return 0;
  return 1;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cout << (ok() ? "Yes" : "No") << '\n';
  }
}
