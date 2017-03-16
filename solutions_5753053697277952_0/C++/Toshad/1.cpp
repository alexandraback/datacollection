#include<bits/stdc++.h>
#define f(i,a,n) for(int i=a;i<n;i++)
#define S second
#define F first
#define Sc(n) scanf("%lld",&n)
#define scc(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)
#define sp(a) scanf("%lld %lld",&a.first,&a.second)
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define sc(n) scanf("%d",&n)
#define It iterator
#define SET(a,b) memset(a,b,sizeof(a))
#define DRT()  int t,t1=0; cin>>t; while(t1++<t)
// inbuilt functions
// __gcd,  __builtin_ffs,     (returns least significant 1-bit, __builtin_ffsll(1)=1)
// __builtin_clz,             (returns number of leading zeroes in 
// __builtin_popcount,
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> vi;
#define tr(container, it) for(__typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define trv(s,it) for(auto it:s)
int cnt[30],cn[30];
set<int> s;
stack<string> st;
int main()
{	DRT()
	{	int n,m1=1005;
		cin>>n;
		s.clear();
		f(i,0,n)
		{	cin>>cnt[i];
			m1=min(cnt[i],m1);
			s.insert(i);
		}
		int l=0;
		string ch;
		while(!s.empty())
		{
//			cout<<s.size()<<m1<<endl;
			while(++l<=m1)
			{	trv(s,it)
				{	if(ch.size()==2)
					{	st.push(ch);
						ch.clear();
					}
					ch.pb((char)it+'A');
				}
				if(ch.size())
					st.push(ch);
				ch.clear();
			}
			f(i,0,n)
				if(cnt[i]==m1)
					s.erase(i);
				else cnt[i]-=m1;
			m1=1005;
			trv(s,it)
				m1=min(cnt[it],m1);
			l=0;
//			cout<<s.size()<<*(s.begin())<<endl;
		}
		cout<<"Case #"<<t1<<": ";
		while(!st.empty())
		{	cout<<st.top()<<" \n"[st.size()==1];
			st.pop();
		}
	}
}

