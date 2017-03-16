//Mitesh Agrawal
#include <bits/stdc++.h>
using namespace std;
 
#define gc getchar
#define pi(n) printf("%d",n)
#define pin(n) printf("%d\n",n)
#define pis(n) printf("%d ",n)
#define pll(n) printf("%d",n)
#define plls(n) printf("%lld ",n)
#define plln(n) printf("%lld\n",n)
#define ps printf(" ")
#define pn printf("\n")
#define si(n) scanf("%d",&n)
#define sii(n,m) scanf("%d %d",&n,&m)
#define siii(k,n,m) scanf("%d %d %d",&k,&n,&m)
#define rep(i,n) for(i=0;i<n;i++)
#define fu(i,a,n) for(i=a;i<=n;i++)
#define fd(i,n,a) for(i=n;i>=a;i--)
#define ll long long
#define ii pair<int,int>
#define iii pair<ii,int>
#define ff first 
#define ss second
#define mod 1000000007
#define MAXN 100005 

bool cmp(ii a, ii b){
     return a.ff>b.ff;
}

int main()
{
     freopen ("A-small-attempt0.in","r",stdin); 
     freopen ("A-small-attempt0.out","w",stdout); 
     int i,j,n,sum,t,flag,k;
     si(t);
     for(int qw=1;qw<=t;qw++){
          printf("Case #%d: ",qw);
          si(n);
          vector<int> v(n);
          rep(i,n)
               si(v[i]);
          while(1){
               sum=0;
               rep(i,n)
                    sum+=v[i];
               if(sum==0)
                    break;

               rep(i,n){
                    if(v[i]<1)
                         continue;
                    v[i]-=1;
                    rep(j,n){
                         if(v[j]<1)
                              continue;
                         v[j]-=1;
                         flag=1;
                         rep(k,n){
                              if(v[k]*2 > sum-2){
                                   flag=0;
                                   break;
                              }
                         }
                         if(flag==1){
                              cout<<(char)(i+'A')<<(char)(j+'A')<<" ";
                              goto here;
                         }
                         v[j]+=1;
                    }
                    v[i]+=1;
               }

               rep(i,n){
                    if(v[i]<1)
                         continue;
                    v[i]-=1;
                    flag=1;
                    rep(j,n){
                         if(v[j]*2 > sum-1){
                              flag=0;
                              break;
                         }
                    }
                    if(flag==1){
                         cout<<(char)(i+'A')<<" ";
                         goto here;
                    }
                    v[i]+=1;
               }
               here:;
          }

          pn;
     }


     return 0;
}      