#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<memory.h>
#include<assert.h>
#include <unistd.h>
#include <wait.h>
using namespace std;
typedef long long ll;
const int __limitofthreads = 4;
vector<pid_t> __ids;
char __str[256];

const int N = 1e5+5;

int x[N], y[N], h1[N], h2[N];

ll vp(ll ax, ll ay, ll bx, ll by, ll cx, ll cy){
    return (ax-cx)*(by-cy) - (ay-cy)*(bx-cx);
}

struct point{
    int x, y;
};


set<int> ch(vector<int> p){
    if(p.size()==1){
        return {p[0]};
    }
    sort(p.begin(), p.end(), [](int i, int j){
         pair<int,int> p1(x[i],y[i]);
         pair<int,int> p2(x[j],y[j]);
         return p1<p2;
         });
    point pa = {x[p[0]], y[p[0]]};
    point pb = {x[p.back()], y[p.back()]};
    int m1 = 0, m2 = 0;
    h1[m1++] = p[0];
    h2[m2++] = p[0];
    for(int i=1;i<p.size();++i){
        point q = {x[p[i]], y[p[i]]};
        if(i+1==p.size() || vp(pb.x,pb.y,q.x,q.y,pa.x,pa.y)>0){
            while(m1>1 && vp(q.x,q.y,x[h1[m1-2]],y[h1[m1-2]],x[h1[m1-1]],y[h1[m1-1]])>=0) --m1;
            h1[m1++] = p[i];
        }
        if(i+1==p.size() || vp(pb.x,pb.y,q.x,q.y,pa.x,pa.y)<0){
            while(m2>1 && vp(q.x,q.y,x[h2[m2-2]],y[h2[m2-2]],x[h2[m2-1]],y[h2[m2-1]])<=0) --m2;
            h2[m2++] = p[i];
        }
    }
    vector<int> h;
    
    for(int i=0;i<m1;++i) h.push_back(h1[i]);
    for(int i=m2-2;i>0;--i) h.push_back(h2[i]);
    int m = h.size();
    
    set<int> res;
    for(int i=0;i<p.size();++i){
        for(int j=0;j<m;++j){
            if(vp(x[p[i]],y[p[i]],x[h[j]],y[h[j]],x[h[(j+1)%m]],y[h[(j+1)%m]])==0) res.insert(p[i]);
        }
    }
    
    return res;
}

point p[N];
inline int tp(const point&p){
    if(p.y==0){
        return p.x>0 ? 0 : 2;
    }else return p.y>0 ? 1 : 3;
}
bool cmp(const point&a, const point&b){
    int ta = tp(a);
    int tb = tp(b);
    if(ta==tb) return vp(a.x,a.y,b.x,b.y,0,0)>0;
    return ta<tb;
}
int calc(int s, int n){
    int m = 0;
    for(int i=0;i<n;++i) if(i!=s) p[m++] = {x[i]-x[s],y[i]-y[s]};
    sort(p,p+m,cmp);
    //for(int i=0;i<m;++i) cout<<p[i].x<<','<<p[i].y<<' '; cout<<endl;
    int res = 1e9;
    int cnt = 0;
    for(int i=0,j=1;i<m;++i){
        while(vp(p[i].x,p[i].y,p[j].x,p[j].y,0,0)>0){
            ++cnt;
            ++j;
            if(j==m) j = 0;
        }
        //cout<<i<<' '<<j<<' '<<cnt<<"!"<<endl;
        res = min(res, cnt);
        --cnt;
    }
    return res;
}

void solve(int test){
    /*+++start read data+++*/
    
    int n;
    cin>>n;
    for(int i=0;i<n;++i) cin>>x[i]>>y[i];
    
    /*---end read data---*/
    if(__ids.size()>=__limitofthreads) wait(0);
    pid_t __id = fork();
    if(__id>0){
        __ids.push_back(__id);
        return ;
    }else{
        sprintf(__str, "thread%d.out", test);
        freopen(__str,"w",stdout);
    }
    /*+++start solution and write output+++*/
    cout<<"Case #"<<test<<": "<<endl;
    
    vector<int> ans(n,n);
    vector<int> ans2(n,n);
    
    vector<int> p(n);
    for(int i=0;i<n;++i) p[i]=i;
    set<int> h = ch(p);
    for(int i=0;i<n;++i) if(h.count(i)){
        ans[i] = 0;
    }else{
        ans[i] = calc(i,n);
    }
    /*
    for(int ms=1;ms<(1<<n);++ms){
        p.clear();
        int del = 0;
        for(int i=0;i<n;++i) if(ms>>i&1) p.push_back(i);
        else ++del;
        set<int> h2 = ch(p);
        for(int i : h2) ans2[i] = min(ans2[i], del);
    }*/
    
    for(int i=0;i<n;++i){
        //cout<<(ans[i]==ans2[i])<<endl;
        //cout<<ans2[i]<<' '<<ans[i]<<endl;
        cout<<ans[i]<<endl;
        //assert(ans2[i]==ans[i]);
    }
    
    /*---end solution---*/
    sprintf(__str, "test #%d ok.%c", test,10);
    cerr<<__str;
    exit(0);
}

int main(){
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        solve(i);
    }
    
    /*combining outputs*/
    for(pid_t __id : __ids) waitpid(__id,0,0);
    int __bufsize = 1<<16;
    char *__buf = new char[__bufsize];
    for(int i=1;i<=t;++i){
        sprintf(__str, "thread%d.out", i);
        FILE *f = fopen(__str, "r");
        while(fgets(__buf, __bufsize, f)) printf("%s",__buf);
        fclose(f);
        remove(__str);
    }
    
    return 0;
}
