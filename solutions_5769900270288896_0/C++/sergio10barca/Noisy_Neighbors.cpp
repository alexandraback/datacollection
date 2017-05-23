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
#define MAX 1000010
#define MOD 1000000007
using namespace std;

int solve(int r, int c, int n){
    int m[17][17], lim = 1<<(r*c), mejor = 1000;
    if(n == 0)
        return 0;
    for(int i = 1;i < lim;i++){
        int j, cont = 0, fil = 0, col = 0;
        memset(m, 0, sizeof(m));
        for(j = i; j > 0; j>>=1){
            if(j&1){
                cont++;
                m[fil][col] = 1;
            }
            col++;
            if(col == c){
                fil++, col = 0;
            }
        }

        if(cont == n){
            int resp = 0;
            for(int a = 0; a < r; a++){
                for(int b = 0; b < c; b++){
                    if(m[a][b]){
                        if(m[a+1][b])
                            resp++;
                        if(m[a][b+1])
                            resp++;
                    }
                }
            }
            mejor = min(resp, mejor);
        }
//        printf("valor %lld pasos %lld\n", valor, pasos);
    }
    return mejor;
}


int main(){
	int casos, r, c, n;
	cin >> casos;
	for(int i = 1; i <= casos; i++){
        cin >> r >> c >> n;
        cout << "Case #"<<i<<": "<<solve(r, c, n) << endl;
	}
	return 0;
}
