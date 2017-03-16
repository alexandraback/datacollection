#include <cstdio>
#include <vector>
#include <algorithm>

#define FO(i,a,b) for (int i = a; i < b; i++)
#define sz(v) (int)(v.size())

using namespace std;

int square[16][16];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

int r,c;

bool v (int a, int b) {
	return a >= 0 && a < r && b >= 0 && b < c;
}

void printstuff () {
	FO(i,0,r) {
		FO(j,0,c) {
			printf("%d ",square[i][j]);
		}
		printf("\n");
	}
}

int main() {
	freopen("noisy.in","r",stdin);
	freopen("noisy2.out","w",stdout);
	int t;
	scanf("%d\n",&t);
	FO(_,1,1+t) {
		int n;
		FO(i,0,16)FO(j,0,16)square[i][j] = 0;
		printf("Case #%d: ",_);
		scanf("%d %d %d\n",&r,&c,&n);
		if (n <= (r*c+1)/2) {
			puts("0");
			continue;
		}
		int copy = n;
		n -= (r*c+1)/2;
		int co;
		int two = 0, three = 0, four = 0;
		if (c%2==0) two++;
		if (r%2==0) two++;
		if (r%2==0) {
			three = r-2;
		} else {
			three = 2*(r/2);
		}
		if (c%2==0) {
			three += c-2;
		} else {
			three += 2*(c/2);
		}
		int ans = 0;
		four = r*c-(r*c+1)/2 - two - three;
		if (n >= two) {
			ans+= 2*two;
			n-=two;
		} else {
			ans+=2*n;
			goto print;
		}
		if (n >= three) {
			ans+=3*three;
			n-=three;
		} else {
			ans+=3*n;
			goto print;
		}
		if (n >= four) {
			ans+=4*four;
		} else {
			ans+=4*n;
		}
		print:;
		printf("%d\n",ans);
	}
}


