#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
int main(){
	int i,j;
	int t,p;
	scanf("%d", &t);
	for(p=1;p<=t;p++){
		int r,c,n;
		scanf("%d%d%d",&r,&c,&n);
		int ans = (c-1)*r+c*(r-1);
		if (r>c) {
			int t=r;
			r=c;
			c=t;
		}
		if (r==1) {
			if (n<=(c+1)/2) {
				ans = 0;
				goto pans;
			}
			ans = 2*(n-(c+1)/2);
			goto pans;
		}
		if (r==2) {
			if (n<=c) {
				ans = 0;
				goto pans;
			}
			if (n<=c+2) {
				ans = (n-c)*2;
				goto pans;
			}
			ans = 4+(n-c-2)*3;
			goto pans;
		}
		int a=r*c-n;
		int fours = ((r-2)*(c-2)+1)/2;
		if (a<=fours){
			ans-=4*a;
			goto pans;
		}
		ans -= 4*fours;
		a-=fours;
		int threes = (c/2-1)*2+(r/2-1)*2;
		if (threes>=a) {
			ans-=3*a;
			goto pans;
		}
		int twos = 4;
		if (twos>=a) {
			ans -= 2*a;
			goto pans;
		}
		ans = 0;
pans:
		printf("Case #%d: %d\n", p, ans);
	}
}
