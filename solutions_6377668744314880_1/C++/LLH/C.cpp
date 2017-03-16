#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <complex>
using namespace std;
#define double long double
typedef long long int64;
const double PI=atan(1)*4, eps=1e-10;
typedef complex<double> Point;

const int maxn=3010;

int n;
Point p[maxn];
double l[maxn*2];
void solve(int icase) {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		//x=rand()%100000,y=rand()%100000;
		p[i]=Point(x,y);
	}
	
	printf("Case #%d:\n",icase);
	for(int i=1;i<=n;i++) {
		int nl=0;
		for(int j=1;j<=n;j++) if(j!=i) {
			++nl;
			l[nl]=arg(p[j]-p[i]);
			++nl;
			l[nl]=l[nl-1]+2*PI;
		}
		sort(l+1,l+nl+1);
		
		int mp=0;
		for(int left=1,right=1;right<=nl;right++) {
			while(l[right]-l[left]>PI+eps)
				left++;
			mp=max(mp,right-left+1);
		}
		printf("%d\n",n-1-mp);
	}

	//printf("%d\n",r);
	
}
int main() {
	int T;
	//solve(1);
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
		solve(i);
	scanf("%*s");
	return 0;
}
/*
4
6
23 90 40 0 100 9
4
10 5 15 5
2
100 100
8
81 81 81 81 81 81 81 0
6
23 90 40 0 100 9
*/
