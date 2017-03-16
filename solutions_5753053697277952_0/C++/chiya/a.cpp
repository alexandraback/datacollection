#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<cmath>
#include<bitset>
#define rep(i,a,b) for(int i=a,_b=b;i<=_b;i++)
#define per(i,a,b) for(int i=a,_b=b;i>=_b;i--)
#define For(i,b) for(int i=0,_b=b;i<_b;i++)
#define upmax(a,b) if ((a)<(b)) (a)=(b)
#define upmin(a,b) if ((a)>(b)) (a)=(b)
using namespace std;

int n,T,tot;
struct node{
    int x;
    char p;
}a[1200];

bool cmp(node a,node b){return a.x>b.x;}

int main(){
//freopen("A.in","r",stdin);
//freopen("A.out","w",stdout);
    cin>>T;
    rep(ca,1,T){
        cin>>n;
        cout<<"Case #"<<ca<<":";
        rep(i,1,n) cin>>a[i].x;
        rep(i,1,n) a[i].p='A'+i-1;
        rep(i,1,n) tot+=a[i].x;
        while(tot){
            sort(a+1,a+n+1,cmp);
            cout<<' '<<a[1].p;
            a[1].x--;
            tot--;
            sort(a+1,a+n+1,cmp);
            if (a[1].x>tot/2){
                cout<<a[1].p;
                a[1].x--;
                tot--;
            }
        }
        cout<<endl;
    }
}