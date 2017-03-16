/*
***************************************************************************************************************

							Author : Yash Sadhwani

**************************************************************************************************************
*/
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<deque>
#include<map>
#include<set>
#include<stack>
#include<stdlib.h>
#include<math.h>
#include<queue>
#include<functional>
using namespace std;
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define sc(x) scanf("%c",&x)
#define vl vector<ll>
#define vi vector<int>
#define vvl vector< vl >
#define vvi vector< vi >
#define pb push_back
#define mod 1000000007
#define mem(x,y) memset(x,y,sizeof(x))
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define max_int_value 2147483647
#define max_long_value 9223372036854775807
#define maxn 2005
#define  INF  mod


//qsort(ww,cc,sizeof(tp),compare);
/*int compare(const void *a,const void *b){
	ll y=((((tp*)a)->w)-(((tp*)b)->w));
	if(y>0)return 1;
	else if(y==0)return 0;
	else return -1;
}*/


map<ll , ll> visit , val;
inline void solve(void){
    int t; si(t);
    int Tnum = 1;
    while(t--){
        ll r, c , N;
        sl(r); sl(c); sl(N );
        ll l = r*c;
        ll max_mask = (1<<l);
        ll uh = INF;
        int a[40][40];
        for(ll mask  = 0;mask < max_mask ;mask++){
            if(__builtin_popcount(mask) == N){
                for(int i=0;i<r;i++){
                    for(int j=0;j<c;j++){
                        a[i][j] = 0;
                    }
                }
                for(int i=0;i<r;i++){
                    for(int j=0;j<c;j++){
                        ll num = c*i + j;
                        if(mask & (1<<num)){
                            a[i][j] = 1;
                        }
                    }
                }
                ll tmp = 0;
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
int main(){
    solve();
    return 0;
}