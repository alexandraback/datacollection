/* 
 * File:   main.cpp
 * Author: sValerii
 *
 * Created on May 3, 2014, 6:38 PM
 */


#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <ctime>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)
#define forr(i,a,b) for (int i=a; i<=b; i++)
#define ford(i,a,b) for (int i=a; i>=b; i--)
#define mset(a,b) memset(a,b,sizeof(a))
#define sz(a) int( a.size() )
#define all(A) A.begin(),A.end()
#define sqr(q) q*q
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define X first
#define Y second

typedef long long i64;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef pair<int,int> PII;
typedef vector<string> VS;

int findCount(VI a) {
    int ans = -1;
    rep(i,sz(a)) {
        int s = 0;
        int v = a[i];
        rep(j,sz(a))
            s+=abs(a[j]-v);
        if (ans == -1) ans = s;
        if (s < ans) ans = s;
    }
    return ans;
}

pair<char,int> a[120][120];
char s[120];
int main() {
    freopen("out.txt","w",stdout);
    freopen("a.in.txt","r",stdin);
    int tnum;
    scanf("%d",&tnum);
    rep(tc,tnum) {
        int n;
        scanf("%d\n",&n);
        int k = -1;
        int good = true;
        printf("Case #%d: ",tc+1);
        rep(i,n) {
            char old=' ',c;
            scanf("%c",&c);
            int ind = 1;
            
            while (c != '\n') {
                if (old == ' ') a[i][0]=mp(c,0),old = c;
                if (old == c) a[i][ind-1].Y++;
                else {
                    old = c;
                    a[i][ind++]=mp(c,1);
                }
                scanf("%c",&c);
            }
            
            if (k == -1) k = ind;
            if (ind != k) good = false;
        }
        if (!good) { printf("Fegla Won\n"); }
        else {
            int ans = 0;
            rep(i,k) {
                if (!good) continue;
                VI t;
                rep(j,n)
                    if (a[j][i].X != a[0][i].X) good = false;
                    else t.pb(a[j][i].Y);
                if ( good ) ans+=findCount(t);    
            }
            if (!good) { printf("Fegla Won\n");}
            else printf("%d\n",ans);
            
        }

    }
    return 0;
}

