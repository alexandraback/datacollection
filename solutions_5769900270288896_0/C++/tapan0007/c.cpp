//  main.cpp
//  Practice

//  Copyright (c) 2014 Tapan. All rights reserved.
//

#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<stack>
#include<functional>
using namespace std;
#define LL long long
#define si(x) scanf("%d",&x)
#define sc(x) scanf("%c",&x)
#define sl(x) scanf("%I64d",&x)
#define prl(x) printf("%I64d",x)
#define pri(x) printf("%d\n",x)
#define prs(x) printf("%s\n",x)
typedef pair<int, int> ii;
typedef pair<LL, LL> iil;
typedef pair<ii, int> iii;
typedef pair<ii, ii> iiii;
#define vl vector<ll>
#define vi vector<int>
#define vii vector<ii>
#define vvl vector< vl >
#define vvi vector< vi >
#define vvii vector< vii >
#define pb push_back
#define mem(x,y) memset(x,y,sizeof(x))
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define mod 1000000007
#define max_long_value 9223372036854775807
#define pb push_back

const int  maxn  = 2005;

const LL INF  = mod;

LL rev(LL n){
    LL s = 0;
    while(n!=0){
        s = s*10 + n%10;
        n/=10;
    }
    return s;
}
map<LL , LL> visit , val;
inline void solve(void){
    int t;
    cin >>t;
    int Tnum = 1;
    while(t--){
        LL r, c , N;
        cin >> r >> c >> N;
        LL l = r*c;
        LL max_mask = 1<<(l);
        LL uh = INF;
        int a[40][40];
        for(LL mask  = 0;mask < max_mask ;mask++){
            if(__builtin_popcount(mask) == N){
                for(int i=0;i<r;i++){
                    for(int j=0;j<c;j++){
                        a[i][j] = 0;
                    }}
                for(int i=0;i<r;i++){
                    for(int j=0;j<c;j++){
                        LL num = c*i + j;
                        if(mask & (1<<num)){
                            a[i][j] = 1;
                        }
                    }
                }
                /*   for(int i=0;i<r;i++){
                 for(int j=0;j<c;j++){
                 cout <<a[i][j] <<" ";
                 }
                 cout <<endl;
                 }*/
                LL tmp = 0;
                for(int i=0;i<r;i++){
                    for(int j=0;j<c;j++){
                        if(a[i][j] == 1){
                            for(int k=0;k<2;k++){
                                for(int m=0;m<2;m++){
                                    if(k==m)continue;
                                    if((i+k) <r && (j+m) < c){
                                        if(a[i+k][j+m]==1)tmp++;
                                    }
                                }
                            }
                        }
                    }
                }
                uh = min(uh , tmp);
            }
            
        }
        cout << "Case #"<<Tnum<<":  "<<uh<<endl;
        Tnum++;
    }
}
void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
int main(int argc, const char * argv[]){
    init();
    solve();
    return 0;
}