#include <bits/stdc++.h>
using LL = long long ;

struct Point {
    int x,y;

    Point(int _x = 0,int _y = 0) : x(_x),y(_y) {}

    Point operator + (const Point &rhs) const {
        return Point(x + rhs.x,y + rhs.y);
    }

    Point operator - (const Point &rhs) const {
        return  Point(x - rhs.x,y - rhs.y);
    }

    LL operator * (const Point &rhs) const {
        return (LL) x * rhs.y - (LL) y * rhs.x;
    }

    LL operator % (const Point &rhs) const {
        return (LL) x * rhs.x + (LL) y * rhs.y;
    }

    void read() {
        scanf("%d%d",&x,&y);
    }
};

bool polar_cmp(const Point &lhs,const Point &rhs) {
    if ((LL) lhs.y * rhs.y <= 0) {
        if (lhs.y > 0 || rhs.y > 0) return lhs.y < rhs.y;
        if (lhs.y == 0 && rhs.y == 0) return lhs.x < rhs.x;
    }
    return lhs * rhs > 0;
}

const int N = 3000 + 5;
Point backup[N];
Point points[N];
int answer[N];
int n;

void work() {
    if (n <= 3) {
        for (int i = 0; i < n; ++ i) {
            answer[i] = 0;
        }
        return ;
    }
    for (int center = 0; center < n; ++ center) {
        int tot = 0;
        for (int i = 0; i < n; ++ i) {
            if (center != i) {
                points[tot++] = backup[i] - backup[center];
            }
        }
        std::sort(points,points + tot,polar_cmp);
        int vmin = tot;
        for (int i = 0,j = 1; i < tot; ++ i) {
            while (j != i && (points[i] * points[j] >= 0))
                j = (j + 1) % tot;
            int tmp = tot;
            if (i < j) {
                tmp -= j - i;
            } else {
                tmp -= tot - i + j;
            }
            vmin = std::min(vmin,tmp);
        }
        answer[center] = vmin;
    }
}

int main(int argc,char **args) {
    if (argc > 1) {
        freopen(args[1],"r",stdin);
        freopen("data.txt","w",stdout);
    }
    
    int cas,ca = 0;
    scanf("%d",&cas);
    while (cas--) {
        scanf("%d",&n);
        for (int i = 0; i < n; ++ i) {
            backup[i].read();
        }
        work();
        printf("Case #%d:\n",++ca);
        for (int i = 0; i < n; ++ i) {
            printf("%d\n",answer[i]);
        }
    }
}
