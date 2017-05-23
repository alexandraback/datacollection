#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <list>
#include <cstring>
#include <stack>
#include <bitset>

using namespace std;

#define NMAX 2147483647
#define LMAX 9223372036854775807LL
#define pb push_back
#define pob pop_back
#define mp make_pair
#define st first
#define nd second
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i,a,b) for(int i=(a);i>(b);--i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)

int main() {
  freopen("input.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int TS;
  scanf("%d",&TS);
  FORE(ts,1,TS) {
    int num[17];
    memset(num,0,sizeof(num));
    int a, b;
    REP(iiii,2) {
      scanf("%d",&a);
      REP(i,4)REP(j,4) {
        scanf("%d",&b);
        if(i == a - 1)
          num[b]++;
      }
    }
    vector <int> ans;
    printf("Case #%d: ",ts);
    FORE(i,1,16)
      if(num[i] == 2)
        ans.pb(i);
    if(ans.size() == 1)
      printf("%d\n",ans[0]);
    else if(ans.size())
      printf("Bad magician!\n");
    else
      printf("Volunteer cheated!\n");
  }
  return 0;
}
