#include <cstdio>
#include <algorithm>
#include <complex>

#define X real()
#define Y imag()
#define sign(x) ((x < -EPS) ? -1 : x > EPS)

using namespace std;

typedef complex<double> Point;

const double EPS = 1E-6;
const int N = 3333;

int n;
Point p[N];
int ans[N];

double cross(const Point a, const Point b){
    return a.X * b.Y - a.Y * b.X;
}

double cross(const Point a, const Point b, const Point c){
    return cross(b - a, c - a);
}

void work(int id){
    for(int i = 0; i < n; i++){
        if (i == id) continue;
        int a = 0, b = 0;
        for(int j = 0; j < n; j++){
            int f = sign(cross(p[i], p[id], p[j]));
            if (f < 0) a++;
            if (f > 0) b++;
        }
        ans[i] = min(ans[i], min(a, b));
        ans[id] = min(ans[id], min(a, b));
    }
}

int main(){
    int test;
    scanf("%d", &test);
    for(int cas = 1; cas <= test; cas++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            ans[i] = (n > 1) ? n : 0;
            int x, y;
            scanf("%d%d", &x, &y);
            p[i] = Point(x, y);
        }
        for(int i = 0; i < n; i++){
            work(i);
        }
        printf("Case #%d:\n", cas);
        for(int i = 0; i < n; i++){
            printf("%d\n", ans[i]);
        }
    }
}
