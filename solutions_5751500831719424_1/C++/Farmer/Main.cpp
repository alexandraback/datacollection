/*
 *Author:       Zhaofa Fang
 *Created time: 2014-05-03-23.50 Saturday
 */
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
#define DEBUG(x) cout<< #x << ':' << x << endl
#define FOR(i,s,t) for(int i = (s);i <= (t);i++)
#define FORD(i,s,t) for(int i = (s);i >= (t);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define REPD(i,n) for(int i=(n-1);i>=0;i--)
#define PII pair<int,int>
#define PB push_back
#define ft first
#define sd second
#define lowbit(x) (x&(-x))
#define INF (1<<30)
#define eps (1e-8)

const int maxn = 111;

string str[maxn],tmp[maxn];
int idx[maxn],cnt[maxn];

void solve(){
    int n;
    cin>>n;
    REP(i,n){
        cin>>str[i];
    }
    REP(i,n){
        int len = str[i].length();
        tmp[i] = "";
        tmp[i].PB(str[i][0]);
        FOR(j,1,len-1){
            if(str[i][j]!=str[i][j-1])tmp[i].PB(str[i][j]);
        }
    }
    REP(i,n){
        if(tmp[i] != tmp[0]){
            puts("Fegla Won");
            return;
        }
    }
    memset(idx,0,sizeof(idx));
    int sz = tmp[0].length();
    int ans = 0;
    REP(i,sz){
        memset(cnt,0,sizeof(cnt));
        REP(j,n){
            while(idx[j]<str[j].length() && str[j][idx[j]] == tmp[0][i]){
                cnt[j] ++;
                idx[j] ++;
            }
        }
        int sum = 0;
        REP(j,n)sum += cnt[j];
        int tmp1 = sum/n;
        int tmp2 = tmp1;
        if(sum%n!=0)tmp2 ++;
        int tot1=0,tot2=0;
        REP(j,n){
            tot1 += abs(cnt[j]-tmp1);
            tot2 += abs(cnt[j]-tmp2);
        }
        ans += min(tot1,tot2);
    }
    printf("%d\n",ans);
}
int main(){
    freopen("A-large.in","r",stdin);
    freopen("out","w",stdout);
    int T;
    cin>>T;
    FOR(cas,1,T){
        printf("Case #%d: ",cas);
        solve();
    }
    return 0;
}
