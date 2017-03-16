#include <bits/stdtr1c++.h>

#define MAX 15
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define write() freopen("output.txt", "w", stdout)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

typedef struct {
    long long x, y;
}Point;

Point P[MAX], CH[MAX<<1];

int cmp(const void *i, const void *j) {
    Point *a, *b;
    a = (Point *)i, b = (Point *) j;
    if(a->y != b->y)
        return a->y - b->y;
    return a->x - b->x;
}

long long Cross(Point *o, Point *a, Point *b) {
    return (a->x - o->x)*(b->y - o->y) - (a->y - o->y)*(b->x - o->x);
}

int ConvexHull(int N) {
    qsort(P, N, sizeof(Point), cmp);
    int i, m = 0, t;
    for(i = 0; i < N; i++) {
        while(m >= 2 && Cross(&CH[m-2], &CH[m-1], &P[i]) <= 0)
            m--;
        CH[m++] = P[i];
    }
    for(i = N-1, t = m+1; i >= 0; i--) {
        while(m >= t && Cross(&CH[m-2], &CH[m-1], &P[i]) <= 0)
            m--;
        CH[m++] = P[i];
    }

    return m;
}

int n, X[15], Y[15], ar[1 << 15];

double dis(double x1, double y1, double x2, double y2){
    double x = (x1 - x2);
    double y = (y1 - y2);
    return sqrt((x * x) + (y * y));
}

bool compare(int a, int b){
    return (__builtin_popcount(a) < __builtin_popcount(b));
}

int main(){
    read();
    write();
    int T = 0, t, i, j, k, bitmask, x, y, np, len;

    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%d %d", &X[i], &Y[i]);

        int lim = 1 << n;
        for (i = 0; i < lim; i++) ar[i] = i;
        sort(ar, ar + lim, compare);

        printf("Case #%d:\n", ++T);
        for (i = 0; i < n; i++){
            for (j = 0; j < lim; j++){

                np = 0, len = 0;
                bitmask = ar[j];
                if (bitmask & (1 << i)) continue;

                for (k = 0; k < n; k++){
                    if (!(bitmask & (1 << k))){
                        P[np].x = X[k];
                        P[np].y = Y[k];
                        np++;
                    }
                }

                int flag = 0;
                len = ConvexHull(np);
                for (k = 0; (k + 1) < len; k++){
                    double x = dis(X[i], Y[i], CH[k].x, CH[k].y);
                    double y = dis(X[i], Y[i], CH[k + 1].x, CH[k + 1].y);
                    double z = dis(CH[k].x, CH[k].y, CH[k + 1].x, CH[k + 1].y);
                    if (fabs(x + y - z) <= 1e-5){
                        flag = 1;
                        break;
                    }
                }


                if (flag){
                    printf("%d\n", __builtin_popcount(bitmask));
                    break;
                }
            }
        }
    }
    return 0;
}
