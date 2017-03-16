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

int gcd(int a, int b){
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int mcm(int a, int b){
    return (a/gcd(a, b))*b;
}

int solve(int n, int m, int v[]){
    int tiempo = 0;
    if(n == 1 || m == 1)
        return 1;
    int avance = v[0], suma = 0;
    for(int i = 1; i < n; i++){
        avance = mcm(avance, v[i]);
    }
//    printf("avance %d\n", avance);
    for(int i = 0; i < n; i++){
        suma += (avance/v[i]);
    }
//    printf("suma %d\n", suma);
    int salto = m%suma;
//    printf("saltos %d %d %d\n", m, salto, m/suma);
    m = salto;
    if(m == 0){
        int i = 1;
        for(; i < n; i++){
            if(v[i] != v[i-1])
                break;
        }
        if(i == n)
            return n;
        return 1;
    }
    for(tiempo = 0; ; tiempo++){
        int i;
        for(i = 0; i < n && m > 0; i++){
            if(tiempo%v[i] == 0){
                m--;
            }
        }
        if(m == 0)
            return i;
    }

    return -1;
}

int main(){
	int n, m, casos, v[10];
	scanf("%d", &casos);
	for(int i = 1; i <= casos; i++){
        scanf("%d%d", &n, &m);
        for(int j = 0; j < n; j++){
            scanf("%d", &v[j]);
        }
        printf("Case #%d: %d\n", i, solve(n, m, v));
	}
	return 0;
}
