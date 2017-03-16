#include<bits/stdc++.h>
#define f(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define fiter(i,col) for(auto (i)=(col).begin();(i)!=(col).end();++(i))
#define pb push_back
#define mp make_pair
#define INF 1000000000

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int ,int> pii;
typedef vector<int> vi;
typedef pair<ll,ll> pll;

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

int unh(vector<vector<int> >& grid, int r, int c, int cnt)
{
	int ans=0;
	f(i,0,r) {
		f(j,0,c) {
			if(grid[i][j]) cnt--;
		}
	}
	if(cnt!=0) return INF;
	f(i,0,r) {
		f(j,0,c-1) {
			if(grid[i][j]&&grid[i][j+1]) ans++;
		}
	}
	f(i,0,r-1) {
		f(j,0,c) {
			if(grid[i][j]&&grid[i+1][j]) ans++;
		}
	}
	return ans;
}

int solve(int r, int c, int n) {
	vector<vector< int> > grid(r);
	f(i,0,r) grid[i]=vector<int>(c,0);
	int best = r*(c-1)+c*(r-1);
	f(opt,0,1<<(r*c)) {
		f(i,0,r) {
			f(j,0,c) {
				grid[i][j]=((1<<(i*c+j)&opt)?1:0);
				best=min(best,unh(grid,r,c,n));
			}
		}
	}
	return best;
}

int main()
{
	int tcases;
	cin>>tcases;
	f(cas,1,tcases+1) {
		int r,c,n;
		cin>>r>>c>>n;
		cout<<"Case #"<<cas<<": "<<solve(r,c,n)<<endl;
	}
	return 0;
}
