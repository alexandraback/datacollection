/*
	In the Name of God
	Aida Sadat Mousavi
*/

#include <vector>
#include <map>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <complex>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <iomanip>
#include <set>
#include <stack>
#include <stdio.h>

using namespace std;

#define MAXN 60
#define X first
#define Y second
#define CLR(x,a) memset(x,a,sizeof(x))
#define FOR(i,b) for(ll i=0;i<(b);i++)
#define FOR1(i,b) for(ll i=1;i<=(b);i++)
#define FORA(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORB(i,b,a) for(ll i=(b);i>=(a);i--)
#define sh(x) cerr<<(#x)<<" = "<<(x)<<endl
#define EPS 0.00001
#define ull unsigned long long int
#define ll long long 
#define MP make_pair
#define PB push_back
#define ALL(v) (v).begin(),(v).end()
#define sz size()
#define EXIST(a,b) find(ALL(a),(b))!=(a).end()
#define Sort(x) sort(ALL(x))
#define UNIQUE(v) Sort(v); (v).resize(unique(ALL(v)) - (v).begin())
#define timestamp(x) printf("Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define N 5019
//const double PI = acos(-1);
typedef complex<double> point;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef vector<ll> vi;
typedef vector<vi > vii;
typedef vector<pii> vpii;
typedef vector<piii> vpiii;

int main()
{
	ofstream fout;
  	fout.open ("Aans.txt");
  	int T; cin>>T;
  	FOR1(cs,T)
  	{
  		int n; cin>>n;
		vpii v(n);
		int t=0;
		FOR(i,n) 
		{
			int x; cin>>x;
			t+=x;
			v[i]=pii(x,i);	
		}	
		vector<string> ans;
		while(t>0)
		{
			sort(ALL(v), greater<pii>());
			if(v[0].X==v[1].X && (!(t==3)))
			{
				v[0].X-=1;
				v[1].X-=1;
				t-=2;
				string s; s+=(char)(v[0].Y+'A');
				s+=(char)(v[1].Y+'A');
				ans.PB(s);
			}
			else
			{
				v[0].X--;
				t--;
				string s; s+=(char)(v[0].Y+'A');
				ans.PB(s);
			}
		}
		cout<<"Case #"<<cs<<": "; 
		FOR(i,ans.sz)
		{
			if(i) cout<<" ";
			cout<<ans[i];
		}
		cout<<endl;
	}
	
	fout.close();
		
}























