/* Divanshu Garg */

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <cctype>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ill long long int
#define pii pair<int,int>
#define pb(x) push_back(x)
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define FD(i,a,n) for(int i=(a);i>=(n);--i)
#define FE(it,x) for(it=x.begin();it!=x.end();++it)
#define V(x) vector<x>
#define S(x) scanf("%d",&x)
#define Sl(x) scanf("%llu",&x)
#define M(x,i) memset(x,i,sizeof(x))
#define debug(i,sz,x) F(i,0,sz){cout<<x[i]<<" ";}cout<<endl
ill ABS(ill a) { if ( a < 0 ) return (-a); return a; }
#define fr first
#define se second

/* Relevant code begins here */

/* Input from file or online */

void input() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

/* Input opener ends */

#define pci pair<char,int>

string s[105];

int main() {

    // input();

    int t, test =1;
    cin >> t;

    while ( t-- ) {
        int n; cin >> n;
        F(i,0,n) {
            cin >> s[i];
        }

        vector<pci> order[105];
        F(i,0,n) {
            char curr = s[i][0];
            int cnt = 1;
            F(j,1,s[i].size()) {
                if ( curr != s[i][j] ) {
                    order[i].pb(pci(curr,cnt));
                    curr = s[i][j];
                    cnt = 1;
                }
                else cnt++;
            }
            order[i].pb(pci(curr,cnt));
        }
        // F(i,0,n) {
        //     F(j,0,order[i].size()) cout << order[i][j].fr << " " << order[i][j].se << " , ";
        //     cout << endl;
        // }
        bool poss = 1;
        F(i,1,n) {
            if ( order[i].size() != order[0].size() ) {
                poss = 0; break;
            }
            F(j,0,order[0].size())
                if ( order[i][j].fr != order[0][j].fr )
                    { poss = 0; }
        }
        cout << "Case #" << test++ << ": ";
        if ( poss ) {
            int ans = 0;
            F(j,0,order[0].size()) {
                vector<int> x;
                F(i,0,n) x.pb(order[i][j].se);
                sort(x.begin(),x.end());
                if ( (x.size()%2) == 0 ) {
                    int ans1 = 0, ans2 = 0;
                    int el = x.size()/2;
                    int el2 = el-1;
                    F(i,0,n) {
                        ans1 += ABS(x[el]-x[i]);
                        ans2 += ABS(x[el2]-x[i]);
                    }
                    ans += min(ans1,ans2);
                } else {
                    int el = x.size()/2;
                    F(i,0,n) ans += ABS(x[el]-x[i]);
                }
            }
            cout << ans << endl;
        } else cout << "Fegla Won" << endl;

    }

    return 0;
}