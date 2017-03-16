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

long long f(vector<int>& v, long long m) {
	long long cnt = 0;
	for(int i=0;i<v.size();i++)
		cnt += (m+v[i]-1)/v[i];
	return cnt;
}

int main() {
#ifdef LARGE
	freopen("b_large.i", "rt", stdin);
	freopen("b_large.o", "wt", stdout);
#elif SMALL
	freopen("b_small.i", "rt", stdin);
	freopen("b_small.o", "wt", stdout);
#else
	freopen("b_sample.i", "rt", stdin);
#endif

	int t;
	cin>>t;
	for(int tt=1;tt<=t;tt++) {
		int b,n;
		cin>>b>>n;
		vector<int> v(b);
		for(int i=0;i<b;i++)
			cin>>v[i];
		long long st = 0, end = 1e15;
		while(st<end) {
			long long m = (st+end+1)/2;
			long long cnt = f(v, m);
			if(cnt > n-1)
				end = m-1;
			else
				st = m;
		}
		int ans = -1, rem = n-f(v, st)-1;
		for(int i=0;i<b;i++)
			if(st%v[i] == 0) {
				if(!rem) {
					ans = i;
					break;
				}
				rem--;
			}
		cout << "Case #"<<tt<<": "<<ans+1<<endl;
	}

	return 0;
}
