#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

struct Point{
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}

    Point operator-(const Point &p)const{ return Point(x-p.x,y-p.y); }
    Point operator+(const Point &p)const{ return Point(x+p.x,y+p.y); }
    Point operator*(double u)const{ return Point(x*u,y*u); }
    double operator^(const Point &p)const{ return x*p.y-y*p.x; }
    double operator*(const Point &p)const{ return x*p.x+y*p.y; }

    void read(){ scanf("%lf%lf",&x,&y); }
    double len()const{ return sqrt(x*x+y*y); }

    Point setLen(double l)const{
        double u = l/len();
        return Point(x*u,y*u);
    }

    int out()const {
        printf("(%.2lf %.2lf)\n", x, y);
    }
};

double angle(const Point &a, const Point &b){
    int w = (fless(0,a^b))?1:-1;
    return acos((a*b)/a.len()/b.len())*w;
}

Point II = Point(0, 1);
int DEBUG = 1;

struct Comper {
    bool operator()(const Point &a, const Point &b) {
        return angle(a, II) > angle(b, II);
        /*
        double w = a^b;
        if (fequal(w, 0)) return a.len() < b.len();
        return w > 0;
        */
    }
}comper;

int main(){
    int tt; scanf("%d",&tt);
    for (int ti=1;ti<=tt;ti++){
        int n; scanf("%d", &n);
        Point P[n];
        for (int i=0;i<n;i++) {
            P[i].read();
        }


        printf("Case #%d:\n",ti);
        int m = n-1;

        DEBUG =false;

        //printf("m %d\n", m);
        for (int x=0; x<n; x++) {
            Point A[m]; 
            for (int i=0;i<m;i++) {
                if (i < x) {
                    A[i] = P[i] - P[x];
                } else {
                    A[i] = P[i+1] - P[x];
                }
            }
            // sort points by x
            sort(A, A+m, comper);

            if (DEBUG) {
            P[x].out();
            printf("-----\n");
            for (int i=0;i<m;i++) {
                (A[i]).out();
            }
            printf("-----\n");
            }
            
            
            // process
            int ans = 1;
            for (int st=0, size=2; size<=m && st < m; ) {
                int j = (st + size - 1)%m;
                if (DEBUG) printf("- %d %d: %d (%d)\n", st, j, size, ans);
                if (fless(A[st] ^ A[j], 0)) {
                    st++;
                    size--;
                } else {
                    if (DEBUG) printf("  - yes\n");
                    if (ans < size) {
                        ans = size;
                    }

                    size ++;
                }
            }

            printf("%d\n", m==0 ? 0 : m-ans);
        }

    }
    return 0;
}
