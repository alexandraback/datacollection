//
//  main.cpp
//  C
//
//  Created by Li Qiu on 4/10/15.
//  Copyright (c) 2015 Li Qiu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <cstring>
#include <unordered_map>

using namespace std;
#define mp make_pair
const int inf = 1e8;
const int maxn = 1e4 + 10;
int n;
int ans[maxn];
/*==================================================*\
 | Graham求凸包 O(N * logN)
 | CALL: nr = graham(pnt, int n, res); res[]为凸包点集;
 \*==================================================*/
struct Point { long long x, y; }point[maxn], res[maxn], candi[maxn];
bool mult(Point sp, Point ep, Point op){
    return (sp.x - op.x) * (ep.y - op.y) >= (ep.x - op.x) * (sp.y - op.y);
}


bool operator < (const Point &l, const Point &r){
    return l.y < r.y || (l.y == r.y && l.x < r.x);
}
int graham(Point pnt[], int n, Point res[]){
    int i, len, k = 0, top = 1;
    sort(pnt, pnt + n);
    if (n == 0) return 0; res[0] = pnt[0];
    if (n == 1) return 1; res[1] = pnt[1];
    if (n == 2) return 2; res[2] = pnt[2];
    for (i = 2; i < n; i++) {
        while (top && mult(pnt[i], res[top], res[top-1]))
            top--;
        res[++top] = pnt[i];
    }
    len = top; res[++top] = pnt[n - 2];
    for (i = n - 3; i >= 0; i--) {
        while (top!=len && mult(pnt[i], res[top], res[top-1]))
            top--;
        res[++top] = pnt[i];
    }
    return top; // 返回凸包中点的个数
}

bool onBound(const Point res[], int num, const Point p ){
    //on vertex
    for(int i = 0; i <  num; ++i ) if( res[i].x == p.x && res[i].y == p.y ) return true;
    
    for(int i = 0; i < num; ++i ){
        long long ax = p.x - res[i].x;  long long ay = p.y - res[i].y;
        long long bx = p.x - res[(i + 1) % num].x;  long long by = p.y - res[(i + 1)%num ].y;
        if( ax * by == bx *ay ) return true;
    }
    return false;
    
}

void solve(int tcase){
    printf("Case #%d:\n", tcase);
    fill_n(&ans[0], maxn, inf);
    for(int s = 0; s < (1<<n); ++s){
        int cno = 0;
        for(int i = 0; i < n; ++i ) if( s & (1<<i) ){
            candi[cno++] = point[i];
        }
        sort( candi, candi + cno );
        int num = graham(candi, cno, res );
        for(int i = 0; i < n; ++i ) if( s & (1<<i) ){
            if( onBound(res, num, point[i] ) ){
                bitset<20> b( s );
                ans[i] = min(ans[i], n -  (int)b.count() );
            }
        }
    }
    for(int i = 0; i < n; ++i)
        printf("%d\n", ans[i]);
    
}
int main(int argc, const char * argv[]) {
    freopen("/Users/liqiu/Desktop/C/C.in", "r", stdin );
    freopen("/Users/liqiu/Desktop/C/C.out", "w", stdout );
    int T;
    cin >> T;
    int tcase = 0;
    while(T--){
        cin >> n;
        for(int i = 0; i < n; ++i ){
            cin >> point[i].x >> point[i].y;
        }
        solve(++tcase);
    }
    return 0;
}
