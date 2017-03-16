/**————————————————————————————————————————————————————
 计算几何模版<二维空间>
 Included:
 基础:
 -->点,向量,直线,角,线段,三角形,多边形,圆
 位置关系:
 -->相交,平行,垂直,交点
 坐标变换:
 -->旋转,对称
 多边形:
 -->质心,三角剖分(建设中)
 离散点集:
 -->凸包,最近点对,最远点对,最小包围圆,费马点
 其它:
 -->半平面交
 Author: haosheng@google.com
 copyright TJU ONLY!
 <--
 pay attention to -0.00000 when output
 so use ans+EPS instead of ans to avoid
 this trick, strongly suggested
 -->
 
 ————————————————————————————————————————————————————*/

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<deque>
#include<vector>
#include<iostream>
#include<queue>
#include<map>
#include<iomanip>
using namespace std;
struct P{
	int x,y;
	int r;
	long long operator*(P o){
		return 1ll*x*o.y-1ll*y*o.x;
	}
}pp[3000],qq[3000];
long long f(int k){
	return 1ll*k*k;
}
bool cmp(P a,P b){
	if(a.r!=b.r)return a.r<b.r;
	return a*b>0;
}
int main(){
	int ca;
	scanf("%d",&ca);
	for(int cas=1;cas<=ca;cas++){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&pp[i].x,&pp[i].y);
		}
		printf("Case #%d: \n",cas);
		for(int i=0;i<n;i++){
			memcpy(qq,pp,sizeof(pp));
			swap(qq[0],qq[i]);
			for(int j=1;j<n;j++){
				qq[j].x-=qq[0].x;
				qq[j].y-=qq[0].y;
				if(qq[j].x>=0&&qq[j].y>=0)qq[j].r=1;
				else if(qq[j].x>=0&&qq[j].y<=0)qq[j].r=4;
				else if(qq[j].x<=0&&qq[j].y>=0)qq[j].r=2;
				else if(qq[j].x<=0&&qq[j].y<=0)qq[j].r=3;
			}
			sort(qq+1,qq+n,cmp);
			if(n<=3){
				printf("0\n");
				continue;
			}
			int ans=n-3;
			for(int j=1,jj=2;j<n;j++){
				if(jj==j){
					jj++;
					if(jj==n)jj=1;
				}
				while(qq[j]*qq[jj]>0){
					jj++;
					if(jj==n)jj=1;
				}
				int tmp=jj-j-1;
				if(tmp<0)tmp+=n-1;
				ans=min(ans,tmp);
			}
			printf("%d\n",ans);
		}
	}
}
