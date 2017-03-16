/*input
4
2
2 2
3
3 2 2
3
1 1 2
3
2 3 1

*/
#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
long long mod=1e9+7;
 
typedef long long unsigned llu;
typedef long long int lld;
typedef long ld;
#define rep(i,a,n) for(long long int i = (a); i <= (n); ++i)
#define repI(i,a,n) for(int i = (a); i <= (n); ++i)
#define repD(i,a,n) for(long long int i = (a); i >= (n); --i)
#define repDI(i,a,n) for(int i = (a); i >= (n); --i)
 
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%lld",&a)
#define sc2(a,b) scanf("%lld%lld",&a,&b)
#define sc3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define scd(a) scanf("%d",&a)
#define scd2(a,b) scanf("%d%d",&a,&b)
#define scd3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define scf(a) scanf("%lf",&a)
#define scf2(a,b) scanf("%lf%lf",&a,&b)
#define scf3(a,b,c) scanf("%lf%lf%lf",&a,&b,&c)
#define prL(a) printf("%lld\n",a)
#define prS(a) printf("%lld ",a)
#define prdL(a) printf("%d\n",a)
#define prdS(a) printf("%d ",a)
#define prfL(a) printf("%lf\n",a)
#define prfS(a) printf("%lf ",a)
#define popcount __builtin_popcountll
#define swap(a,b,t) t=a;a=b;b=t
typedef pair<lld,lld> PA;
 
#define lim 1000003
#define lim2 1003
inline lld sqr(lld x) { return x * x; }
// map<pair<PA,PA>,lld> M;
// map<lld,lld> M,My;
// map<PA,lld> Ms;
// deque<PA> Q;
// map<lld,lld>::iterator it;
// std::ios::sync_with_stdio(false);
 
// multiset<lld> S;
// set<lld> S;
// vector<lld> V[lim];
 
// bool dp[1002][12][12];
// priority_queue<PA> Q;
// lld A[lim],B[lim],C[lim];
lld A[lim],B[lim],P[lim],dp[lim2];
// lld X[lim],Y[lim];
// PA P[lim];
// lld dp[1<<18];
lld one,zero,ansR,numNodes;


lld findGcd(lld a,lld b){
    if(a==0) return b;
    else return findGcd(b%a,a);
}
lld powP(lld a,lld b){
    if(b==0) return 1%mod;
    lld k;
    k=powP(a,b/2);
    k=k*k%mod;
    if(b%2==0) return k;
    else return a*k%mod;
}

lld root(lld a){
    while(A[a]!=a){
        A[a]=A[A[a]];
        a=A[a];
    }
    return a;
}

void unionP(lld a,lld b){
    A[a]=b;
}


int main(){
    // std::ios::sync_with_stdio(false);
    lld T,i,j,h,l,r,k,s,b,c,a,d,q,p,n,m,w,x,y,v,z,t,curr,prev,sum,ans,pos,val,countA,secondMin,indicator;
    sc(T);
    rep(testCase,1,T){
        sc(n);
        p=0;
        rep(i,0,n-1){
            sc(A[i]);
            p+=A[i];
        }
        k=p-1;
        while(1){
            t=0;
            x=0;
            rep(i,0,n-1){
                if(A[i]>t){
                    t=A[i];
                    x=i;
                }
            }
            if(t==0) break;
            P[k]=x;
            A[x]--;
            k--;
        }
        // rep(i,0,p) rep(j,0,p) dp[i][j]=0;
        rep(i,0,p-1){
            A[P[i]]++;
            t=0;
            rep(j,0,n-1){
                if(A[j]>t){
                    t=A[j];
                }
            }
            if(t>(i+1)/2) dp[i]=0;
            else dp[i]=1;
            // printf("i=%lld dp[i]=%lld t=%lld\n",i,dp[i],t );
        }
        k=p-1;
        printf("Case #%lld: ",testCase);
        while(1){
            if(k<1) break;
            if(dp[k-1]==1){
                printf("%c ",int(P[k])+'A' );
                k--;
            }
            else{
                printf("%c%c ",int(P[k])+'A',int(P[k-1])+'A' );
                k-=2;
            }
        }
        printf("\n");
    }
    return 0;
}
