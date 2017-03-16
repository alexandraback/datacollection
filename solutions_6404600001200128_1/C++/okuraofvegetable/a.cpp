#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
int N;
int m[1010];
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)scanf("%d",&m[i]);
		int ans1=0,ans2=0,c=0;
		for(int i=1;i<N;i++)
		{
			if(m[i]<m[i-1])
			{
				ans1+=m[i-1]-m[i];
				c = max(c,m[i-1]-m[i]);
			}
		}
		for(int i=0;i<N-1;i++)ans2 += min(m[i],c);
		printf("Case #%d: %d %d\n",t+1,ans1,ans2);
	}
	return 0;
}
