#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cctype>
#include <stack>
#include <ctime>
#include <strstream>
#include <unordered_map>
#include <unordered_set>
typedef long long ll;
#define EPS 1e-8
using namespace std;
typedef pair<int,int> pii;
template<class T> inline T euclide(T a,T b,T &x,T &y)//NOTES:a*x+b*y=1;
  {if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}
   if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}
   if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}

ll gcd(ll x,ll y)
{
	if(!x||!y)return x>y?x:y;
	for(ll t;t=x%y;x=y,y=t);
	return y;
}

#define N 1005
int m[N];
bool cmp(pii a,pii b)
{
	if(a.second==b.second)return a.first<b.first;
	return a.second<b.second;
}
int main()
{
	ios_base::sync_with_stdio(false);
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int cas;
	int ki,i,j;
	scanf("%d",&cas);
	for(ki=1;ki<=cas;ki++)
	{
		printf("Case #%d: ",ki);
		int b,n;
		cin>>b>>n;
		for(i=0;i<b;i++)
			cin>>m[i];
		ll mg=m[0];
		for(i=1;i<b;i++)
			mg=(mg/gcd(mg,m[i]))*m[i];
		//cout<<"mg"<<mg<<endl;
		int cy=0;
		vector<pii> vp;
		for(i=0;i<b;i++)
		{
			cy+=mg/m[i];
			for(j=0;j<cy;j++)
				vp.push_back(make_pair(i,j*m[i]));
		}
		n=(n-1)%cy;
		sort(vp.begin(),vp.end(),cmp);
		cout<<vp[n].first+1<<endl;
		fflush(stdout);
	}
	return 0;
}