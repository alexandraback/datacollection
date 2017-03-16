/*
	By: facug91
	From: 
	Name: 
	Date: 08/05/2016
*/

#include <bits/stdc++.h>
#define endl "\n"
#define EPS 1e-9
#define MP make_pair
#define F first
#define S second
#define DB(x) cerr << " #" << (#x) << ": " << (x)
#define DBL(x) cerr << " #" << (#x) << ": " << (x) << endl
const double PI = acos(-1.0);

#define INF 1000000000
//#define MOD 1000000000ll
//#define MAXN 30015

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> ii; typedef pair<ii, ii> iiii;
typedef vector<int> vi; typedef vector<ii> vii; typedef vector<iiii> viiii;

int n;
ii p[30];

int main () {
	#ifdef ONLINE_JUDGE
		ios_base::sync_with_stdio(0); cin.tie(0);
	#endif
	//cout<<fixed<<setprecision(2); cerr<<fixed<<setprecision(2); //cin.ignore(INT_MAX, ' '); //cout<<setfill('0')<<setw(9)
	int tc = 1, i, j;
	
	cin>>tc;
	for (int it=1; it<=tc; it++) {
		cin>>n;
		for (i=0; i<n; i++) {
			cin>>p[i].F;
			p[i].S = i;
		}
		sort(p, p+n, greater<ii>());
		cout<<"Case #"<<it<<":";
		while (p[0].F != p[1].F) {
			cout<<" "<<(char)(p[0].S+'A');
			p[0].F--;
		}
		for (i=2; i<n; i++) while (p[i].F--) cout<<" "<<(char)(p[i].S+'A');
		while (p[0].F--) {
			cout<<" "<<(char)(p[0].S+'A')<<(char)(p[1].S+'A');
		}
		cout<<endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
