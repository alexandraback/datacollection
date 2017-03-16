#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <cctype>
using namespace std;

#define rep(i, n) for (int i=0; i<(n); ++i)
#define repf(i, a, b) for (int i=(a); i<=(b); ++i)
#define repd(i, a, b) for (int i=(a); i>=(b); --i)
#define clr(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define sz(a) ((int)(a).size())
#define ll long long 

#define N 4

int i,j,k,m,n,l;
int a[N+10][N+10], b[N+10][N+10];
int x, y;

int main(){
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int ts;
    scanf("%d", &ts);
    repf(te, 1, ts){
        scanf("%d", &x);
        rep(i, N) rep(j, N) scanf("%d", &a[i][j]);
        scanf("%d", &y);
        rep(i, N) rep(j, N) scanf("%d", &b[i][j]);    
        
        x--, y--;
        set<int> st;
        rep(j, N) st.insert(a[x][j]);
        int k=0;
        rep(j, N) if (st.find(b[y][j])!=st.end()) k++, l=b[y][j];
        
        printf("Case #%d: ", te);
        if (k==1) printf("%d\n", l);
        else if (k==0) puts("Volunteer cheated!");
        else puts("Bad magician!");
    }
    return 0;
}
