#include <bits/stdc++.h>
using namespace std;

const int dx[]={0,1,0,-1}, dy[]={1,0,-1,0};

int m, n, k;

int solvex(int dd, int k){
    vector<vector<int> > a(m, vector<int>(n, 0));
    int res = 0;
    for (int x = 0; x < m; x++)
        for (int y = 0; y < n; y++) if ((x+y)%2 == dd){
            if (k > 0){a[x][y] = 1; k--;}
        }
    if (k == 0) return res;
    vector<int> L;
    for (int x = 0; x < m; x++)
        for (int y = 0; y < n; y++) if ((x+y)%2 == 1 - dd){
            int V = 0, nx, ny;
            for (int i = 0; i < 4; i++){
                nx = x + dx[i]; ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n){
                    if (a[nx][ny]) V++;
                }
            }
            L.push_back(V);
            //printf("ADD %d\n", V);
        }
    sort(L.begin(), L.end());
    for (int i = 0; i < k; i++) res += L[i];
    return res;
}

int solve(){
    scanf("%d%d%d", &m, &n, &k);
    int res = solvex(0, k);
    res = min(res, solvex(1, k));
    return res;
}

int main(){
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int t, cases = 0; scanf("%d", &t);
    while (t--){
    	printf("Case #%d: %d\n", ++cases, solve());
    }
	return 0;
}
