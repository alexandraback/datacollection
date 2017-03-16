
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <climits>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define RREP(i,n) for(int i=(int)n-1; i>=0; i--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();++i)
#define ALL(c) (c).begin(), (c).end()

typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > pipii;
typedef vector<int> vi;

const int INF = 1e9;
const int MOD = 1e9+7;

int r, c, n;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int calc(vector<vi> &g){
    int res = 0;
    REP(i, g.size()){
        REP(j, g[i].size()){
            REP(k, 4){
                if(i + dx[k] < 0 || j + dy[k] < 0) continue;
                if(i + dx[k] >= r || j + dy[k] >= c) continue;
                if(g[i][j] && g[i+dx[k]][j+dy[k]]) res++; 
            }
        }
    }
    return res;
}

int dfs(int xy, int num, vector<vi> g){
    if(xy >= r * c) return num == n ? calc(g) : INF;
    //cout << xy << ":" << num << endl;
    if(num == n) return calc(g);
    int x = xy / c;
    int y = xy % c;
    //cout << "x : y << " << x << "*" << y << endl;
    int res = dfs(xy+1, num, g);
    g[x][y] = 1;
    res = min(dfs(xy+1, num+1, g), res);
    return res; 
}

int main(void){
    int t;
    cin >> t;
    REP(tt, t){
        cin >> r >> c >> n;
        vector<vi> g(r, vi(c, 0));
        int ans = dfs(0, 0, g); 

        cout << "Case #" << tt + 1 << ": " << ans / 2 << endl;
    }

    return 0;
}

