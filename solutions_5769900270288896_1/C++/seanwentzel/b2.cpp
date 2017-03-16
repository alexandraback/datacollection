#include<bits/stdc++.h>
#define f(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define fiter(i,col) for(auto (i)=(col).begin();(i)!=(col).end();++(i))
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int ,int> pii;
typedef vector<int> vi;
typedef pair<ll,ll> pll;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int neigh(int x, int y, vector<vector<int> >& grid, int r, int c)
{
	if(!(grid[x][y])) return -1;
	int ans =0;
	f(i,0,4) {
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx>=0 && ny >=0 && nx < r && ny < c) {
			if(grid[nx][ny]) ++ans;
		}
	}
	return ans;
}

int solve(int r, int c, int n,int off) {
	if(n<(r*c+1)/2) return 0;
	int gaps=r*c-n;
	vector<vector<int> > grid(r);
	f(i,0,r) {
		grid[i]=vector<int>(c,1);
	}
	int ans = (r-1)*c+(c-1)*r;
	for(int cost=4;cost>=0;--cost) {
		f(i,0,r) {
			f(j,0,c) {
				if(gaps<=0) return ans;
				if((i+j)%2!=off) continue;
				if(neigh(i,j,grid,r,c)==cost) {
					grid[i][j]=0;
					gaps--;
					ans-=cost;
				}
			}
		}
	}
	return ans;
}

int main()
{
	int tcases;
	cin>>tcases;
	f(cas,1,tcases+1) {
		int r,c,n;
		cin>>r>>c>>n;
		cout<<"Case #"<<cas<<": "<<min(solve(r,c,n,0),solve(r,c,n,1))<<endl;
	}
	return 0;
}
