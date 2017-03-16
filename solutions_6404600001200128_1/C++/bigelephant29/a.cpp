#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX = 1000 + 10;

int rec[MAX];

int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	int TN;
	scanf("%d", &TN);
	for(int casen = 1 ; casen <= TN ; casen++){
		int n, ans1 = 0, ans2 = 0, intv = 0;
		scanf("%d", &n);
		for(int i = 0 ; i < n ; i++){
			scanf("%d", &rec[i]);
		}
		for(int i = 1 ; i < n ; i++){
			if(rec[i-1] > rec[i])
				ans1 += rec[i-1] - rec[i];
		}
		for(int i = 1 ; i < n ; i++){
			intv = max(intv, rec[i-1] - rec[i]);
		}
		for(int i = 0 ; i < n-1 ; i++){
			ans2 += min(intv, rec[i]);
		}
		printf("Case #%d: %d %d\n", casen, ans1, ans2);
	}
	return 0;
}
