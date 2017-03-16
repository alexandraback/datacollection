//============================================================================
// Name        : code.cpp
// Author      : vlade087
// Version     : 1.0
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<stdio.h>
#include<iostream>
#include<sstream>
#include<math.h>
#include<ctype.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<string.h>
#include<algorithm>
#include <complex>
#include <numeric>
#include<list>
#include<deque>
#include <stdlib.h>
#define printnVector(R) cout<<R.size()<<endl;for(int i =0;i<R.size();i++) cout<<R[i]<<" ";
#define mod 1000000007
#define inf 9223372036854775807L
#define countbits __builtin_popcount
#define sz sizeof
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define mset memset
#define sz sizeof
#define maxn 1000005
#define EPS 1e-9
#define par pair<int,int>
using namespace std;
int T[maxn],n,tt,c,m;
int use[100][100];
bool vis[100][100];
int fil[4] = {0,1,0,-1};
int col[4] = {1,0,-1,0};
int calc(int x,int y){
	int res = 0;
	if(x-1>=0) res+=use[x-1][y];
	if(x+1<n) res+=use[x+1][y];
	if(y-1>=0) res+=use[x][y-1];
	if(y+1 < m) res+=use[x][y+1];
	return res;
}
bool esta(int x,int y){
	return x>=0&&x<n&&y>=0&&y<m;
}
int method1(int cc){
		int ans = 0;
		memset(use,0,sizeof(use));
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < n;i++){
			for(int j = i % 2; j < m;j+=2){
				use[i][j] = 1;
				cc--;
			}
		}
		if(cc <= 0){
			return 0;
		}
		if(cc && !use[0][0]){
			cc--;
			ans+=2;
			use[0][0] = 1;
		}
		if(cc && !use[0][m-1]){
			cc--;
			ans+=2;
			use[0][m-1] = 1;
		}
		if(cc && !use[n-1][m-1]){
			cc--;
			ans+=2;
			use[n-1][m-1] = 1;
		}
		if(cc && !use[n-1][0]){
			cc--;
			ans+=2;
			use[n-1][0] = 1;
		}
		int p = 0;
		int xx = 0;
		int yy = 0;
		while(cc){
			vis[xx][yy] = 1;
			if(!use[xx][yy]){
				use[xx][yy] = 1;
				ans += calc(xx,yy);
				cc--;
			}
			int nextx = xx+fil[p];
			int nexty = yy+col[p];
			if(!esta(nextx,nexty) || vis[nextx][nexty]){
				p = (p+1) % 4;
				nextx = xx+fil[p];
				nexty = yy+col[p];
			}
			xx = nextx;
			yy = nexty;
		}
		return ans;
}
int method2(int cc){
		int ans = 0;
		memset(use,0,sizeof(use));
		memset(vis,0,sizeof(vis));
		for(int i = 0; i < n;i++){
			for(int j = (i+1) % 2; j < m;j+=2){
				use[i][j] = 1;
				cc--;
			}
		}
		if(cc <= 0){
			return 0;
		}
		if(cc && !use[0][0]){
			cc--;
			ans+=2;
			use[0][0] = 1;
		}
		if(cc && !use[0][m-1]){
			cc--;
			ans+=2;
			use[0][m-1] = 1;
		}
		if(cc && !use[n-1][m-1]){
			cc--;
			ans+=2;
			use[n-1][m-1] = 1;
		}
		if(cc && !use[n-1][0]){
			cc--;
			ans+=2;
			use[n-1][0] = 1;
		}
		int p = 0;
		int xx = 0;
		int yy = 0;
		while(cc){
			vis[xx][yy] = 1;
			if(!use[xx][yy]){
				use[xx][yy] = 1;
				ans += calc(xx,yy);
				cc--;
			}
			int nextx = xx+fil[p];
			int nexty = yy+col[p];
			if(!esta(nextx,nexty) || vis[nextx][nexty]){
				p = (p+1) % 4;
				nextx = xx+fil[p];
				nexty = yy+col[p];
			}
			xx = nextx;
			yy = nexty;
		}
		return ans;
}
int main(){
	freopen("B-small-attempt0.in","r",stdin);
	freopen("output-B.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin>>tt;
	for(int w = 1;w<=tt;w++){
		cin>>n>>m>>c;
		int a = method1(c);
		int b = method2(c);
		printf("Case #%d: %d\n",w,min(a,b));
	}
	return 0;
}
