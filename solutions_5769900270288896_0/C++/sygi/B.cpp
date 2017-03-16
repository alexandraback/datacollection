#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define F first
#define S second
#define pb push_back
#define rep(I,N) for(int (I) = 0; (I) < (N); (I)++)

typedef pair<int,int> pii;
typedef long long ll;
bool grid[20][20];
int r,c;
pii change(int x){
    return mp(x % r, x / r);
}
bool ins(pii x){
    if (x.F < 0 || x.S < 0 || x.F >= r || x.S >= c)
        return false;
    if (!grid[x.F][x.S])
        return false;
    return true;
}
int mx[]={0,0,1,-1};
int my[]={1,-1,0,0};
int count(pii x){
    int res = 0;
    rep(m, 4){
        pii n = mp(x.F + mx[m], x.S + my[m]);
        if (!ins(n))
            continue;
        res++;
    }
    return res;
}
vector<pii> places;
void fill(int x){
    places.clear();
    rep(i, 20) rep(j,20) grid[i][j] = 0;
    rep(i, r*c){
        if (x & (1<<i)){
            pii p = change(i);
            grid[p.F][p.S] = 1;
            places.pb(p);
        }
    }
}
int curr(){
    int myR = 0;
    rep(i, places.size()){
        myR += count(places[i]);
    }
    return myR/2;
}
int main(){
    int t;
    scanf("%d",&t);
    rep(testId,t){
        printf("Case #%d: ", testId+1);
        int tenants;
        scanf("%d%d%d",&r,&c,&tenants);
        int best = 1000 * r * c;
        rep(i, 1<<(r*c)){
            if (__builtin_popcount(i) != tenants)
                continue;
            fill(i);
            best = min(best, curr());
        }
        printf("%d\n", best);
    }
}
