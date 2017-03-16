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

int ans;

int check() {
	int ret = 0;
	FO(i,0,r)FO(j,0,c) {
		if(square[i][j]) {
			if(v(i+1,j)&&square[i+1][j]) {
				ret++;	
			}
			if(v(i,j+1)&&square[i][j+1]) {
				ret++;
			}
		}
	}
	return ret;
}

void kek (int i, int j, int num) {
	if (num == 0) {
		ans = min(ans,check());
		return;
	}
	if (i == r-1 && j == c-1) {
		if (num) square[i][j] = 1;
		if (num == 1)ans = min(ans,check());
		return;
	}
	if (j == c-1) {
		square[i][j] = 0;
		kek(i+1,0,num);
		square[i][j] = 1;
		kek(i+1,0,num-1);
		return;
	}
	square[i][j] = 0;
	kek(i,j+1,num);
	square[i][j] = 1;
	kek(i,j+1,num-1);
}

int main() {
	freopen("noisy.in","r",stdin);
	freopen("noisy.out","w",stdout);
	int t;
	scanf("%d\n",&t);
	FO(_,1,1+t) {
		int n;
		FO(i,0,16)FO(j,0,16)square[i][j] = 0;
		printf("Case #%d: ",_);
		scanf("%d %d %d\n",&r,&c,&n);
		ans = 1e9;
		kek(0,0,n);
		printf("%d\n",ans);
	}
}
