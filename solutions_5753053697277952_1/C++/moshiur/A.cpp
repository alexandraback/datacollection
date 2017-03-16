#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#include <vector>
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;

int INT(){int x;scanf("%d",&x);return x;}

#define CLR(A,X) memset((A),(X),sizeof((A))
#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)

int P[33];
int n;

int findMax() {
	int ret = 0;
	FOR(i,n) if (P[i] > P[ret]) ret = i;
	return ret;
}

bool isBad() {
	int total=0;
	FOR(i,n) total+=P[i];
	int k = findMax();
	return (P[k] > total/2);
}

int main() {
	int T=INT();
	REP(t,1,T) {
		n=INT();
		FOR(i,n)P[i]=INT();
		printf("Case #%d:", t);
		while (true) {
			int k = findMax();
			if (P[k] == 0) break;
			printf(" ");
			printf("%c", 'A'+k);
			P[k]--;
			if (isBad()) {
				k = findMax();
				P[k]--;
				printf("%c", 'A'+k);
			}
			if (isBad()) {
				fprintf(stderr, "NOOOOOOOOOO!!!\n");
			}
		}
		puts("");
	}
	return 0;
}
