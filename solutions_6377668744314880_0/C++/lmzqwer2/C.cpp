#include<stdio.h>
#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long LL;
int a[10000];
int t;

LL calc(int b, int *m, LL t){
	LL tot=0;
	for (int i=0;i<b;i++)
		tot += t / m[i] +1;
	return tot;
}

int main(){
	freopen("stdin","r",stdin);
	freopen("stdout","w",stdout);
	scanf("%d",&t);
	for (int time=0;time<t;time++){
		int n,b;
		int m[3010][2];
		scanf("%d", &n);
		for (int i=0;i<n;i++){
			scanf("%d %d", &m[i][0], &m[i][1]);
		}
		printf("Case #%d:\n", time+1);
		if (n>2){
			for (int k=0;k<n;k++){
				int minn = n-2;
				for (int i=0;i<n;i++){
					if (i!=k){
						LL y = (m[i][0] - m[k][0]);
						LL x = -(m[i][1] - m[k][1]);
						int totl = 0;
						int totr = 0;
						for (int j=0;j<n;j++)
							if (j!=i && j!=k){
								LL xx = m[j][0] - m[k][0];
								LL yy = m[j][1] - m[k][1];
								totl += (x*xx+y*yy)>0;
								totr += (x*xx+y*yy)<0;
							}
						if (totl<minn){
							minn = totl;
						}
						if (totr<minn){
							minn = totr;
						}
					}
				}
				printf("%d\n", minn);
			}
		}else{
			for (int i=0;i<n;i++)
				puts("0");
		}
	}
	return 0;
}
