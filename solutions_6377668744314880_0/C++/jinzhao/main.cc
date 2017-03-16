#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
	int x,y,z;
	Point (int xx=0,int yy=0) {
		x=xx;y=yy;
		if (x==0&&y==0) z=-1;
		else if (x>0&&y==0) z=0;
		else if (x>0&&y>0) z=1;
		else if (x==0&&y>0) z=2;
		else if (x<0&&y>0) z=3;
		else if (x<0&&y==0) z=4;
		else if (x<0&&y<0) z=5;
		else if (x==0&&y<0) z=6;
		else if (x>0&&y<0) z=7;
	}
	friend long long operator * (const Point &a,const Point &b) {
		return (long long)a.x*b.y-(long long)b.x*a.y;
	}
	friend Point operator - (const Point &a,const Point &b) {
		return Point(a.x-b.x,a.y-b.y);
	}
	friend bool operator < (const Point &a,const Point &b) {
		if (a.z!=b.z) return a.z<b.z;
		return a*b>0;
	}
};

Point a[3000];
Point b[6007];
int n;

int main() {
	int t,tt,x,y,ans,i,j,p1,q1,p2,q2;
	scanf("%d",&t);
	for (tt=1;tt<=t;tt++) {
		scanf("%d",&n);
		for (i=0;i<n;i++) {
			scanf("%d%d",&x,&y);
			a[i]=Point(x,y);
		}
		printf("Case #%d:\n",tt);
		if (n<=3) {
			for (i=0;i<n;i++)
				printf("0\n");
		} else {
			for (i=0;i<n;i++) {
				ans=n;
				for (j=0;j<i;j++) b[j]=a[j]-a[i];
				for (j=i+1;j<n;j++) b[j-1]=a[j]-a[i];
				b[n-1]=Point(1,0);
				b[n]=Point(0,1);
				b[n+1]=Point(-1,0);
				b[n+2]=Point(0,-1);
				sort(b,b+n+3);
				for (j=0;j<n+4;j++) {
					b[j+n+3]=b[j];
					b[j+n+3].z+=8;
				}
				//printf("i=%d\n",i);
				//for (j=0;j<n+n+7;j++) {
					//printf("%d: %d %d %d\n",j,b[j].x,b[j].y,b[j].z);
				//}
				p1=p2=q1=q2=0;
				for (j=0;j<n+3;j++) {
					while (b[j]*b[p1]<=0) p1++;
					if (q1<p1) q1=p1;
					while (b[j]*b[q1]>0) q1++;
					while (b[j]*b[p2]<0) p2++;
					if (q2<p2) q2=p2;
					while (b[j]*b[q2]>=0) q2++;
					//printf("%d: %d %d %d %d\n",j,p1,q1,p2,q2);
					if (b[j].x==0||b[j].y==0) {
						ans=min(ans,q1-p1-1);
						ans=min(ans,n-(q2-p2-3)-1);
					} else {
						ans=min(ans,q1-p1-2);
						ans=min(ans,n-(q2-p2-2)-1);
					}
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
