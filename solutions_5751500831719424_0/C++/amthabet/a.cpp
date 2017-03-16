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
//#define LARGE 1

string a[200];
vector<vector<int> > v;

int calc(int ind) {
	int best = 1000000000;
	for(int cnt = 1;cnt<=100;cnt++) {
		int cur = 0;
		for(int i=0;i<v.size();i++) {
			cur += abs(v[i][ind] - cnt);
		}
		best = min(best, cur);
	}
	return best;
}

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
		v.clear();
		v.resize(n);
		string s;
		for(int i=0;i<n;i++) {
			cin>>s;
			int cnt = 1;
			s.push_back('#');
			a[i] = "";
			for(int j=1;j<s.size();j++) {
				if(s[j] != s[j-1]) {
					a[i].push_back(s[j-1]);
					v[i].push_back(cnt);
					cnt=0;
				}
				cnt++;
			}
		}
		bool ok = true;
		for(int i=0;i<n;i++) {
			if(a[i] != a[0]) {
				ok = false;
				break;
			}
		}
		cout<<"Case #"<<tt<<": ";
		if(!ok) {
			cout<<"Fegla Won"<<endl;
			continue;
		}
		int ans = 0;
		for(int i=0;i<a[0].size();i++) {
			ans += calc(i);
		}
		cout<<ans<<endl;
	}

	return 0;
}
