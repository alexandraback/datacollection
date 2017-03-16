#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <map>
using namespace std;


int n;
char alpa[] = "ABCDEFGHIJKLMNOPQRXTUVWXYZ";
int main() {
	int TC;
	scanf("%d",&TC);
	for(int tc =1; tc<=TC; tc++) {
		printf("Case #%d: ",tc);
		int n,p[26];
		scanf("%d",&n);
		for(int i=0; i<n; i++) scanf("%d",&p[i]);
		int cnt=n;
		while(true) {
			int a,b,c,d;
			a=b=c=d=0;
			for(int i=0; i<n; i++) {
				if(a<p[i]) {
					b=a;
					d=c;
					a = p[i];
					c=i;
				}
				else if(b<p[i]) {
					b = p[i] ;
					d = i;
				}
			}
//			printf("a,b,c,d %d %d %d %d\n",a,b,c,d);
			if(a == 0 && b== 0) break;
			if(a) {
				printf("%c",alpa[c]);
				p[c]--;
				if(p[c]==0) cnt--;
				if(cnt==2 && a==1) {
					printf(" ");
					continue;
				}
				if(a>1 && a-b>1) {
					printf("%c ",alpa[c]);
					p[c]--;
					if(p[c]==0) cnt--;
					continue;
				}
			}
			if(b) {
				printf("%c",alpa[d]);
				p[d]--;
				if(p[d]==0) cnt--;
			}
			printf(" ");
		}
		puts("");
	}
}
