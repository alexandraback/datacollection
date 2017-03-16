#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAXN 25

struct Point {
    long long x,y;
    Point(){}
    Point(long long x_,long long y_){
        x = x_ ;
        y = y_ ;
    }
    friend bool operator == (const Point&a , const Point&b){
        return a.x == b.x && a.y == b.y ;
    }
} P[MAXN],S[MAXN],init[MAXN];

int ans[MAXN] ;
int N,top,n;

long long Dis(const Point& p1,const Point& p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y) ;
}

long long Cross(const Point& p1,const Point& p2,const Point& p3,const Point& p4) {
    return (p2.x - p1.x) * (p4.y - p3.y) - (p2.y - p1.y) * (p4.x - p3.x) ;
}
long long Cross(const Point&p1 , const Point&p2 , const Point&p3){
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x) ;
}

bool cmp(const Point& p1,const Point& p2) {
    long long C = Cross(P[0],p1,P[0],p2);
    return C ? C > 0 : Dis(P[0],p1) < Dis(P[0],p2);
}

void Pole_Point() {
    int id;
    Point pp = P[id = 0];
    for(int i = 1; i < n; i++)
        if(P[i].y < pp.y || P[i].y == pp.y && P[i].x < pp.x)
            pp = P[i] , id = i;
    P[id] = P[0] , P[0] = pp;
}

void Convex_Hull() {

    sort(P + 1 , P + n , cmp);
    S[0] = P[0],S[top = 1] = P[1];
    for(int i = 2 ; i < n ; i++) {
        while(top && Cross(S[top-1],S[top],S[top],P[i]) <= 0)
            --top;
        S[++top] = P[i];
    }
}

bool online(const Point &a , const Point &b , const Point &c){
    if (a == b || a == c) return true ;
    if (a.x >= min(b.x , c.x) && a.x <= max(b.x , c.x))
    if (a.y >= min(b.y , c.y) && a.y <= max(b.y , c.y)){
        return Cross(a , b , c) == 0 ;
    }
    return false ;
}

bool check_segment(const Point& a){

    for (int i = 0 ; i <= top ; i++)
        if (online(a , S[i] , S[((i == top) ? 0 : i + 1)])) return true ;

    return false ;
}

void check(int state){

    n = 0 ;
    for (int i = 0 ; i < N ; i++)
        if ((state >> i) & 1)
            P[n++] = init[i] ;
    if (n < 3) return ;
    Pole_Point();
    Convex_Hull();
    for (int i = 0 ; i < N ; i++)
        if ((((state >> i) & 1) == 1) && check_segment(init[i]))
            ans[i] = min(ans[i] , N - n) ;
}

int main() {
    freopen("input.txt" , "r" , stdin) ;
    //freopen("output.txt" , "w" , stdout) ;
    int _ , cas = 0;
    scanf("%d",&_) ;
    cout << online(Point(50,50) , Point(0,0) , Point(50,50)) ;
    while(_--) {
        scanf("%d",&N) ;
        for(int i = 0 ; i < N ; i++)
            cin >> init[i].x >> init[i].y ;
        for (int i = 0 ; i < N ; i++) ans[i] = 0x3F3F3F3F ;
        for (int i = 0 ; i < (1 << N) ; i++) check(i) ;
        printf("Case #%d:\n",++cas) ;
        for (int i = 0 ; i < N ; i++)
            cout << ans[i] << endl ;
    }
    return 0;
}
