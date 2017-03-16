#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<iomanip>
#include<vector>
#include<list>
#include<iterator>
#include<stack>
#include<queue>
using namespace std;

#include<fstream>
FILE *fin=freopen("a.in","r",stdin);
FILE *fout=freopen("a.out","w",stdout);

struct ee{
	long long x,y,q;
	bool operator<(const ee &b) const {
		if (q!=b.q)
		return q<b.q;
		else return y*b.x<b.y*x;
	}
};
ee a[3010],g[3010],d;

bool leftturn(ee u,ee v,ee w) {
	ee p,q;
	p.x=v.x-u.x;
	p.y=v.y-u.y;
	q.x=w.x-v.x;
	q.y=w.y-v.y;
	if (p.y*q.x<q.y*p.x)
	return 1;
	else return 0;
}

int main() {
	int T,t,n,m,i,j,k,c,ans;
	d.x=d.y=0;
	cin>>T;
	for (t=1;t<=T;t++) {
		cin>>n;
		for (i=0;i<n;i++) {
			scanf("%d%d",&j,&k);
			a[i].x=j;
			a[i].y=k;
		}
		printf("Case #%d:\n",t);
		if (n<4) {
			for (i=0;i<n;i++)
			printf("0\n");
		}
		else {
			for (i=0;i<n;i++){
				m=0;
				for (j=0;j<n;j++) 
				if (i!=j) {
					g[m].x=a[j].x-a[i].x;
					g[m].y=a[j].y-a[i].y;
					if (g[m].x>=0)
					if (g[m].y>=0)
					g[m].q=1;
					else g[m].q=4;
					else if (g[m].y>=0)
					g[m].q=2;
					else g[m].q=3;
					m++;
				}
				sort(g,g+m);
				//cout<<i<<" "<<a[i].x<<" "<<a[i].y<<endl;
				//for (j=0;j<m;j++)
				//cout<<g[j].x<<" "<<g[j].y<<endl;
				for (j=1;j<m;j++)
				if (leftturn(g[0],d,g[j]))
				break;
				ans=m-j;
				//cout<<"	"<<j<<endl;
				for (c=1;c<m;c++) {
					if (j==c)
					j=(j+1)%m;
					for (;(j!=c && !leftturn(g[c],d,g[j]));j=(j+1)%m);
					ans=min(ans,(m-j+c)%m);
				}
				printf("%d\n",ans);
			}
		}
	}
    return 0;
}
