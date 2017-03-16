#include <bits/stdc++.h>
using namespace std;
const int N  = 1004;
typedef long long ll;
int a[N];
int n, m;

struct point{
    ll time;
    int id;
    point(){};
    point(ll x, int y){time = x, id = y;};
}p[N];
bool check(ll mid){
    int i;
    ll sum = 0;
    for(i = 1; i <= m; i++){
        if(mid % a[i])  {
            sum += mid / a[i] + 1;
        }else sum += mid / a[i];
    }
    if(sum >= (ll)n)return false;
    return true;
}

bool cmp(point x, point y){
    if(x.time == y.time)    return x.id < y.id;
    return x.time < y.time;
}


int main(){
    //B-small-attempt0.in
     freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int TC, tc, i;
    ll ans, low, high, mid;
    scanf("%d", &TC);
    for(tc = 1; tc <= TC; tc++){
        scanf("%d%d", &m, &n);
        low = 0, high = (ll)n *100000;
        for(i = 1; i <= m; i++)scanf("%d", &a[i]);
        while(low <= high){
            mid = (low + high) >> 1ll;
            if(check(mid)){
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        int sum = 0;

        for(i = 1; i <= m; i++){
            if(ans % a[i])  {
                sum += ans / a[i] + 1;//printf("%d %d\n", sum, 21 / 7);
            }else sum += ans / a[i];
        }
        n -= sum;//printf("%lld %d\n", ans, n);
        for(i = 1; i <= m; i++){
            p[i] = point(ans % a[i] ? a[i] - ans%a[i] : 0, i);
        }
        sort(p + 1, p + m + 1, cmp);
        for(i = 1; i <= m; i++){
            if(n > 1)   {
                n--;
                continue;
            }else break;
        }
        printf("Case #%d: %d\n", tc, p[i].id);
    }

    return 0;
}
