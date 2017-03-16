#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

#define REP(a, b, c) for(long long a=(b); a<(c); a++)

using namespace std;

int R, C, N;
int grid[16][16];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isValid(int x, int y){
	if(x<0||x>=R) return false;
	if(y<0||y>=C) return false;
	return true;
}

bool chk_bits(int n){
	int c = 0;
	while(n!=0){
		if(n%2) c++;
		n /= 2;
	}
	if(c==N) return true;
	return false;
}

int unhappiness(int bm){
	REP(i, 0, R){
		REP(j, 0, C){
			grid[i][j] = bm%2;
			bm /= 2;
		}
	}
	int uh = 0;
	REP(i, 0, R){
		REP(j, 0, C){
			if(grid[i][j]==1){
				REP(k, 0, 4){
					int x=i+dx[k], y=j+dy[k];
					if(isValid(x, y)&&(grid[x][y]==1)){
						uh++;
					}
				}
			}
		}
	}
	uh /= 2;
	return uh;
}

/*void display(int p){
	cout << endl;
	REP(i, 0, R){
		REP(j, 0, C){
			cout << p%2 << " ";
			p /= 2;
		}
		cout << endl;
	}
}*/

int main(){
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	REP(t, 1, T+1){
		cout << "Case #" << t << ": ";
		cin >> R >> C >> N;
		int p = R*C;
		int mn_uh = 1000000;
		REP(i, 0, 1<<p){
			if(chk_bits(i)){
				mn_uh = min(mn_uh, unhappiness(i));
			}
		}
		cout << mn_uh;
		cout << "\n";
	}
	return 0;
}
