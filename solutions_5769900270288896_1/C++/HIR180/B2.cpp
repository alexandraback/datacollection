#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int x[105][10005]={},y[105][10005]={};
int main()
{
	int t; cin >> t;
	for(int ss=1;ss<=t;ss++)
	{
		int r,c,n;
		cin >> r >> c >> n;
		printf("Case #%d: ",ss);
		if(r==1&&c==1)
		{
			cout << 0 << endl;
			continue;
		}
		if(r>c) swap(r,c);
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		int xzan=n,yzan=n;
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				if((i+j)%2 == 0) x[i][j] = 1,xzan--;
				else y[i][j] = 1,yzan--;
			}
		}
		vector<int>X,Y;
		for(int i=1;i<=r;i++)
		{
			for(int j=1;j<=c;j++)
			{
				if((i+j)%2 == 0)
				{
					if((i==1||i==r) && (j==1||j==c)) Y.pb((r==1?1:2));
					else if(i==1 || i==r || j==1 || j==c) Y.pb((r==1?2:3));
					else Y.pb(4);
				}
				else
				{
					if((i==1||i==r) && (j==1||j==c)) X.pb((r==1?1:2));
					else if(i==1 || i==r || j==1 || j==c) X.pb((r==1?2:3));
					else X.pb(4);
				}
			}
		}
		sort(X.begin(),X.end());
		sort(Y.begin(),Y.end());
		int xx=0,yy=0;
		for(int i=0;i<xzan;i++) xx+=X[i];
		for(int i=0;i<yzan;i++) yy+=Y[i];
		cout << min(xx,yy) << endl;
	}
}