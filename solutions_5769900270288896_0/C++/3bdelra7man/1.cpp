#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
#define sc(x) scanf("%d", &x)
#define scl(x) scanf("%I64d", &x)
#define loop(i,s,e) for(int i=s ; i<e ; i++)
#define rep(i,s,e) for(int i=s ; i>=e ; i--)
#define INF 1e6
#define MOD 1000000007  
#define f first
#define s second
#define EPS 1e-6
#define Rd freopen("in.txt", "r", stdin)
#define Wr freopen("out.txt", "w", stdout)
#define PS push_back
#define M_PI           3.14159265358979323846
//#define DFS_WHITE -1
//#define DFS_BLACK 0

bool arr[20][20];
int r, c, n, res;
		
void solve(int x){
	if(x == r*c){
		int cc = 0;
		loop(i,0,r){
			loop(j,0,c){
				if(arr[i][j]) 
					cc++;
				//printf("%d", arr[i][j] );
			}
			//printf("\n");
		}	
		//printf("%d %d\n", cc, n);
		if(cc != n) return;
		int walls = 0;
		loop(i,0,r){
			loop(j,0,c){
				if(arr[i][j] == 0) continue;
				if(i-1 >= 0 && arr[i-1][j]) walls++;
				if(j-1 >= 0 && arr[i][j-1]) walls++;
			}
		}
		res = min(res, walls);
		return;
	}

	int i = x/c;
	int j = x%c;

	arr[i][j] = 1;
	solve(x+1);
	arr[i][j] = 0;
	solve(x+1);
}

int main(){
	Rd;
	Wr;
	int T;
	sc(T);
	loop(t,0,T){
		sc(r); sc(c); sc(n);
		res = INF;
		solve(0);
		printf("Case #%d: %d\n", t+1, res);
	}
	return 0;
}