#include<bits/stdc++.h>
typedef long long int uli;
using namespace std;

const int mx = 20;
struct pt{
    uli x,y;
    int idx;
    pt(uli x, uli y):x(x),y(y){}
    pt(){}
    bool operator <(pt a)const{
        if(y!=a.y) return y<a.y;
        return x<a.x;
    }
    pt operator -(pt a){
        return pt(x-a.x,y-a.y);
    }
};
uli cross(pt a, pt b){ return a.x*b.y-a.y*b.x; }
bool ccw(pt a, pt b, pt c){
//    return cross(b-a,c-b)>0;
    return cross(b-a,c-b)>=0;
}

pt dp[mx],pts[mx],hull[mx+mx],base;
int n,h;

bool cmp(pt a, pt b){
    uli c = cross(a-base,b-base);
    if(c!=0) return c>0;
    if(a.y!=b.y) return a.y<b.y;
    return a.x<b.x;
}

void chull(){
    sort(pts,pts+n);
    base = pts[0];
    sort(pts+1,pts+n,cmp);
    pts[n] = pts[0];
    h = 0;
    for(int i=0;i<=n;i++){
        while(h>=2 && !ccw(hull[h-2],hull[h-1],pts[i]))
            h--;
        hull[h++] = pts[i];
    }
    for(int i=0;i<n;i++){
        if(cross(pts[n-1]-base,pts[i]-base)==0){
            hull[h++]=pts[i];
        }
    }

}

int ans[mx];
int main(){
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int t,nn;
    scanf("%d",&t);

    for(int tt=1;tt<=t;tt++){
        scanf("%d",&nn);
        for(int i=0;i<nn;i++){
            scanf("%lld %lld",&dp[i].x,&dp[i].y);
            dp[i].idx=i;
        }
        for(int i=0;i<mx;i++)ans[i]=nn;

        for(int b=1;b<(1<<nn);b++){
            //          cout<<"________"<<endl;
            //          cout<<"b="<<b<<endl;
            int rem=__builtin_popcount(b);
            n=0;
            for(int i=0;i<nn;i++){
                if(b&(1<<i)){
                    pts[n++]=dp[i];
                }
            }
            //          cout<<"ch of ";for(int i=0;i<n;i++)cout<<"("<<pts[i].x<<";"<<pts[i].y<<")";cout<<endl;
            chull();
            //            cout<<"ans=> ";for(int i=0;i<h;i++)cout<<hull[i].idx<<"=("<<hull[i].x<<";"<<hull[i].y<<")";cout<<endl;
            //            cout<<"setting value=>"<<nn-rem<<endl;
            for(int i=0;i<h;i++){
                int ix=hull[i].idx;
                ans[ix]=min(ans[ix],nn-rem);
            }
        }
        printf("Case #%d:\n",tt);
        for(int i=0;i<n;i++){
            printf("%d\n",ans[i]);
        }

    }
    return 0;
}


