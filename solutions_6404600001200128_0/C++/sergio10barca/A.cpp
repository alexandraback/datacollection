#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdio>
#define x first
#define y second
#define IN(x, n) (0 <= (x) && (x) < n)
#define MAX 1010
#define MOD 1000000007
using namespace std;

typedef long long int entero;
typedef pair<int, int> Point;


pair<int, int> solve(int n, int v[]){
    int dif = 0;
    pair<int, int> p(0, 0);
    for(int i = 1; i < n; i++){
        p.first += (v[i] < v[i-1] ? v[i-1]-v[i] : 0);
        dif = max(dif, v[i-1]-v[i]);
    }
//    printf("%d\n", dif);
    for(int i = 0; i < (n-1); i++){
        p.second += min(dif, v[i]);
    }
    return p;
}

int main(){
	int n, casos, v[10000];
	scanf("%d", &casos);
	for(int i = 1; i <= casos; i++){
        scanf("%d", &n);
        for(int j = 0; j < n; j++){
            scanf("%d", &v[j]);
        }
        pair<int, int> p = solve(n, v);
        printf("Case #%d: %d %d\n", i, p.first, p.second);
	}
	return 0;
}
