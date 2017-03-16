#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long LL;

struct node{
    LL t;
    int pos;
};

int n, b;
LL m[1010];
node  bb[1010];

bool cmp(const node &a, const node &b){
    if (a.t != b.t)
        return a.t < b.t;
    else
        return a.pos < b.pos;
}

int divi(LL l, LL r){
    while (l < r - 1){
//        cout << l<<' '<< r<<endl;
        LL mid = (l + r) >> 1;
        LL minn = mid;
        int pos = 0;
        LL sum = 0;
        for (int i = 0; i < b; i++){
            sum += LL(ceil((mid + 0.0) / m[i]));
        }
        if (sum < n)
            l = mid;
        else
            r = mid;
    }
    LL sum = 0;
    for (int i = 0; i < b; i++){
        sum += LL(ceil((l + 0.0) / m[i]));
        bb[i].t = m[i] * LL(ceil((l + 0.0) / m[i]));
        bb[i].pos = i + 1;
    }
    sort(bb, bb + b, cmp);
    return bb[n - sum - 1].pos;
}

int main(){
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int  T;
    scanf("%d", &T);
    for (int ca = 1; ca <= T; ca++){
        scanf("%d%d", &b, &n);
        for (int i = 0; i < b; i++){
            scanf("%lld", &m[i]);
        }
        if (n <= b){
            printf("Case #%d: %d\n", ca, n);
        }else{
            int ans = divi(0, m[0] * n);
            printf("Case #%d: %d\n", ca, ans);
        }
    }

}
