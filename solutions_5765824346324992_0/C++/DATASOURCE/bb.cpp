#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;

struct point{
    int p;
    long long t;

    friend bool operator < (const point &a, const point &b){
        if(a.t == b.t) return a.p > b.p;
        return a.t > b.t;
    }
};

priority_queue<point> que;

int a[1010];

int main(){
    int t, n, b;
    scanf("%d", &t);
    for(int di = 1; di <= t; di++){
        int ans;
        if(!que.empty()) que.pop();
        scanf("%d%d", &b, &n);
        for(int i = 1; i <= b; i++)
            scanf("%d", &a[i]);
        if(b >= n) ans = n;
        else{
            point aa;
            for(int i = 1; i <= b; i++){
                aa.p = i, aa.t = a[i];
                que.push(aa);
            }
            for(int i = b + 1; i < n; i++){
                aa = que.top();
                que.pop();
                aa.t += a[aa.p];
                que.push(aa);
            }
            ans = que.top().p;
        }
        printf("Case #%d: %d\n", di, ans);
    }
    return 0;
}

