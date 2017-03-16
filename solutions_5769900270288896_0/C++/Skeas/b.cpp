#include<cstdio>
#include<algorithm>

using namespace std;

int T,cs,R,C,n;

int main() {
	scanf("%d",&T);
	for(cs=1;cs<=T;++cs) {
		printf("Case #%d: ",cs);
		scanf("%d%d%d",&R,&C,&n);

		int c2 = 0, c3 = 0, c4 = 0;
		if(R == 1 || C == 1) {
			if(C == 1) swap(R,C);
			if(C%2) {
				printf("%d\n",2*max(0, n-(C+1)/2));
			}
			else {
				int rest = max(0,n - C/2);
				printf("%d\n",1*min(1,rest) + 2*max(0,rest-1));
			}
		}
		else if(R%2 && C%2) {
			int ans1 = 0, ans2 = 0, tot, rest;
			tot = 0;
			for(int i=0;i<C;++i) {
				if(i % 2 == 0) tot += R - (R/2);
				else tot += R/2;
			}
			rest = max(0, n - tot);
			c3 = 2 * (C / 2) + 2 * (R / 2);
			c4 = (R*C-tot) - c3;
			ans1 = 3 * min(c3, rest) + 4 * max(0, rest-c3);
			
			tot = 0;
			for(int i=0;i<C;++i) {
				if(i % 2) tot += R - (R/2);
				else tot += R/2;
			}
			rest = max(0, n - tot);
			c2 = 4;
			c3 = 2 * ((C+1) / 2) + 2 * ((R+1) / 2) - 4 - 4;
			c4 = (R*C-tot) - c2 - c3;
			ans2 = 2 * min(c2, rest) + 3 * min(c3, max(0, rest-c2)) + 4 * max(0,rest-c2-c3);

			printf("%d\n",min(ans1,ans2));
		}
		else {
			if(R%2) swap(R,C);
			c2 = 2;
			c3 = R-2+C-2;
			int rest = max(0,n-R*C/2);
			printf("%d\n",2*min(c2,rest) + 3*min(c3,max(0,rest-c2)) + 4 * max(0,rest-c2-c3));
		}
	}
}
