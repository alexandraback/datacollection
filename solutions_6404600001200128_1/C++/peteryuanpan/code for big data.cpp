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
int n,a[N],ans;
inline int cal1(){
    int res=0;
    repin(i,2,n){
        if(a[i-1]>a[i]) res+=a[i-1]-a[i];
    }
    return res;
}
inline int cal2(int speed){
    int res=0;
    repin(i,1,n){
        if(i>1){
            int beremain=max(0,a[i-1]-speed);
            if(beremain>a[i]) return INT;
        }
        if(i!=n){
            res+=min(speed,a[i]);
        }
    }
    return res;
}
int main(){
    //input;
    //freopen("A-large (1).in","r",stdin);
    //freopen("outputbig.txt","w",stdout);
    int T;
    scanf("%d",&T);
    repin(Case,1,T){
        printf("Case #%d: ",Case);
        scanf("%d",&n);
        repin(i,1,n){
            scanf("%d",a+i);
        }
        ans=cal1();
        printf("%d ",ans);
        bool ok=true;
        repin(j,2,n){
            if(a[j-1]>a[j]){
                ok=false;
                break;
            }
        }
        if(ok) ans=0;
        else ans=INT;
        repin(j,2,n){
            if(a[j-1]>a[j]) ans=min(ans,cal2(a[j-1]-a[j]));
        }
        printf("%d\n",ans);
    }
    return 0;
}





















