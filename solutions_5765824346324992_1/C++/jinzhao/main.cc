#include <cstdio>
#include <algorithm>

using namespace std;

int b,n;
int a[1000];

int main() {
	int cas,tt,i,maxa;
	long long l,r,t,p;
	scanf("%d",&cas);
	for (tt=1;tt<=cas;tt++) {
		scanf("%d%d",&b,&n);
		maxa=0;
		for (i=0;i<b;i++) {
			scanf("%d",&a[i]);
			maxa=max(maxa,a[i]);
		}
		l=0;r=(long long)maxa*n;
		while (l!=r) {
			t=(l+r)/2;
			p=0;
			for (i=0;i<b;i++) p+=1+t/a[i];
			if (p>=n) r=t;
			else l=t+1;
		}
		t=l;
		p=0;
		for (i=0;i<b;i++) {
			p+=1+t/a[i];
			if (t%a[i]==0) p--;
		}
		p=n-p;
		for (i=0;i<b&&p>0;i++) {
			if (t%a[i]==0) p--;
		}
		printf("Case #%d: %d\n",tt,i);
	}
	return 0;
}
