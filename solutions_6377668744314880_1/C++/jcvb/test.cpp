#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<string>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
typedef long long ll;
typedef double db;


struct point{
	int x,y;
	point operator-(const point&a){
		return (point){x-a.x,y-a.y};
	}
	point operator+(const point&a){
		return (point){x+a.x,y+a.y};
	}
	int operator==(const point&a)const{
		return a.x==x && a.y==y;
	}
	ll operator*(const point&a)const{
		return 1ll*x*a.y-1ll*y*a.x;
	}
}arr[3333],p[3333];int tot;
int ans[3333];

int cmp(const point&a,const point&b){
	if(a==b)return 0;
	int s1=(a.y<=0 && a.x<=0 || a.y<0);
	int s2=(b.y<=0 && b.x<=0 || b.y<0);
	if(s1!=s2)return s1>s2;
	return a*b>0;
}
int work(){
	int ma=0;
	sort(p+1,p+1+tot,cmp);
	for (int st=1,cur=1;st<=tot && (p[st].y<=0 && (p[st].y<0 || p[st].x<0));st++){
		while(p[st]*p[cur]>=0 && cur<=tot)cur++;
		ma=max(ma,cur-st);
	}
	for (int i=1;i<=tot;i++)p[i].x*=-1,p[i].y*=-1;
	sort(p+1,p+1+tot,cmp);
	for (int st=1,cur=1;st<=tot && (p[st].y<=0 && (p[st].y<0 || p[st].x<0));st++){
		while(p[st]*p[cur]>=0 && cur<=tot)cur++;
		ma=max(ma,cur-st);
	}
	return tot-ma;
}
int main()
{
	int n;
	freopen("bs.in","r",stdin);
	freopen("bs.out","w",stdout);
	int tes;scanf("%d",&tes);
	for (int tt=1;tt<=tes;tt++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)scanf("%d%d",&arr[i].x,&arr[i].y);
		for (int i=1;i<=n;i++){
			tot=0;
			for (int j=1;j<=n;j++){
				if(arr[i]==arr[j])continue;
				p[++tot]=arr[j]-arr[i];
			}
			ans[i]=work();
		}
		printf("Case #%d:\n",tt);
		for (int i=1;i<=n;i++)printf("%d\n",ans[i]);
	}
	return 0;
}



		



