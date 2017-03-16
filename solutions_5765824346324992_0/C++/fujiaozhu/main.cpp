#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using  namespace std;

typedef long long ll;

const double eps = 0.001;

vector<int> vec;
int t, n, m, res, a[1010];

bool judge(ll time){
    ll sum = 0;
    vec.clear();
    for(int i = 0; i < n; i ++){
        sum += ceil(time / a[i] + eps);
        if(time % a[i] == 0) vec.push_back(i + 1);
    }
    if(sum >= m){
        ll sz = sum - vec.size();
        if(sz >= m) return true;
        ll tmp = m - sz;
        res = vec[tmp - 1];
        return true;
    }
    return false;
}


int main(){
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("data.out", "w", stdout);
    cin >> t;
    for(int cas = 1; cas <= t; cas ++){
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i ++)
            scanf("%d", &a[i]);
        ll l = 0, r = (ll)m * 1000000;
        while(l <= r){
            ll mid = l + (r - l) / 2;
            if(judge(mid)) r = mid - 1;
            else l = mid + 1;
        }

        printf("Case #%d: %d\n", cas, res);
    }
    return 0;
}
