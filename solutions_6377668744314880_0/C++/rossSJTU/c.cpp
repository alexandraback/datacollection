#include<stdio.h>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;
struct point
{
    point () {}
    point(LL _x,LL _y,int _Id =0 ){
        x = _x;
        y = _y;
        Id = _Id;
    }
    LL x,y;
    int Id;
    LL  det (point o) {
        return x*o.y-o.x*y;
    }
    point operator - (point& o){
        return point(x-o.x,y-o.y);
    }
    bool operator < (const point& o) const{
        if(x!=o.x) return x<o.x;
        return y<o.y;
    }
};
int X[20];
int Y[20];
int ans[20];
vector<point> convex_hull(vector<point> ps)
{
    sort(ps.begin(),ps.end());
    int n = ps.size();
    vector<point> qs(n*2);
    int k = 0;
    for(int i =0;i<n;i++){
        while(k>1&&(qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<0) k--;
        qs[k++] = ps[i];
    }
    for(int i = n-2,t=k;i>=0;i--){
        while(k>t && (qs[k-1]-qs[k-2]).det(ps[i]-qs[k-1])<0) k--;
        qs[k++] = ps[i];
    }
    qs.resize(k-1);
    return qs;
}
int main ()
{
    int T;
    int n,count;
    vector<point> ps;
    scanf("%d",&T);
    for(int _ =1;_<=T;_++){
        ps.clear();
        scanf("%d",&n);
        for(int i =0;i<n;i++){
            scanf("%d%d",&X[i],&Y[i]);
            ans[i] = n;
        }
        for(int mask = 1; mask<(1<<n);mask++){
            ps.clear();
            count = 0;
            for(int i = 0;i<n;i++){
                if(mask&(1<<i)){
                    ps.push_back(point(X[i],Y[i],i));
                    count++;
                }
            }
            ps = convex_hull(ps);
            for(auto x : ps){
                ans[x.Id]  = min(ans[x.Id],n-count);
            }
        }
        printf("Case #%d:\n",_);
        for(int i =0;i<n;i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}