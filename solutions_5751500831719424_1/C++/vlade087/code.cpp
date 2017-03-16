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
#define inf 200000000000000L
#define countbits __builtin_popcount
#define sz sizeof
#define mp make_pair
#define pb push_back
#define ll long long
#define ull unsigned long long
#define mset memset
#define sz sizeof
#define maxn 205
#define EPS 1e-9
#define par pair<int,int>
using namespace std;
int n,m,k,tt,d,x,y,P,t,A[maxn][maxn],r,C[maxn],cc,R[maxn];
vector<string> M1,M;
string cad;
string Rep(int pos,string c)
{
	string res = "";
	char last = c[0];
	res+=last;
	int cnt = 1;
	int b = 0;
	for(int i = 1;i < c.length();i++)
	{
		if(c[i]!= last)
		{
			A[pos][b++] = cnt;
			last = c[i];
			res+=c[i];
			cnt = 1;
		}else cnt++;
	}
	A[pos][b++] = cnt;
	return res;
}
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	cin>>tt;
	for(int w = 1;w<=tt;w++)
	{
		cin>>n;
		mset(A,0,sz(A));
		mset(C,0,sz(C));
		M1.clear();
		M.clear();
		for(int i = 0; i < n;i++)
		{
			cin>>cad;
			M.pb(cad);
			M1.pb(Rep(i,cad));
		}
		bool ok = true;
		for(int i = 1; i < n && ok;i++)
			if(M1[i]!=M1[i-1])
			{
				ok = 0;
			}
		printf("Case #%d: ",w);
		if(ok){
			cad = M1[0];
			int rr = 0;
			for(int i = 0; i < cad.length();i++)
			{
				int maxi = 0;
				for(int j = 0; j < n;j++)
					maxi = max(maxi,A[j][i]);
				int mini = 10000;
				for(int j = 1; j<= maxi;j++)
				{
					int aux = 0;
					for(int k = 0; k < n;k++)
						aux = aux + abs(A[k][i] - j);
					mini = min(mini,aux);
				}
				rr += mini;
			}
			printf("%d\n",rr);
		}else
		{
			printf("Fegla Won\n");
		}
	}
	return 0;
}
