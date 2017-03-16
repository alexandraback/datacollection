#include <stdio.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <iostream>
using namespace std;
#define LL long long
#define MIN(a, b) (((a)<(b))?(a):(b))
#define MAX(a, b) (((a)>(b))?(a):(b))
#define ABS(x) (((x)<0)?(-(x)):(x))
struct Point{
    LL x, y;
    Point(){
        x = 0;
        y = 0;
    }
    Point(LL _x, LL _y){
        x = _x;
        y = _y;
    }
    
    void print()const{
        printf("(%lld, %lld)\n", x, y);
    }
    
    LL cross(const Point &P){
        return x * P.y - P.x * y;
    }
    
    LL dot(const Point &P){
        return x * P.x + y * P.y;
    }
    
    Point operator - (const Point &P)const{
        return Point(x - P.x, y - P.y);
    }
    
    Point operator + (const Point &P)const{
        return Point(x + P.x, y + P.y);
    }
    
    double distance(const Point &P){
        double dx = x - P.x;
        double dy = y - P.y;
        return sqrt(dx*dx + dy*dy);
    }
};

//------- Compare functions------

bool operator <(const Point &P, const Point &Q){//Default comparison (by x, then by y)
    if(P.x == Q.x){
        return P.y < Q.y;
    }
    return P.x < Q.x;
}

//------------------------------

struct Segment{
    Point P, Q;
    Segment(const Point &_P, const Point &_Q){
        P = _P;
        Q = _Q;
    }
    
    bool contains(const Point &R){
        // First check if the point is in the segment's range
        if(R.x < MIN(P.x, Q.x) || MAX(P.x, Q.x) < R.x){
            return false;
        }
        if(R.y < MIN(P.y, Q.y) || MAX(P.y, Q.y) < R.y){
            return false;
        }
        //If the triangle P,Q,R is degenerated then they're collinear
        bool in_line = (R-P).cross(Q-P) == 0;
        return in_line;
    }
};

struct Line{
    Point P, Q;
    Line(Point _P, Point _Q){
        P = _P;
        Q = _Q;
        if(P.x==Q.x && P.y==Q.y){
            printf("Warning: P==Q\n");
        }
    }
    
    bool contains(const Point &R)const{
        //If the triangle P,Q,R is degenerated then they're collinear
        bool in_line = (R-P).cross(Q-P) == 0;
        return in_line;
    }
    
    double distance(const Point &R){
        double d = (Q-P).cross(R-P)/P.distance(Q);
        return ABS(d);
    }
    
    int intersection(const Line &L, double &x, double &y)const{
        /*
        If the lines intersect at a unique point, then there exist two unique 
        scalars u, v such that
            P + u(Q-P) = L.P + v(L.Q-L.P)
        then
            (Q - P)u + (L.P - L.Q)v = L.P - P.
        In matrix form:
            |Qx-Px    L.Px-L.Qx|   | u | = |L.Px - Px|
            |Qy-Py    L.Py-L.Qy|   | v | = |L.Py - Py|
        
        solving for v:
                (Qx - Px)(L.Py - Py) - (Qy - Py)(L.Px - Px)
            v = --------------------------------------------
                (Qx - Px)(L.Py - L.Qy) - (Qy - Py)(L.Px - L.Qx)
                
        and then for u:
                   (L.Px-L.Qx)(L.Py - Py) - (L.Py-L.Qy)(L.Px - Px)
            u = -  ------------------------------------------------
                   (Qx - Px)(L.Py - L.Qy) - (Qy - Py)(L.Px - L.Qx)
        
        */
        if(L.contains(P) && L.contains(Q)){//the same line
            return -1;
        }
        
        LL den = (Q.x - P.x)*(L.P.y - L.Q.y) - (Q.y - P.y)*(L.P.x - L.Q.x);
        if(den == 0){
            return 0;
        }
        
        LL num = (Q.x - P.x)*(L.P.y - P.y) - (Q.y - P.y)*(L.P.x - P.x);
        double v = (double)num/(double)den;
        
        num = ((L.P.x-L.Q.x)*(L.P.y - P.y) - (L.P.y-L.Q.y)*(L.P.x - P.x))*-1LL;
        double u = (double)num/(double)den;
        
        x = (L.P.x + v*(L.Q.x-L.P.x));
        y = (L.P.y + v*(L.Q.y-L.P.y));
        //We didn't need u
        return 1;
    }
};

vector<Point> convex_hull(vector<Point> &P){
    //Andrew's algorithm. 
    if(P.empty()){
        return vector<Point>();
    }
    int n = P.size();
    vector<Point> hull(2*n);
    sort(P.begin(), P.end());
    int k=0;//current number of elements in the convex hull
    //Lower hull.
    for(int i=0;i<n;++i){
        //remove all segments that P[i] is to the right of
        while((k>=2) && (hull[k-1]-hull[k-2]).cross(P[i]-hull[k-2])<=0){
            --k;
        }
        hull[k] = P[i];
        ++k;
    }
    int lower_size = k;
    //Upper hull.
    for(int i=n-2;i>=0;--i){//the first and last points must be part of the lower hull
        //remove all segments that P[i] is to the right of
        while((k >= 1+lower_size) && (hull[k-1]-hull[k-2]).cross(P[i]-hull[k-2])<=0){
            --k;
        }
        hull[k] = P[i];
        ++k;
    }
    //Note: the first and last points are the same
    hull.resize(k-1);
    return hull;
}

bool point_in_convex_polygon(const Point &Q, const vector<Point> &P){
    int n = P.size();
    for(int i=0;i<n;++i){
        int j = (i+1)%n;
        LL cp = (P[j]-P[i]).cross(Q-P[i]);
        if(cp == 0){
            return true;
        }
    }
    return false;
}

vector<Point> points;
int N;
vector<int> solve(){
    vector<int> sol(N);
    for(int i=0;i<N;++i){
        sol[i] = N-1;
    }
    for(int mask=1;mask<(1<<N);++mask){
        vector<Point> P;
        for(int i=0;i<N;++i)if(mask&(1<<i)){
            P.push_back(points[i]);
        }
        int opt = N-P.size();
        
        if(P.size()<=3){
            for(int i=0;i<N;++i)if(mask&(1<<i)){
                if(opt<sol[i]){
                    sol[i] = opt;
                }
            }
        }else{
            vector<Point> H = convex_hull(P);
            for(int i=0;i<N;++i)if(mask&(1<<i)){
                if(point_in_convex_polygon(points[i], H)){
                    if(opt<sol[i]){
                        sol[i] = opt;
                    }
                }
            }
        }
    }
    return sol;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int c=1;c<=T;++c){
        scanf("%d", &N);
        points.clear();
        for(int i=0;i<N;++i){
            int x, y;
            scanf("%d %d",&x, &y);
            points.push_back(Point(x, y));
        }
        vector<int> sol = solve();
        printf("Case #%d:\n", c);
        for(unsigned i=0;i<sol.size();++i){
            printf("%d\n", sol[i]);
        }
    }
    return 0;
}