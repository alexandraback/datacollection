#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for (int testcase = 1; testcase <= T; testcase++)
	{
		int n;
		int ans1 = 0, ans2 = 0, maxrate = 0;
		vector<int> dat;
		scanf("%d",&n);
		for (int i = 0; i < n; i++) {
			int val;
			scanf("%d",&val);
			dat.push_back(val);
			if (i > 0 && val < dat[i-1]) {
				ans1 += dat[i-1] - val;
			}
			if (i > 0) {
				maxrate = max(maxrate, dat[i-1] - val);
			}
		}
		for (int i = 0; i < n-1; i++) {
			ans2 += min(dat[i], maxrate);
		}
		printf("Case #%d: %d %d\n", testcase, ans1, ans2);
	}
	return 0;
}