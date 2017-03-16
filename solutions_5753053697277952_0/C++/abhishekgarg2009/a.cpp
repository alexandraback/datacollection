#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int p[1003];
int main() {
	int t,n,max1,pos1,max2,pos2;
	scanf("%d",&t);
	for(int i=1;i<=t;i++) {
		scanf("%d",&n);
		for(int j=0;j<n;j++) {
			scanf("%d",&p[j]);
		}
		if(p[0]>=p[1]) {
			max1=p[0];
			pos1=0;
			max2=p[1];
			pos2=1;
		} else {
			max1=p[1];
			pos1=1;
			max2=p[0];
			pos2=0;
		}
		for(int j=2;j<n;j++) {
			if(p[j]>max1) {
				max2=max1;
				pos2=pos1;
				max1=p[j];
				pos1=j;
			} else if(p[j]>max2) {
				max2=p[j];
				pos2=j;
			}
		}
		printf("Case #%d: ",i);
		for(int j=max2;j<max1;j++) {
			printf("%c ",'A'+ pos1);
		}
		max1=max2;
		for(int j=0;j<n;j++) {
			if(j!=pos1 && j!=pos2) {
				for(int k=0;k<p[j];k++) {
					printf("%c ",'A'+j);
				}
			}
		}
		for(int j=0;j<max2;j++) {
			printf("%c%c ",'A'+pos1,'A'+pos2);
		}
		printf("\n");
	}
	return 0;
}