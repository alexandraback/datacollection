#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <sstream>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define fill(a,v) memset(a, v, sizeof a)
#define INF 1e9
#define EPS 1e-9
#define pb push_back
#define sz size()
#define ln length()
#define forf(i,a,b) for(int i=a;i<b;i++)
#define forfa(i,a,b) for(int i=a;i<=b;i++)
#define forr(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define mp make_pair
#define ff first
#define ss second
#define sc(a) scanf("%d",&a)
#define mod 1000000007


int main() {
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int n,tmp;
	forf(z,1,t+1)
	{
		cout<<"Case #"<<z<<": ";
		cin>>n;
		string ans;
		vector<pii> c;
		forf(i,0,n){
			cin>>tmp;
			c.push_back(mp(tmp,i+65));
		}
		sort(all(c));
		int mn = c[0].first;
		while(c[n-1].first!=mn){
			c[n-1].first--;
			ans = ans + (char)c[n-1].second;
			ans = ans + " ";
			sort(all(c));
		}
		if(n%2==1){
			while(c[0].first>0){
				c[n-1].first--;
				ans = ans + (char)c[n-1].second;
				ans = ans + " ";
				for(int i=0;i<n-1;i+=2){
					c[i].first--;
					c[i+1].first--;
					ans = ans + (char)c[i].second;
					ans = ans + (char)c[i+1].second;
					ans = ans + " ";
				}
			}
		}else{
			while(c[0].first>0){
				for(int i=0;i<n;i+=2){
					c[i].first--;
					c[i+1].first--;
					ans = ans + (char)c[i].second;
					ans = ans + (char)c[i+1].second;
					ans = ans + " ";
				}
			}
		}
		cout<<ans;
		cout<<"\n";
	}

	return 0;
}
