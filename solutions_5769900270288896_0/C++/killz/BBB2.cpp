#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin(), unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;
template<typename A, typename B> inline bool mina(A &x, B y) { return (x > y)? (x=y,1):0; }
template<typename A, typename B> inline bool maxa(A &x, B y) { return (x < y)? (x=y,1):0; }

int i, n, k, N, M, K;
int v[101][101];

void run(int x, int y, int C){
    if(C > K) return ;
    if(y == M){
        y = 0;
        x++;
    }
    if(x == N){
		if(C != K) return;
        int cnt = 0;
        for(int a=0;a<N;a++) for(int b = 0;b<M;b++){
            if(v[a][b] == 1){
                if(v[a+1][b] == 1) cnt++;
                if(v[a][b+1] == 1) cnt++;
            }
        }
        k = min(k, cnt);
        return;
    }
    v[x][y] = 1;
    run(x, y+1, C+1);
    v[x][y] = 0;
    run(x, y+1, C);
}

int main(){

freopen("C:\\Users\\Jui\\Downloads\\B-small-attempt0 (2).in", "r", stdin);
//freopen("BBB.txt", "w", stdout);

int a, b, c, d;
int TT, RR;
cin >> TT;
REPI(RR, TT){
	cin >> N >> M >> K;
	k = 2e9;
    run(0, 0, 0);
	printf("Case #%d: %d\n", RR, k);
}



return 0;
}
