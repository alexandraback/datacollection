#include "iostream"
#include "algorithm"
#include "vector"
#include "set"
#include "map"
#include "cstring"
#include "string"
#include "vector"
#include "cassert"
#include "queue"
#include "cstdio"
#include "cstdlib"
#include "ctime"
#include "cmath"
#include "bitset"

using namespace std;

typedef long long ll;
typedef pair < int, int > ii;

int n;
int a[30];

void solve() {
    scanf("%d", &n);
    priority_queue < ii > Q;
    int rem = 0;
    for(int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        rem += a[i];
        Q.push({a[i], i});
    }
    while(!Q.empty()) {
        int i = Q.top().second, j = -1;
        Q.pop();
        if(!Q.empty()) {
            j = Q.top().second;
            Q.pop();
        }
        putchar('A' + i - 1);
        if(j != -1 and a[j] == a[i] and a[i] + a[j] == rem) {
            putchar('A' + j - 1);
            a[j]--;
            rem--;
        }
        a[i]--;
        rem--;
        if(a[i])
            Q.push({a[i], i});
        if(j != -1 and a[j])
            Q.push({a[j], j});
        putchar(' ');
    }
    puts("");
}

int main () {
    
    freopen("A-large.in.txt", "r", stdin);
    freopen("large.txt", "w", stdout);
    
    int t;
    
    scanf("%d", &t);
    
    for(int tt = 1; tt <= t; tt++) {
        printf("Case #%d: ", tt);
        solve();
    }
    
    return 0;
    
}