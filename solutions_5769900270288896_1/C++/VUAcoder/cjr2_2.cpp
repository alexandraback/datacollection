/*
AUTHOR : VUAcoder
LANGUAGE : C++
PROBLEM :
*/
#pragma comment(linker, ”/STACK:36777216“)
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
#include<set>
#include<fstream>
#include<cfloat>
using namespace std;
#define PI (2.*acos(0.))
#define EPS 1e-9
#define ZERO(x)     (fabs(x) < EPS)
#define EQ(a,b)     (ZERO((a)-(b)))
#define LESSER(a,b) (!EQ(a,b) && (a)<(b))
#define GREATER(a,b)(!EQ(a,b) && (a)>(b))
#define GETBIT(x,i) (x&(1<<i))
#define SETBIT(x,i) (x|(1<<i))
#define FORab(i,a,b) for(typeof(b) i=(a);i<=(b);i++)
#define FOR(i,n) FORab(i,0,(n)-1)
#define FOR1(i,n) FORab(i,1,n)
#define FORit(it,a) for( typeof((a).begin()) it=(a).begin();it!=(a).end();it++)
#define all(a) (a).begin(),(a).end()
#define ms(a,b) memset((a),(b),sizeof(a))
#define pb push_back
#define sz(a) (int)a.size()
#define in(a,b,c) ((a) <= (b) && (b) <= (c))
#define px first
#define py second
#define __eXYZ__
#ifdef __eXYZ__
//USE THESE FOR DEBUG
#define RFILE(a)    freopen(a, "r", stdin)
#define WFILE(a)    freopen(a, "w", stdout)
#define _r(arg) {dbg,arg; dbg.start(); }
#define _n(arg...) {_r(#arg " ==> ");dbg,arg; }
#define _(arg...) { _n(arg); dbg.nl(); }
#else
#define RFILE(a)
#define WFILE(a)
#define _n(arg) {}
#define _n(arg...) {}
#define _(arg...) {}
#endif


typedef long long  LL;
typedef vector<int>   vi;
typedef pair<int,int>  pii;

template<class A, class B> ostream &operator<<(ostream& o, pair<A,B>& p) { //pair print
    return o << "("<<p.first<<", "<<p.second<<")";
}

template<class T> ostream& operator<<(ostream& o, const vector<T>& v) { //vector print
    o << "{";FORit(it, v) o << *it << ", "; return o << "}";
}

struct debugger
{
    ostream &out; bool first;
    void start() { first = true; }
    debugger(ostream& out):out(out) {start();}
    void nl() { out << endl; start(); }
    // Taken from rudradevbasak
    template<class T> debugger& operator,(T& v) {
        if(first) first = false; else out << ", ";
        out << v; return *this;
    }
    template<class T> debugger& operator,(pair<T*,int> arr) { //array print
        out << "{";
            FOR(i, arr.second) { out << arr.first[i] << ", "; }
        out << "}";
        return *this;
    }
} dbg(cerr);
int grid[20][20];
int side(int r, int c){
    return 2*(r+c) -4;
}
int corner(int r, int c){
    if((r*c)%2)return 0;
    return 4;
}
int rightway(int r, int c, int n){
    if(n <= (r*c+1)/2 + side(r,c)/2)return (n -(r*c+1)/2)*3;
    return  (n -(r*c+1)/2 - side(r,c)/2)*4 + (side(r,c)/2)*3;
}
int leftway(int r, int c, int n){
    if(n <= (r*c)/2 + 4)return (n -(r*c)/2)*2;
    else if(n <= ((r*c)/2 + side(r,c)/2)) return (n -(r*c)/2 -4)*3 +8;
    return  (n -(r*c)/2 - side(r,c)/2)*4 + (side(r,c)/2 -4)*3 +8;
}

int main()
{
    RFILE("input.txt");
    WFILE("outputr2_2_large.txt");
    int t, cn=1;
    cin>>t;
    while(t--){
        int r, c, n;
        int ans=1e9;
        cin>>r>>c>>n;
         cout<<"Case #"<<cn++<<": ";
        if(r>c) swap(r,c);
        if(r==1){
            if(n <= (c+1)/2)cout<<0<<endl;
            else {
                if(c%2==1){
                    cout<<2*(n-(c+1)/2)<<endl;
                }else {
                    cout<<1+(n-(c+1)/2-1)*2<<endl;
                }
            }
        }
        else{
            if(n<= (r*c+1)/2){
                cout<<0<<endl;
            }else{
                if((r*c)%2==1){
                    cout<<min(rightway(r,c,n), leftway(r,c,n))<<endl;
                }else{
                    if(n <= (r*c+1)/2 + 2)cout<<(n -(r*c+1)/2)*2<<endl;
                    else if(n <= (r*c+1)/2 + side(r,c)/2)cout<<(n -(r*c+1)/2 -2)*3 + 4<<endl;
                    else cout<<(n -(r*c+1)/2 - side(r,c)/2)*4 + (side(r,c)/2 -2)*3 +4<<endl;
                }
            }
        }


        /*FOR(i,1<<(r*c)){
            if(__builtin_popcount(i) != n)continue;
            ms(grid,0);
            FOR(j,r*c){
                if((1<<j)&i){
                    grid[j%r][j/r]=1;
                }
            }
            int cnt=0, dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
            FOR(k,r){
                FOR(j,c){
                    FOR(l ,4){
                        if(dx[l] +k <0 || dx[l] +k>=r ||
                           dy[l] +j <0 || dy[l] +j>=c )continue;
                            if(grid[dx[l] +k][dy[l] +j] && grid[k][j])cnt++;
                    }
                }
            }
            cnt/=2;
            ans=min(ans,cnt);
        }*/

    }
    return 0;
}

