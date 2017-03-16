#include<bits/stdc++.h>
using namespace std;
  
#define MOD 1000000007
#define MAX 1000000007
#define gc getchar()  
#define sc(a) scanf("%d",&a)
#define scs(a) scanf("%s",a+1);
#define pri(a) printf("%d\n",a);
#define rep(a,b,c) for(a=b;a<c;a++) 
#define rrep(a,b,c) for(a=b;a>c;a--)  
#define vit vector<int > :: iterator
#define viit vector<ii > :: iterator
#define mp(a,b)  make_pair(a,b)
#define pb(a,b) a.push_back(b)
#define trv(it,v) for(it=v.begin();it!=v.end();it++)
#define F first
#define S second
#define all(v)	v.begin(),v.end()
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define read(a) freopen(a,"r",stdin)
#define write(a) freopen(a,"w",stdout);

priority_queue<pair<int,char> > q;
int main()
{	
	read("input.in");
	write("output.out");
	int t,ta;
	cin>>t;
	pair<int,char> a,b;
	for(ta=1;ta<=t;ta++)
	{
		int cnt[26],n;
		int sum=0;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>cnt[i];
			sum+=cnt[i];
			q.push(make_pair(cnt[i],i+'A'));
		}
		cout<<"Case #"<<ta<<": ";
		while(!q.empty())
		{
			a=q.top();
			  q.pop();
			if(a.F>=2&&q.top().first<=(sum-2)/2)
			{
				cout<<a.S<<a.S<<" ";
				sum-=2;
				a.F=a.F-2;
				if(a.F!=0)
				q.push(a);
				continue;
			}
			if(a.F>=1&&q.top().first<=(sum-1)/2)
			{
				cout<<a.S<<" ";
				sum-=1;
				a.F=a.F-1;
				if(a.F!=0)
				q.push(a);
				continue;
			}
			b=q.top();
			  q.pop();
			cout<<a.S<<b.S<<" ";
			sum-=2;
			a.F=a.F-1;
			b.F=b.F-1;
			if(a.F!=0)
			q.push(a);
			if(b.F!=0)
			q.push(b);
		}
		cout<<endl;
	}
	return 0;
}
