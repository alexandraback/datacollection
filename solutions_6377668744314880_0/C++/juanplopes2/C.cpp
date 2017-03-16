#include <iostream>
#include <algorithm>
#define ull long long
using namespace std;

struct Point {
    ull i, x, y, a;
    Point() { }
    
    inline bool operator<(const Point& b) const {
        return x!=b.x ? x<b.x : y<b.y;
    }
};

Point P[10000];
int H[10000];
int hull;

inline bool byI(const Point& a, const Point& b) {
    return a.i < b.i;
}


Point m(int i) {
    return P[H[hull-i]];
}

bool isLeft(Point a, Point b, Point c) {
    return ((b.x - a.x)*(c.y - a.y) - (b.y - a.y)*(c.x - a.x)) > 0;
}

bool isInHull(int somePoint, int mask, int N) {
    hull = 0;
    for(int i=0; i<N; i++) {
        if ((1<<i) & mask) continue;

        while(hull >= 2 && isLeft(m(1), m(2), P[i])) hull--;
        H[hull++] = i;
    }
    
    hull--;
    
    for(int i=N-1, k=hull; i>=0; i--) {
        if ((1<<i) & mask) continue;

        while(hull >= k+2 && isLeft(m(1), m(2), P[i])) hull--;
        H[hull++] = i;
    }
    
    for(int i=0; i<hull; i++)
        if (H[i] == somePoint)
            return true;

    return false;
}

int bc(int i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main() {
    int test=0, tests; cin >> tests;
    int N;
    while(cin >> N) {
        for(int i=0; i<N; i++) {
            cin >> P[i].x >> P[i].y;
            P[i].i = i;
            P[i].a = N;
        }
        sort(P, P+N);
        
        for(int i=0; i<N; i++) { 
            for(int mask=0; mask<(1<<N); mask++) {
                int wei = bc(mask);
                
                if (N-wei < 1 or wei >= P[i].a) continue;
                
                if (isInHull(i, mask, N))
                    P[i].a = wei;
            }
        }

        sort(P, P+N, byI);
        
        cout << "Case #" << ++test << ":" << endl;
        for(int i=0; i<N; i++) { 
            cout << P[i].a << endl;
        }       
    }
}
