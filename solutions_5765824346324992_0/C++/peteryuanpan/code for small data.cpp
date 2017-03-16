//Hello. I'm Peter.
#include<cstdio>
#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<functional>
#include<cctype>
#include<ctime>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
typedef long double ld;
//const double pi=acos(-1.0);
//const double eps=1e-9;
#define peter cout<<"i am peter"<<endl
#define input freopen("data.txt","r",stdin)
#define randin srand((unsigned int)time(NULL))
#define INT (0x3f3f3f3f)*2
#define LL (0x3f3f3f3f3f3f3f3f)*2
#define gsize(a) (int)a.size()
#define len(a) (int)strlen(a)
#define slen(s) (int)s.length()
#define clr(a) memset(a,0,sizeof(a))
#define clr_true(a) memset(a,true,sizeof(a))
#define clr_queue(q) while(!q.empty()) q.pop()
#define clr_stack(s) while(!s.empty()) s.pop()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define dep(i, a, b) for (int i = a; i > b; i--)
#define repin(i, a, b) for (int i = a; i <= b; i++)
#define depin(i, a, b) for (int i = a; i >= b; i--)
#define MAXN
#define N 1024
#define M
int b[N],nb,n,a[N];
int main(){
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("outputsmall.txt","w",stdout);
    //    input;
    int T;
    scanf("%d",&T);
    repin(Case,1,T){
        scanf("%d%d",&nb,&n);
        repin(i,1,nb){
            scanf("%d",b+i);
        }
        int lcm=1;
        repin(i,1,nb){
            int d=__gcd(lcm,b[i]);
            lcm=lcm*b[i]/d;
        }
        int nt=0;
        repin(i,1,nb){
            nt+=lcm/b[i];
        }
        n%=nt;
        if(!n) n=nt;
        repin(i,1,nb){
            a[i]=0;
        }
        repin(i,1,n){
            int mini=INT,w=1;
            repin(j,1,nb){
                if(a[j]<mini){
                    mini=a[j];
                    w=j;
                }
            }
            if(mini==0){
                a[w]=b[w];
                if(i==n){
                    printf("Case #%d: %d\n",Case,w);
                }
            }
            else{
                repin(j,1,nb){
                    a[j]-=mini;
                }
                i--;
            }
        }
    }
    return 0;
}




















