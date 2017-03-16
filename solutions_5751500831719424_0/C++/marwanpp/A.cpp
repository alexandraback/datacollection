#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

int check (vector <int> cnt) {
  sort(cnt.begin(), cnt.end());
  int ans = 1e9;

  for (int x = cnt[0] ; x <= cnt.back() ; x ++) {
    int curans = 0;
    for (int i=0 ; i < cnt.size() ; i++)
      curans += abs(cnt[i] - x);
    ans = min (ans, curans);
  }

  return ans;
}

int main () {
  freopen ("input.txt", "rt", stdin);
  freopen ("out.txt", "wt", stdout);

  int t ;
  cin >> t ;
  for (int tt = 0 ; tt < t ; tt++) {
    cout << "Case #" << tt+1 << ": ";
    int n;
    cin >> n;
    vector <string> vs(n);
    set <string> s;

    for (int i=0 ; i < n ; i++) {
      cin >> vs[i];
      
      string str = vs[i].substr(0,1);
      for (int j=1 ; j < vs[i].size() ; j++)
        if (vs[i][j] != vs[i][j-1]) str += vs[i][j];
      
      s.insert(str);
    }
    if (s.size() > 1) {
      cout << "Fegla Won" << endl;
      continue;
    }
    
    vector <vector <int> > frq (n);
    for (int i=0 ; i < n ; i++) {
      for (int j=0 ; j < vs[i].size() ; j++) {
        frq[i].push_back(1);
        while (j+1 < vs[i].size() && vs[i][j+1] == vs[i][j]) {
          j++, frq[i].back() ++;
        }
      }
    }
    
    int result = 0;
    for (int j=0 ; j < frq[0].size() ; j++) {
      vector <int> cur;
      for (int i=0 ; i < n ; i++)
        cur.push_back(frq[i][j]);

      result += check(cur);
    }

    cout << result << endl;
  }
  return 0;
}
