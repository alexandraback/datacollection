#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


#define FOR(i,n) for(int i=0; i<n; i++)

void usefile(const string& a){
    if(a!="std" && a!="s"){
        freopen( (a + ".in").c_str(), "r", stdin);
        freopen( (a + ".out").c_str(), "w", stdout);
    }
}

template<typename T>
void print(const vector<T>& vec){
    FOR(i, vec.size()){
        cout << vec[i] << ((i==vec.size()-1)?'\n':' ');
    }
}

template<typename T>
void print(T vec[], int n){
    FOR(i, n){
        //cout << vec[i] << ((i==n-1)?'\n':' ');
        cout << vec[i] << endl;
    }
}

template<typename T>
int input(T vec[]){
    int n;
    cin >> n;
    FOR(i,n) cin >> vec[i];
    return n;
}

template<typename T>
int input(vector<T>& vec){
    int n;
    cin >> n;
    vec.clear(); vec.resize(n);
    FOR(i,n) cin >> vec[i];
    return n;
}


typedef long long db;
const double eps = 1e-7;
int sgn(db a){ return a<-eps? -1 : a>eps; } //返回double 型的符号

struct Point2D
{
    db x, y;
    int id;
    Point2D(db _x=0, db _y=0):x(_x), y(_y){}

    void input() { cin >> x >> y; }
    void output() { cout << " " << x << " " << y << endl;}

    db len2() { return x*x + y*y; }

    bool operator == (const Point2D &t) const{
    return sgn(x-t.x) == 0 && sgn(y-t.y) == 0;
    }
    bool operator < (const Point2D &t) const{
        if( sgn(x-t.x)==0 ) return y < t.y;
        else return x < t.x;
    }

    Point2D operator - (const Point2D &t) const
    { return Point2D(x-t.x, y-t.y); }

    db operator ^ (const Point2D &t) const{//dot product
        return x*t.x + y*t.y;
    }
    db operator * (const Point2D &t) const{//cross product
        return x*t.y - y*t.x;
    }

};


Point2D pbase;
bool polarSortCmp(const Point2D& a, const Point2D &b)
{
    return ( (a-pbase)*(b-pbase) > 0) ||
    (abs((a-pbase)*(b-pbase)) <= 0 && a-pbase.len2() < b-pbase.len2());
}

int Graham(Point2D co[] , int &cn , Point2D ps[] , int n)
{//co 中保存凸包的点，cn 为凸包点数，ps 为原来点集，n 为原来点数
    int i, u, p;
    for(u = 0, i = 1; i < n; ++i){
        if((ps[i].y < ps[u].y + eps && ps[i].x < ps[u].x - eps)
        ||ps[i].y < ps[u].y - eps ) {u = i;}
    }
    swap(ps[u], ps[0]);
    pbase = ps[0]; //记录左下点
    sort(ps + 1, ps + n, polarSortCmp); //极角排序
    co[0] = ps[0];
    co[1] = ps[1];
    p = 2; //记录凸包中点数
    for(i = 2; i < n; ++i)
    {   //保留了除凸包上最后两点之间的点以外的所有凸包上的点
        while((co[p-1]-co[p-2])*(ps[i]-co[p-2])<-eps){ //改为ep 不保留多余点
            --p;
            if(p == 1) break;
        }
        co[p++] = ps[i];
    }
    cn = p; return p; //返回凸包点数
}


bool p_on_edge(Point2D p, Point2D co[], int n)
{
    co[n] = co[0];
    for(int i=0; i<n; i++){
        if ( ((p-co[i]) * (p-co[i+1])) == 0  &&
             ((p-co[i]) ^ (co[i+1] - p)) >= 0 ) return true;
    }
    return false;
}


const int MAXN = 20;


Point2D origin_tree[MAXN];
Point2D tree[MAXN];
Point2D convex[MAXN];
int N;
int res[MAXN];

void read(){
    cin >> N;
    for(int i=0; i<N; i++){
        origin_tree[i].input();
        origin_tree[i].id = i;
    }
}

void construct(int pat)
{
    int pn = 0;
    for(int i=0; i<N; i++){
        if( (pat>>i)&1 ){
            tree[pn++] = origin_tree[i];
        }
    }

    if(pn <= 3){
        for(int i=0; i<N; i++){
            if( (pat>>i)&1 ) res[i] = min(res[i], N - pn);
        }
        return;
    }

    int cn;
    Graham(convex, cn, tree, pn);
    for(int i=0; i<N; i++){
        if( (pat>>i)&1 ) {
            if(p_on_edge(origin_tree[i], convex, cn)){
                res[i] = min(res[i], N - pn);
//                if(pat == (1<<N)-1 ){
//                cout << "point ";
//                origin_tree[i].output();
//                cout << " on edge " << endl;
//                }
            }
        }
    }

}


int solve(){
    FOR(i,N) res[i] = N;
    for(int i=1; i<(1<<N); i++){
        construct(i);
    }
}

int main()
{
    usefile("C");
    int T;
    cin >> T;

    FOR(ca, T){
        read();
        solve();
        cout << "Case #" << ca + 1 << ":" << endl;
        print(res, N);
    }
    return 0;
}
