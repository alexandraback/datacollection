#include <cstdio>
#include <math.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <vector>
#include <queue>
#include <cstring>
#include <iomanip>
#include <deque>
#include <stack>
#include <map>
#include <set>

#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int, int> P2;
typedef pair<ll, ll> P2l;

#define INF 1000000

struct cmp{
	bool operator() (P2 a1, P2 a2) {
		return a1.first<a2.first;
	}
};

int main()
{	
	freopen("A-small-attempt0.in", "r", stdin);//test.txt
	freopen("out.txt", "w", stdout);
	
	int T; cin>>T;
	forn(i,T) {
		int N, sm=0; cin>>N;
		priority_queue<P2,vector<P2>,cmp> pq;
		forn(j, N) {int t; cin>>t; pq.push(P2(t, j)); sm+=t;}
		string ans="";

		while(pq.size() && sm>3){
			P2 k1=pq.top(); pq.pop();
			P2 k2=pq.top(); pq.pop();
			ans+=" "; ans+=(k1.second+'A'); ans+=(k2.second+'A');
			if(k1.first>1) {pq.push(P2(k1.first-1, k1.second)); sm--;}
			if(k2.first>1) {pq.push(P2(k2.first-1, k2.second)); sm--;}
		}

		if(pq.size()==2) {
			P2 k1=pq.top(); pq.pop();
			P2 k2=pq.top(); pq.pop();
			ans+=" "; ans+=(k1.second+'A'); ans+=(k2.second+'A');
		}

		if(pq.size()==3) {
			P2 k1=pq.top(); pq.pop();
			P2 k2=pq.top(); pq.pop();
			P2 k3=pq.top(); pq.pop();
			ans+=" "; ans+=(k1.second+'A');
			ans+=" "; ans+=(k2.second+'A'); ans+=(k3.second+'A');
		}

		cout<<"Case #"<<i+1<<":"<<ans<<endl;

	}

	return 0;
}
