#include <cstdio>

int n,t;
int a[1010];

long long count( long long tt ){
	long long ret=0;
	for (int i=0; i<n; ++i)
		ret+=tt/a[i]+1;
	return ret;
}

int main(){
	int test=0;
	scanf("%d", &test);
	for (int T=1; T<=test; ++T){
		scanf("%d %d", &n,&t);
		for (int i=0; i<n; ++i) scanf("%d", a+i);
		long long l=0, r=t, tt=0;
		r=r*100000;
		while (l<=r){
			long long m=(l+r)/2;
			if (count(m)>=t){
				tt=m; r=m-1;
			} else
				l=m+1;
		}
		printf("Case #%d: ", T);
		if (tt==0){
			printf("%d\n", t);
		} else {
			//printf("%lld\n", tt);
			long long m=count(tt-1);
			t=t-m;
			for (int i=0; i<n; ++i)
				if (tt%a[i]==0){
					--t;
					if (t==0){
						printf("%d\n", i+1);
						break;
					}
				}
		}
	}
}
