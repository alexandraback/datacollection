#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int n;

struct STR{
    int eng[110], len[110], nl;
    char s[110];
}p[110];

int main() {
    freopen("A-large.in", "r", stdin);
    //freopen("A.txt", "r", stdin);
    freopen("A-l.txt", "w", stdout);
    int cse, g = 1, i, j, a, b, k, tp, res, mi, mx, min_op;
    bool ok;
    scanf("%d", &cse);
    while(cse--) {
        scanf("%d", &n);
        for(i = 0; i < n; ++i) {
            scanf("%s", p[i].s);
            for(j = 0; p[i].s[j]; ++j) {
                if(j > 0 && p[i].s[j] != p[i].s[j - 1]) {
                    p[i].len[p[i].nl] = tp;
                    tp = 1;
                    p[i].nl++;
                    p[i].eng[p[i].nl] = p[i].s[j] - 'a';
                }
                else if(!j) {
                    tp = 1;
                    p[i].nl = 0;
                    p[i].eng[p[i].nl] = p[i].s[j] - 'a';
                }
                else {
                    tp++;
                }
            }
            p[i].len[p[i].nl] = tp;/*
            for(j = 0; j <= p[i].nl; ++j) {
                printf("~~%d %d %d\n", p[i].nl, p[i].eng[j], p[i].len[j]);
            }*/
        }
        ok = true;
        res = 0;
        for(i = 1; i < n && ok; ++i) {
            if(p[i].nl != p[0].nl) {
                //printf("here %d %d %d\n", i, p[i].nl, p[0].nl);
                ok = false;
                break;
            }
            for(j = 0; j <= p[0].nl; ++j) {
                if(p[0].eng[j] != p[i].eng[j]) {
                    ok = false;
                    break;
                }
            }
        }
        if(ok) {
            for(i = 0; i <= p[0].nl; ++i) {
                mi = 110;
                mx = 1;
                for(j = 0; j < n; ++j) {
                    mi = min(mi, p[j].len[i]);
                    mx = max(mx, p[j].len[i]);
                }
                min_op = 1100000;
                for(j = mi; j <= mx; ++j) {
                    tp = 0;
                    for(k = 0; k < n; ++k) {
                        tp += abs(j- p[k].len[i]);
                    }
                    min_op = min(min_op, tp);
                }
                res += min_op;
                //printf("~%d %d\n", i, min_op);
            }
        }
        if(ok) {
            printf("Case #%d: %d\n", g++, res);
        }
        else {
            printf("Case #%d: Fegla Won\n", g++);
        }
    }
    //system("PAUSE");
    return 0;
}
