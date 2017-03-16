#include<cstdio>
#include<cstring>
#include<cmath>
#include<cctype>
#include<vector>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<numeric>
#include<fstream>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define pb push_back
#define all(a) a.begin(),a.end()
#define eps (1e-9)
#define inf (1<<29)
#define i64 long long
#define u64 unsigned i64


int R, C , N;
int calc(int x){
    int i, j, k, k1, ret = 0;
    for(i = 0;i<R;i++){
        for(j = 0;j<C;j++){
            k = i*C + j;
            if(!(x & (1<<k))) continue;
            if(j<C-1){
                k1 = k+1;
                if(x & (1<<k1))
                    ret ++;
            }
            if(i<R-1){
                k1 = (i+1)*C + j;
                if(x & (1<<k1))
                    ret ++;
            }
        }
    }
    return ret;
}
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.ans","w",stdout);
    int t,cs = 1, M, ans, r, i;
    cin>>t;
    while(t--){
        cin>>R>>C>>N;
        M = R*C;
        if(N == 0){
            printf("Case #%d: %d\n",cs++,0);
            continue;
        }
        ans = inf;
        for(i = 1;i<(1<<M);i++){
            if(__builtin_popcount(i) == N){
                r = calc(i);
                ans = min(r,ans);
            }
        }
        printf("Case #%d: %d\n",cs++,ans);
    }
	return 0;
}
