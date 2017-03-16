#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;

#define SMALL 1
#define LARGE 1

int main() {
#ifdef LARGE
	freopen("a_large.i", "rt", stdin);
	freopen("a_large.o", "wt", stdout);
#elif SMALL
	freopen("a_small.i", "rt", stdin);
	freopen("a_small.o", "wt", stdout);
#else
	freopen("a_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int n;
		cin>>n;
		vector<int> v(n);
		for(int i=0;i<n;i++) {
			cin>>v[i];
		}
		int m1 = 0, mx = 0, m2 = 0;
		for(int i=1;i<n;i++) {
			m1 += max(0, v[i-1]-v[i]);
			mx=max(mx, v[i-1]-v[i]);
		}
		for(int i=1;i<n;i++) {
			m2 += min(mx, v[i-1]);
		}
		cout << "Case #"<<tt<<": "<<m1<<" "<<m2<<endl;
	}

	return 0;
}
