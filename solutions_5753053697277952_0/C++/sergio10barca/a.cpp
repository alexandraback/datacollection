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

pair<int, int> a[MAX];


void solve(int n){
    int sum = 0;
    for(int i = 1; i <= n; i++){
        sum += a[i].first;
    }
    while(sum > 0){
        int maximo = 0, cont = 0, v[MAX];
        for(int i = 1; i <= n; i++){
            if(maximo < a[i].first){
                v[0] = i;
                cont = 1;
                maximo = a[i].first;
            }
            else if(maximo == a[i].first){
                v[cont] = i;
                cont++;
            }
        }
 //       printf("%d %d\n", cont, maximo);
        if(cont == 2){
            printf(" %c%c", v[0]+'A'-1, v[1]+'A'-1);
            a[v[0]].first--;
            a[v[1]].first--;
            sum -= 2;
        }
        else{
            printf(" %c", v[0]+'A'-1);
            a[v[0]].first--;
            sum--;
        }
    }
    printf("\n");
    return;
}

int main(){
    int casos, n;
    cin >> casos;
    for(int i = 1; i <= casos; i++){
        cin >> n;
        for(int j = 1; j <= n; j++){
            cin >> a[j].first;
            a[j].second = j;
        }
        printf("Case #%d:", i);
        solve(n);
    }
	return 0;
}
