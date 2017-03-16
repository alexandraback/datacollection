#include <cstdio>

int a[1010];

int main(){
	freopen("A-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int tc;
	scanf("%d", &tc);
	for(int ti = 1; ti <= tc; ti++){
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		int mx = 0, sm = 0;
		for(int i = 1; i < n; i++){
			int x = a[i]-a[i-1];
			if(x<0)
				sm -= x;
			if(-x>mx)
				mx = -x;
		}
		int sm2=0;
		for(int i = 1; i < n; i++){
			if(a[i-1]>mx)
				sm2+=mx;
			else
				sm2+=a[i-1];

		}
		printf("Case #%d: %d %d\n",ti,sm,sm2);
	}
	return 0;
}