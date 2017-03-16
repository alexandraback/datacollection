#include <iostream>
#include <ios>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
#define XINF INT_MAX
#define INF 0x3f3f3f3f
#define MAXN 0x7fffffff
#define eps 1e-10
#define zero(a) fabs(a)<eps
#define sqr(a) ((a)*(a))
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define PF(X) push_front(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define PI  acos(-1.0)
#define test puts("OK");
#define lowbit(X) (X&(-X))
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
typedef pair<int,int> PII;
typedef priority_queue<int,vector<int>,greater<int> > PQI;
typedef vector<PII> VII;
typedef vector<int> VI;
#define X first
#define Y second

ll a[1010];

int main()
{_
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int T;
	cin>>T;
	REP(k,T)
	{
		ll b,n;
		cin>>b>>n;
		REP(i,b)
			cin>>a[i];
		ll l=0LL,r=1000000000000000LL;
		while(r-l>1)
		{
			ll mid=(l+r)>>1;
			ll res=0LL;
			REP(i,b)
				res+=((mid+(a[i]-1))/a[i]);
			if(res<n)
				l=mid;
			else
				r=mid;
		}
		ll ans=r,tot=0LL;
		REP(i,b)
			tot+=((ans-1)+(a[i]-1))/a[i];
		int cnt=n-tot,j=0,pos=-1;
		for(int i=0;i<b;i++)
			if((ans-1)%a[i]==0)
			{
				j++;
				if(j==cnt)
				{
					pos=i+1;
					break;
				}
			}
		cout<<"Case #"<<k+1<<": "<<pos<<endl;
	}
	return 0;
}

