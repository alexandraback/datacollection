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
		int b,n;
		vector<int> dat;
		scanf("%d%d",&b,&n);
		for (int i = 0; i < b; i++) {
			int val;
			scanf("%d",&val);
			dat.push_back(val);
		}
		long long low = 0, high = LLONG_MAX/3;
		int ans = -1;
		while (low <= high) {
			long long mid = (low+high) / 2;
			long long inprocess = 0, empty = 0;
			for (int i = 0; i < b; i++) {
				inprocess += (mid+dat[i]-1)/dat[i];
				empty += (mid%dat[i] == 0);
			}
			if (inprocess <= n-1 && inprocess + empty >= n) {
				for (int i = 0; i < b; i++) {
					if (mid % dat[i] == 0) {
						inprocess++;
						if (inprocess == n) {
							ans = i+1;
							break;
						}
					}
				}
				break;
			} else if (inprocess <= n-1) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		printf("Case #%d: %d\n", testcase, ans);
	}
	return 0;
}