#include <bits/stdc++.h>
#define _ printf("\n");
#define sc1(a) scanf("%d", &a)
#define sc2(a,b) scanf("%d %d", &a, &b)
#define sc3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sc4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define iz(b) if(b==0) { break; }
#define pb(a) push_back(a)
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3fLL
#define mst(a, b) memset(a, b, sizeof a)
#define fr(i,a,b) for(int i=(a); i < (b); i++)
#define fe(i,a,b) for(int i=(a); i <= (b); i++)
#define mp(a,b) make_pair(a,b)
#define st first
#define pv(a, i) for(int i =0 ; i < (a.size()+0 ); i++ ) {printf("%d ",a[i]); if(i==a.size() - 1 )_  }
#define pvp(a, i) for(int i =0 ; i <(a.size()+0 ); i++ ) {printf("%d %d ~ ",a[i].st, a[i].nd); if(i==a.size() - 1 )_  }
#define nd second
#define EPS 1e-7
#define PI acos(-1)
using namespace std;
typedef vector<int> vi;
typedef long long int ll;
typedef pair<int,int> ii; 
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef pair<char, int> ci;

int N,M,K;

int des[4][2] = {{1,0}, {-1,0 } , {0,1}, {0,-1}};
bool val(int x,int y){ 
	return !(x <0 || x >= N || y <0 || y >= M );
}

int grid[17][17];
bool ok[17][17];

ii get(){
	int r = 0;
	ii id;
	fr(i,0,N){
		fr(j,0,M){
			if(!ok[i][j]) continue;
			if(grid[i][j]  > r ) {
				id = mp(i,j);
				r = grid[i][j];
			}
			
		}	
	}
	return id;
}

int cnt(int x, int y){
	int  cnt = 0;
	int dx, dy;
	fr(i,0,4){
		dx = x + des[i][0], dy= y + des[i][1];
		if(!val(dx,dy) || !ok[dx][dy]) continue;
		cnt++;
	}
	return cnt;
	
}


int main (int argc, char const* argv[]) {
	int caso;
	sc1(caso);
	int s =0;
	fe(T,1,caso){
		s =0;
		sc3(N,M,K);
		fr(i,0,N) fr(j,0,M) ok[i][j] =1;
		fr(i,0,N){
			fr(j,0,M){
				grid[i][j] = cnt(i,j);
			//printf("%d ", grid[i][j]);
				s += grid[i][j];
			}
			//_
		}
		ii p;
		if( K <= ((N*M)+2-1)/2 ) {
			s = 0;
		}
		else{ 
			K = N*M - K;
		//	printf("K: %d | s: %d \n", K, s) ;
			int dx, dy;
			while(K--){
				p = get();
				s -= 2*grid[p.st][p.nd];
				grid[p.st][p.nd] = 0;
				//printf("p: %d %d\n", p.st, p.nd) ;
				ok[p.st][p.nd] =0;
				fr(i,0,4){
					dx = p.st + des[i][0], dy = p.nd + des[i][1];
					if(!val(dx,dy)) continue;
					grid[dx][dy]--;
				}
			
				if(0){
				printf("GRID: | s: %d \n", s);
				fr(i,0,N){
				fr(j,0,M){
				
				printf("%d ", grid[i][j]);					}  _ } 
			
				}
			}
			s/=2;
		}
		printf("Case #%d: %d\n", T, s);
		
		

		
		
		
		
	}
	
	
	
	return 0;
}











