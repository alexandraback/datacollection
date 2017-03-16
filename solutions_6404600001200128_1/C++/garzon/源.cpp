#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>

#define FOR(a,b,c) for(int a=(b);a!=(c);a++)
#define REP(a,n) for(int a=0;a!=(n);a++)
#define FORE(a,b,c) for(int a=(b);a<=(c);a++)

using namespace std;

int n, res1, res2, ret;

int main() {
	int t;
	cin >> t;
	int arr[1000];
	REP(a,t) {
		cin>>n;
		res1=0; res2=0;
		REP(i,n) cin>>arr[i];
		FOR(i,1,n) {
			res1-=min(0,arr[i]-arr[i-1]);
			res2=min(res2,arr[i]-arr[i-1]);
		}
		res2=abs(res2);
		int left = arr[0]; ret = 0;
		FOR(i,1,n) {
			ret +=  min(res2, left);
			left = arr[i];
		}
		if(left != arr[n-1]) throw "error";
		cout << "Case #" << (a+1) << ": " << res1 << " " << ret << endl;
	}
	return 0;
}