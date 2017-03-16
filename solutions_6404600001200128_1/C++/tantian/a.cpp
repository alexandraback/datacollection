#include <cstdio>

int n;
int a[1010];

int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		scanf("%d", &n);
		for (int i=0; i<n; ++i)
			scanf("%d", a+i);
		int ans1=0, ans2=0;
		for (int i=1; i<n; ++i)
			if (a[i-1]>a[i]) ans1+=a[i-1]-a[i];
		int MM=0;
		for (int i=1; i<n; ++i)
			if (a[i-1]-a[i]>MM) MM=a[i-1]-a[i];
		//printf("%d\n", MM);
		for (int i=0; i<n-1; ++i)
			if (MM<a[i]) ans2+=MM; else ans2+=a[i];
		printf("Case #%d: %d %d\n", T, ans1, ans2);
	}
}
