#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <queue>
#include <stack>

using namespace std;

typedef pair<int,int> PII;
typedef pair<long long int,int> PLI; 
typedef pair<double,PLI > PDL;
#define treshold 0.0000001

int main() {
	int t;
	scanf("%d",&t);
	for (int r=1;r<=t;r++) {
		printf("Case #%d:\n",r);
		int n;
		vector < PII > trees;
		scanf("%d",&n);
		trees.reserve(n);
		if (n<4) {
			for (int i=0;i<n;i++) {
				printf("0\n");
				continue;
			}
		}
		for (int i=0;i<n;i++) {
			int tmp1,tmp2;
			scanf("%d %d",&tmp1,&tmp2);
			trees.push_back(PII(tmp1,tmp2));
		}
		for (int i=0;i<n;i++) {
			int minv=3000;
			for (int j=0;j<n;j++) {
				int upper=0,lower=0;
				if (j==i) continue;
				if (trees[i].first==trees[j].first) {
					for (int k=0;k<n;k++) {
						if (k==j||k==i) continue;
						if (trees[k].first<trees[i].first) {
							lower++;
						}
						if (trees[k].first>trees[i].first) {
							upper++;
						}
					}
				} else {
					int x1=trees[i].first,x2=trees[j].first,y1=trees[i].second,y2=trees[j].second;
					double m=((double)(y1-y2))/((double)(x1-x2));
					double l=((double) y1)-m*x1;
					for (int k=0;k<n;k++) {
						if (k==j||k==i) continue;
						//cout << "val " << trees[k].first*m+n << " " << trees[k].second+treshold << endl;
						if (trees[k].first*m+l>trees[k].second+treshold) lower++;
						if (trees[k].first*m+l<trees[k].second-treshold) upper++;
					}
					//cout << "an "<< m << " " << n << endl;
				}
				//cout << i << " " << j << " " << upper << " " << lower << endl;
				minv=min(minv,min(upper,lower));
				if (minv==0) break;
			}
			printf("%d\n",minv);
		}
	}
	return 0;
}
