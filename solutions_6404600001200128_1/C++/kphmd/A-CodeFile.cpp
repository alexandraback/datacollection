#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <set>
#include <utility>
#include <stack>

#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

void solve();
void runCase();

int ok(int x,vector<int> m) {
	int n = m.size();
	rep(i,n-1) {
		if(m[i]-x > m[i+1]) return 0;
	}
	return 1;
}

void runCase()
{
	int N;
	scanf("%d",&N);
	vector<int> m(N);
	rep(i,N) scanf("%d",&m[i]);
	int y,z; y = 0; z = 0;
	rep(i,N-1) {
		y += max(m[i]-m[i+1],0);
	}
	
	int l,r,mid;
	l = 0; r = 0;
	rep(i,N-1) r = max(r,m[i]-m[i+1]);
	
	for(;;) {
		mid = l + ((r-l) >> 1);
		if(ok(mid,m)) {
			r = mid;
		} else {
			l = mid+1;
		}
		if(l>=r) break;
	}
	//cout << r << endl;
	
	rep(i,N-1) z += min(m[i],r);
	
	printf("%d %d\n",y,z);
}

void runSample()
{
	string input;

	char buf[501] = {0};
	cin.getline(buf,501);

	input = buf;


	printf("%s\n",input.c_str());
}

void solve()
{
	int n;
	scanf("%d",&n);
	getchar();

	for(int i = 0; i < n; i++) {
		printf("Case #%d: ",i+1);
		runCase();
		//runSample();
	}
}

int main()
{
	solve();
	return 0;
}
