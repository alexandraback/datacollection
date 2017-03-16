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

void runCase()
{
	int r,c,n;
	cin >> r >> c >> n;
	int x[16];
	int rc = r*c;
	int rv = 1e9;
	for(int i = 0; i < (1<<rc); i++) {
		int cnt = 0;
		for(int j = 0; j < 16; j++) {
			if((1<<j) & i) {
				x[j] = 1;
				cnt ++;
			} else {
				x[j] = 0;
			}
		}
		if(cnt==n) {
			int ans = 0;
			for(int j = 0; j < r; j++) {
				for(int k =0;k<c;k++) {
					if(x[j*c+k]==1) {
						if(j>0&&x[j*c-c+k]==1) ans++;
						if(k>0&&x[j*c-1+k]==1) ans++;
						if(j<r-1&&x[j*c+c+k]==1) ans++;
						if(k<c-1&&x[j*c+1+k]==1) ans++;
					}
				}
			}
			rv = min(rv,ans);
		}
	}
	cout << rv/2 << endl;
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
