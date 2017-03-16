#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <climits>

#define all(c) (c).begin(), (c).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb(e) push_back(e)
#define mp(a, b) make_pair(a, b)
#define fr first
#define sc second

const int INF=100000000;
int dx[4]={1,0};
int dy[4]={0,1};
using namespace std;
typedef pair<int ,int > P;
typedef long long ll;

int room[20][20];
int N,R,C;

void plot() {
    rep(i,20) {
        rep(j,20)
            cout<<room[i][j]<<" ";
        cout<<endl;
    }
}

void put(int S) {
    rep(i,20) rep(j,20) room[i][j]=0;
    rep(i,16) {
        if((S>>i)&1) {
            room[i/C][i%C]=1;
        }
    }
    // cout<<S<<endl;
    // plot();
}
int cnt() {
    int ret=0;
    rep(i,20) rep(j,20) rep(k,2) {
        int r=i+dy[k];
        int c=j+dx[k];
        if(!(0<=r&&r<20)) continue;
        if(!(0<=c&&c<20)) continue;
        if(room[i][j] && room[r][c]) {
            // printf("%d %d -> %d %d\n",i,j,r,c);
            ret++;
        }
    }
    return ret;
}

void solve() {
    int ans=INF;
    cin>>R>>C>>N;
    rep(S,1<<(R*C)) {
        if(__builtin_popcount(S)==N) {
            put(S);
            ans=min(ans,cnt());
        }
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    rep(i,t) {
        printf("Case #%d: ",i+1);
        solve();
    }
    return 0;
}

