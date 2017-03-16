#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int main() {
	
	int T;
	scanf("%d", &T);
	
	for(int tt = 1; tt <= T; tt++) {
		printf("Case #%d: ", tt);
		int R,C,N;
		scanf("%d%d%d", &R, &C, &N);
		
		if(R < C) {
			int tmp = C;
			C = R;
			R = tmp;
		}
		
		int maxc = (R-1)*C + (C-1)*R;
		
		if(N <= (R*C+1)/2) {
			printf("0\n");
			continue;
		}
		
		if((R*C-N <= ((R-2)*(C-2)+1)/2) && R > 2 && C > 2) {
			printf("%d\n", maxc - 4*(R*C-N));
			continue;
		}
		
		if(C == 1) {
			printf("%d\n", maxc-2*(R-N));
			continue;
		}
		
		if(C == 2) {
			int ans;
			if(N > R+2) ans = maxc-3*(R*C-N);
			else if(N == R+1) ans = 2;
			else ans = 4;
			printf("%d\n", ans);
			continue;
		}
		
		int ans1 = 0;
		int ans2 = 0;
		
		int n = N;
		n -= (R*C+1)/2;
		if(R%2 == 0 || C%2 == 0) {
			int w = min(n,2);
			while(w--) {
				n--;
				ans1 += 2;
			}
		}
		while(n--) ans1 += 3;
		
		n = N;
		n -= (R*C)/2;
		int w;
		if(R%2 == 1 && C%2 == 1) w = 4;
		else w = 2;
		w = min(w,n);
		while(w--) {
			n--;
			ans2 += 2;
		}
		while(n--) ans2 += 3;
		
		
		printf("%d\n", min(ans1,ans2));
	}
	
	return 0;
}
