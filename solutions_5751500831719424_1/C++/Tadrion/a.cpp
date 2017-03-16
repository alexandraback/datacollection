//Tadrion
#include <cstdio>
#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define CLEAR(x) (memset(x,0,sizeof(x)))
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define VAR(v, n) __typeof(n) v = (n)
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOREACH(i, c) for(VAR(i,(c).begin()); i != (c).end(); ++i)
#define DBG(v) cout<<#v<<" = "<<v<<endl;
#define IN(x,y) ((y).find(x)!=(y).end())
#define ST first
#define ND second
#define PB push_back
#define PF push_front
#define MP make_pair
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
int T;
int n;
string s[110];
string w[110];
int c[110][110];
int best[110];
int main() {
  scanf("%d",&T);
  FOR(iii,1,T) {
    scanf("%d",&n);
    REP(i,n) {
        cin >> s[i];
    }
    CLEAR(c);
    CLEAR(best);
    FOR(i,0,109) best[i] = 1000000000LL;
    int M = 0;
    REP(i,n) {
        int l = 0;
        c[i][0] = 1;
        w[i] = "";
        w[i] += s[i][0];
        FOR(j,1,SZ(s[i])-1) {
            if(s[i][j] == s[i][j-1]) c[i][l]++;
            else {w[i] = w[i] + s[i][j]; l++; c[i][l] = 1;}
        }
    }
/*
    FOR(i,0,n-1) {
        cout << w[i] << "\n";
        FOR(j,0,SZ(w[i])-1) printf("%d ",c[i][j]);
        printf("\n");
    }
*/
    bool ok = true;
    REP(i,n-1) if(w[i] != w[i+1]) ok = false;
    if(!ok) {
        printf("Case #%d: Fegla Won\n",iii);
        continue;
    }
    else {
        M = SZ(w[0]);
        FOR(i,0,M-1) {
            FOR(cnt,1,110) {
                int val = 0;
                FOR(j,0,n-1) {
                    val += MAX(cnt-c[j][i],c[j][i]-cnt);
                }
                best[i] = MIN(best[i],val);
            }
            //printf("%d %d\n",i,best[i]);
        }
        int summ = 0;
        FOR(i,0,M-1) summ += best[i];

        printf("Case #%d: %d\n",iii,summ);
    }
  }
  return 0;
}
