#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<iomanip> 
#include<utility> 
#include<climits>
#include<climits>
#include<cmath>
#include<queue>
#include<algorithm>


using namespace std;


#define LL long long int
#define sc1(x) scanf("%d", &x)
#define sc2(x, y) scanf("%d%d", &x, &y)
#define sc3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define pr1(x) printf("%d\n", x)
#define FOR(i, a, n) for(int i=a;i<n;i++)
#define pp pair<int, int>
#define pb push_back 

#define MAX 1000001
#define MOD 1000000007LL

priority_queue<pair<int,int>,vector<pair<int,int> >, less<pair<int,int> > > q;


void func() {
	while(!q.empty()) {
		auto x = q.top();
		q.pop();
		auto y = q.top();

		if((x.first == 1) && (!(q.size()&1))) {
			cout<<" "<<char('A'+x.second);
		} else if(x.first == y.first) {
			cout<<" "<<char('A'+x.second)<<char('A'+y.second);
			q.pop();

			if(x.first > 1) {
				q.push({x.first-1, x.second});
			}

			if(y.first > 1) {
				q.push({y.first-1, y.second});
			}
		} else {
			cout<<" "<<char('A'+x.second);
			if(x.first > 1) {
				q.push({x.first-1, x.second});
			}
		}
	}
	cout<<endl;
}

int main() {

	int t, n, x;

	sc1(t);
	FOR(i, 1, t+1) {
		sc1(n);

		while(!q.empty()) q.pop();
		FOR(i, 0, n) {
			sc1(x);
			q.push({x, i});
		}

		cout<<"Case #"<<i<<":";
		func();
	}
	return 0;
}













