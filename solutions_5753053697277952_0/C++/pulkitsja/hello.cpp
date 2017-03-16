#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define mp make_pair
#define f first
#define s second
#define maxn 1000100
#define sz(x) x.size()
typedef pair <int,char> pp;
set<pp> sett;
int main(int argc, char const *argv[])
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	for (int T = 1; T <= t; ++T)
	{  cout<<"Case #"<<T<<": ";
		int n;
		cin>>n;
		int x;
		int sum=0;
		for (int i = 0; i < n; ++i)
		{
			cin>>x;
			sum+=x;
			sett.insert(mp(-1*x,(char)(i+'A')));
		}
		if(sum%2==1)
		{
			pp ans = *sett.begin();
			sett.erase(sett.begin());
			if(ans.f!=-1)
			sett.insert(mp(ans.f+1,ans.s));
			cout<<ans.s<<" ";
		}
		while(sett.size()>1)
		{
			pp ff = *sett.begin();
			sett.erase(sett.begin());
			pp ss = *sett.begin();
			sett.erase(sett.begin());
			if(ff.f !=-1)
				sett.insert(mp(ff.f+1,ff.s));
			if(ss.f !=-1)
				sett.insert(mp(ss.f+1,ss.s));
			cout<<ff.s<<ss.s<<" ";
		}
		if(sett.size()==1)
			{
				pp ans = *sett.begin();
				cout<<ans.s;
			}
		cout<<"\n";
		sett.clear();
	}
	return 0;
}