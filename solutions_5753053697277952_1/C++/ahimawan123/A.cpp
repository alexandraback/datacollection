#include<iostream>
#include<queue>
#include<cstdio>
#include <utility>
#include<cstring>
using namespace std;

typedef pair<int,int> pii;

int main() {
  int cases;
  cin >> cases;
  for (int cas = 1; cas <= cases; cas++) {
    int n, tot, a[30];
    memset(a, 0, sizeof(a));
    
    cin >> n;
    tot = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      tot += a[i];
    }
    priority_queue<pii> q;
    for (int i = 0; i < n; i++) {
      q.push(pii(a[i], i));
    }
    printf("Case #%d:", cas);
    bool nospace = true;
    for (int i = tot; i > 0; i--) {
      pii tmp = q.top();
      int tmp2 = tmp.first;
      if (tmp2 * 2 > tot) {
	nospace = true;
      } else {
	nospace = false;
      }
      q.pop();
      int x = tmp.second;
      if (!nospace) {
	cout << " ";
      }
      cout << char('A' + x);
      a[x]--;
      tot--;
      if (a[x] > 0) {
	q.push(pii(a[x], x));
      }
    }
    cout << endl;
  }
  return 0;
}
