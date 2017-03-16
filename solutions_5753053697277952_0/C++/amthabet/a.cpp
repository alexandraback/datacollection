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
#include<algorithm>
#include<iterator>
#include<numeric>
using namespace std;

#define SMALL 1
//#define LARGE 1

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
		vector<pair<int,int> > v(n);
		for(int i=0;i<n;i++) {
			cin>>v[i].first;
			v[i].second = i;
		}
		cout<<"Case #"<<tt<<":";
		sort(v.begin(), v.end(), greater<pair<int,int> >());
		while(v[0].first) {
			cout<<" ";
			if(v[0].first > v[1].first+1) {
				cout<<char('A'+v[0].second)<<char('A'+v[0].second);
				v[0].first -= 2;
			} else if(v[0].first > v[1].first) {
				cout<<char('A'+v[0].second);
				v[0].first -= 1;
			} else {
				int c = 1;
				for(int i=1;i<v.size();i++)
					if(v[i].first == v[0].first) c++;
				if(c%2) {
					cout<<char('A'+v[0].second);
					v[0].first -= 1;
				} else {
					cout<<char('A'+v[0].second)<<char('A'+v[1].second);
					v[0].first -= 1;
					v[1].first -= 1;
				}
			}
			sort(v.begin(), v.end(), greater<pair<int,int> >());
		}
		cout<<endl;
	}

	return 0;
}
