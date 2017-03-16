#include<bits/stdc++.h>
using namespace std;
const double eps=1.0e-8;
typedef complex<double> point;
typedef vector<point> polygon;
struct polygon_convex{
    polygon p;
    polygon_convex(int sz=0){
        p.resize(sz);
    }
};
bool equal(const point& a, const point& b) { return abs(a-b)<eps;}
inline double cross(const point& a, const point& b) { return (conj(a)*b).imag();}
inline int dlcmp(const double& x){
    return x<-eps?-1:x>eps;
}
bool cmp_less(const point& a, const point& b){
    return a.real()!=b.real()?a.real()<b.real():a.imag()<b.imag();
}
polygon_convex convex_hull(polygon a){
    polygon_convex res(2*a.size()+5);
    sort(a.begin(),a.end(),cmp_less);
    int m=0, n=a.size();
    for(int i=0; i<n; i++){
        while(m>1&&dlcmp(cross(res.p[m-1]-res.p[m-2],a[i]-res.p[m-2]))<0) --m;
        res.p[m++]=a[i];
    }
    int k=m;
    for(int i=n-2;i>=0;--i){
        while(m>k&&dlcmp(cross(res.p[m-1]-res.p[m-2],a[i]-res.p[m-2]))<0) --m;
        res.p[m++]=a[i];
    }
    res.p.resize(m);
    if(a.size()>1) res.p.resize(m-1);
    return res;
}
polygon p, p2;
polygon_convex c;
int ans[15];
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int t; cin>>t;
    for(int cs=1; cs<=t; cs++){
        int n, x, y; cin>>n;
        p.clear();
        for(int i=0; i<n; i++){
            scanf("%d%d",&x,&y);
            p.push_back(point(x,y));
            ans[i]=100;
        }
        for(int s=(1<<n)-1; s>0; s--){
            p2.clear();
            for(int i=0; i<n; i++){
                if(s>>i&1){
                    p2.push_back(p[i]);
                }
            }
            c=convex_hull(p2);
            int ret=n-__builtin_popcount(s);
            for(int i=0; i<n; i++){
                if(s>>i&1){
                    if(ans[i]>ret) for(auto v: c.p){
                        if(equal(v,p[i])){
                            ans[i]=ret;
                        }
                    }
                }
            }
        }
        printf("Case #%d:\n",cs);
        for(int i=0; i<n; i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}
