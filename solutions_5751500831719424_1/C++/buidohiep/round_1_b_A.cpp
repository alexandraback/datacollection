#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(i,a,b) for(int i=a; i>=b; i--)
#define FORAD(i,u) for(int i=0; i < (int)u.size(),i++)
#define BUG(x) cout << x << endl
#define ll long long
#define fi first
#define sd second
#define pb push_back
#define two(i) 1 << i
#define sz(x) (int)x.size()
#define e 1e-12
#define bit(s,i) ((s >> (i-1)) & 1)
#define Nmax 100100
const double pi = acos(-1);
typedef vector<int> vi ;
typedef pair<int,int> pii ;

int l[111], v[111], n, res, sl[111];
string s[111];

bool check() {
    FOR(i, 1, n) if (s[i][v[i]] != s[1][v[1]]) return false;
    return true;
}

void solve() {
    res = -1;
    int sum = 0;
    FOR(i, 1, n) {
      l[i] = sz(s[i]);
      s[i] = s[i] + "#";
      v[i] = 0;
    }
    while (v[1] <= l[1] - 1) {
        if (check() == false) return;
        FOR(i, 1, n) {
            int j = v[i];
            while (j < l[i] && s[i][j] == s[i][v[i]]) j++;
            sl[i] = j - v[i];
            v[i] = j;
        }
        sort(sl + 1, sl + n + 1);
        int mid = (n + 1)/2;
        FOR(i, 1, n) sum += abs(sl[i] - sl[mid]);
    }
    FOR(i, 1, n) if (v[i] < l[i]) return;
    res = sum;
}

int main() {
     freopen("A-large.in","r",stdin);
     freopen("ans.out","w",stdout);

     int test;
     scanf("%d\n", &test);
     FOR(t, 1, test) {
         scanf("%d\n", &n);
         FOR(i, 1, n) getline(cin, s[i]);
         solve();
         if (res == -1) cout << "Case #" << t << ": Fegla Won" <<endl;
         else cout << "Case #" << t << ": " << res << endl;
     }
     return 0;
}
