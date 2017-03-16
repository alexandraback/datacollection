#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define mp make_pair

#define count  dsadasd
typedef long long ll;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ldb;


int n, r, c;       // r <= c
int mx[101][10001];
int cnt[101][10001];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
  int count[5];
   
inline bool ok(int x, int y) {
    return x > -1 && x < r && y > -1 && y < c;
}   
int solve_odd() {
    if (n <= r * c / 2 + 1) return 0;         
    int ans = INT_MAX;
    
    fill(count, count + 5, 0);
    int placed = 0;
    for (int i = 0; i < r; i++) {
        for (int j = i & 1; j < c; j += 2)
            mx[i][j] = 1, cnt[i][j] = 0, placed++;
    }
    for (int i = 0; i < r; i++) {
        for (int j = !(i & 1); j < c; j += 2) {
            mx[i][j] = cnt[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                if (ok (i + dx[k], j + dy[k])) cnt[i][j]++;
            }
            count[cnt[i][j]]++;    
        }
    }
    int left = n - placed;
    int ans0 = 0;
    for (int cost = 1; cost <= 4; cost++) {
        if (count[cost] >= left) {
            ans0 += cost * left;
            left = 0;
            break;
        } 
        ans0 += cost * count[cost];
        left -= count[cost];
    }
    assert(left == 0);
    ans = min(ans, ans0);
    
    fill(count, count + 5, 0);
    placed = ans0 = 0;

    for (int i = 0; i < r; i++)
        for (int j = !(i & 1); j < c; j += 2)
            mx[i][j] = 1, cnt[i][j] = 0, placed++;
    for (int i = 0; i < r; i++) {
        for (int j = i & 1; j < c; j += 2) {
            mx[i][j] = cnt[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                if (ok(i + dx[k], j + dy[k]))   cnt[i][j]++;
            }   
            count[cnt[i][j]]++;
        }
    }
    left = n - placed;
    for (int cost = 1; cost <= 4; cost++) {
        if (count[cost] >= left) {
            ans0 += cost * left;
            left = 0;
            break;
        }
        ans0 += cost * count[cost];
        left -= count[cost];
    }
    assert(left == 0); 
    ans = min(ans, ans0);
    return ans;
}
int solve_even() {
    if (n <= r * c / 2) return 0;
    int left = n - r * c / 2;
    for (int i = 0; i < r; i++) 
        for (int j = i & 1; j < c; j += 2)
            mx[i][j] = 1, cnt[i][j] = 0;
    fill(count, count + 5, 0);
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = !(i & 1); j < c; j += 2) {
            mx[i][j] = cnt[i][j] = 0;
            for (int k = 0; k < 4; k++)
                if (ok(i + dx[k], j + dy[k]))   cnt[i][j]++;
            count[cnt[i][j]]++;
        }
    }
    //cerr << left << "\n";
    for (int cost = 1; cost <= 4; cost++) {
        if (left <= count[cost]) {
            ans += cost * left;
            left = 0;
            break;
        }
        ans += cost * count[cost];
        left -= count[cost];
    }
    assert(left == 0);
    return ans;
}
int main() {
//    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++) {
        scanf("%d %d %d", &r, &c, &n);
        if (r > c) swap(r, c);   // r will be <= c
        int ans;
        if ( (r * c) & 1) ans = solve_odd();
        else ans = solve_even();
        printf("Case #%d: %d\n", tc, ans);
    }

    return 0;
}
