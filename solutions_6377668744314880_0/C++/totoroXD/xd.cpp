#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef long long LL;
const int MOD=1000000007;
const double EPS=1e-12;

//  Convec Hull
//  By totoroXD
struct vec{
    LL x,y;
    int id;
    vec(LL _x=0LL, LL _y=0LL, int _id=0): x(_x), y(_y),id(_id){}
    LL len2(){ return x*x+y*y; }
    vec operator - (const vec &that)const{
        return vec{x-that.x, y-that.y};}
    LL operator * (const vec &that)const{//cross
        return x*that.y-y*that.x;}
}base;
int clock(vec o, vec a, vec b){//clock:1, line:0, counter:-1
    a=a-o;  b=b-o;
    if(a*b<0)return 1;
    else if(a*b==0)return 0;
    else return -1;
}
bool cmp_x(vec a, vec b){
    return a.x<b.x || (a.x==b.x && a.y<b.y);
}
bool cmp_ang(vec a, vec b){//counter
    a=a-base;
    b=b-base;
    if(a*b!=0)return 0<a*b;
    else if(a.y<0) return a.len2()<b.len2();
    else return a.len2()>b.len2();
}
struct point_set{
    vector<vec> p;
    void clear(){p.clear();}
    void add(vec a){p.push_back(a);}
    void convex_hull(){
        if(p.size()<3)return;
        swap(p[0], *min_element(p.begin(), p.end(), cmp_x));//minx->miny
        base = p[0];
        sort(p.begin()+1, p.end(), cmp_ang);//counter

        vector<vec> stk;
        stk.push_back(p[0]);
        stk.push_back(p[1]);

        p.push_back(p[0]);
        for(int i=2; i<p.size(); i++){
            while(1<stk.size() && 0<clock(*(stk.end()-2), *(stk.end()-1), p[i])){
                if(i==p.size()-1 && stk.size()<=2)break;//line
                stk.pop_back();
            }
            stk.push_back(p[i]);
        }
        stk.pop_back();
        p=stk;
    }
}ps;

int n;
vec pt[22];

bool input(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
        scanf("%lld%lld",&pt[i].x,&pt[i].y);
        pt[i].id=i;
    }
	return 1;
}
int res[22];
void solve(){
    static int cas=1;
    printf("Case #%d:\n",cas++);
    fill(res,res+n, n-1);
    ps.clear();
    for(int i=0; i<n; i++){
        ps.add(pt[i]);
    }
    for(int s=0; s<(1<<n);s++){
        ps.clear();
        int cnt=0;
        for(int i=0; i<n; i++){
            if(s&(1<<i)) ps.add(pt[i]),cnt++;
        }
        ps.convex_hull();
        for(auto p:ps.p){
            res[p.id]=min(res[p.id],n-cnt);
            // printf("point %d\n",p.id+1);
        }
    }
    for(int i=0; i<n; i++)printf("%d\n",res[i]);
}

int main()
{
	int zz;
	scanf("%d",&zz);
	while(zz--){
	    input();
		solve();
	}
    return 0;
}
/*

2

5
0 0
10 0
10 10
0 10
5 5

9
0 0
5 0
10 0
0 5
5 5
10 5
0 10
5 10
10 10
*/