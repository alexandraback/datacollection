#include<iostream>
#include<stdio.h> 
#include<algorithm>
#include<math.h>
#include<vector>
#include<set>
#include<stdlib.h>
#include<string.h>
#include<queue>
#include<stack>
#include<assert.h>
#include<limits.h>
#define tr(i) for(typeof(i.begin()) it=i.begin(); it!=i.end();it++)
#define pb push_back
#define mp make_pair
#define REP(i,n) for(int i=0;i<n;i++)
#define rep(i,s,n) for(int i=s;i<n;i++)
#define s(n) scanf("%d",&n)
#define XX first
#define X first
#define Y second
#define all(a) a.begin(),a.end()
#define YY second.first
#define ZZ second.second
#define fill(a,b) memset(a,b,sizeof(a))
#define DREP(a) sort(all(a)); a.erase(unique(all(a)),a.end());
#define INDEX(arr,ind) (lower_bound(all(arr),ind)-arr.begin())
#define SZ(x) (int)(x.size())
#define lin(val,j) (DP[j]-val*D[j])
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define MN 100000

int main()
{	
	int T; s(T);
	int N;
	REP(c,T)
	{
		int sum=0;
		s(N);
		vector<char> ord;
		vector<vector<int> > nums;
		string s;
		cin>>s;
		int l=s.length(),i=0,v=0;
		while(i<l)
		{
			ord.pb(s[i]);
			int c=0;
			while(i<l&&s[i]==ord[v]) i++,c++;;
			nums.pb(vector<int>() );
			nums[v].pb(c);
			v++;
		}
		bool bad=false;
		REP(j,N-1)
		{
			cin>>s;
			l=s.length(),i=0,v=0;
			while(i<l)
			{
				if((v>SZ(ord))||(s[i]!=ord[v]))
				{
					bad=true;
					break;
				}
				int c=0;
				while(i<l&&s[i]==ord[v]) i++,c++;
				nums[v].pb(c);
				v++;
			}
			if(v<SZ(ord)) bad=true; 
		}
		l=nums.size();
		REP(i,l)
		{
			sort(all(nums[i]));
			int com=nums[i].size()/2;
			REP(j,SZ(nums[i])) 
			{
				//cout<<nums[i][j]<<" ";
				sum+=abs(nums[i][j]-nums[i][com]);
			}
			//cout<<endl;
		}
		if(bad) printf("Case #%d: Fegla Won\n",c+1);
		else printf("Case #%d: %d\n",c+1,sum);

	}
	return 0;
}
