#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int n;
int x[10000],y[10000];
pair<double,int> p[10000];
int tx,ty;

double pi=acos(-1);

void getans(){
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for (int q=0;q<n;q++){
		int cur=0;
		for (int j=0;j<n;j++)
			if (j!=q) {
				double t=atan2(x[j]-x[q],y[j]-y[q]);
				p[cur++]=make_pair(t,j);
				p[cur++]=make_pair(t+2*pi,j);
			}
		sort(p,p+cur);
			// puts("####");
			// for (int i=0;i<n-1;i++)
			// 	printf("%.4f %d\n",p[i].first,p[i].second);
		int ans=max(0,n-3);
		for (int i=0,j=0;i<n-1;i++){
			for (;j<cur&&p[j].first<p[i].first+pi-1e-8;j++);
			ans=min(ans,j-i-1);
			// printf("-- %d %d\n",i,j);
		}
		printf("%d\n",ans);
	}
}

int main(){
	int N;
	scanf("%d",&N);
	for (int r=1;r<=N;r++){
		printf("Case #%d:\n",r);
		getans();
	}
	return 0;
}