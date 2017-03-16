#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

int t, n, a[100100];

void solve(int ind) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    int x = 0, y = 0;
    for(int i = 0; i < n-1; i++) {
        if(a[i] > a[i+1]) x += a[i] - a[i+1];
    }
    int v = 0;
    for(int i = 0; i < n-1; i++) {
        v = max(v, a[i]-a[i+1]);
    }
    for(int i = 0; i < n-1; i++) {
        y += min(v, a[i]);
    }
    printf("Case #%d: %d %d\n", ind, x, y);
}

int main(){
    
    scanf("%d", &t);
    
    for(int i = 1; i <= t; i++) solve(i);
        
    return 0;
}
