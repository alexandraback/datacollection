#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<math.h>
#define F first
#define S second
using std::vector;
using std::pair;
using std::make_pair;
using std::sort;
typedef pair<double,double> pdd;

pdd operator+ (const pdd &a,const pdd &b)
{ return pdd(a.F+b.F, a.S+b.S); } 
pdd operator- (const pdd &a,const pdd &b)
{ return pdd(a.F-b.F, a.S-b.S); } 
pdd operator* (const pdd &a,const double &b)
{ return pdd(a.F*b, a.S*b); } 
pdd operator/ (const pdd &a,const double &b)
{ return pdd(a.F/b, a.S/b); } 
double dot (const pdd &a,const pdd &b)
{ return a.F*b.F+a.S*b.S; }
double cross (const pdd &a,const pdd &b)
{ return a.F*b.S-b.F*a.S; }
double abs2 (const pdd &a)
{ return dot(a,a); }
double abs (const pdd &a)
{ return sqrt(dot(a,a)); }

int ans[20];

int cmp(const pdd &a,const pdd &b){
    if((a.F>b.F) || (a.F==b.F&&a.S>b.S)) return 1;
    return 0;
}
void sol(pdd pt0[20],pdd pt[20],int n0,int n){
	sort(pt,pt+n,cmp);
    pdd stack[105];
    int m=0;
    int i,j;
    for(i=0;i<n;i++){
        while(m>=2&&cross(stack[m-1]-stack[m-2],pt[i]-stack[m-2])<0) m--;
        stack[m++]= pt[i];
    }
    int m2=m+1;
    for(i=n-2;i>=0;i--){
        while(m>=m2&&cross(stack[m-1]-stack[m-2],pt[i]-stack[m-2])<0) m--;
        stack[m++]= pt[i];
    }
    for(i=0;i<n0;i++)
      for(j=0;j<m;j++)
        if(stack[j].F==pt0[i].F&&stack[j].S==pt0[i].S)
          if(ans[i]>n0-n) ans[i]=n0-n;
      
}
void dfs(int now,int ch[20],int n,pdd pt[20]){
	int i;
	if(now==n){
		pdd pt2[20];
		int x=0;
		for(i=0;i<n;i++)
		  if(ch[i]) pt2[x].F=pt[i].F,pt2[x].S=pt[i].S,x++;
		sol(pt,pt2,n,x);
		return ;
	}
	int ch2[20];
	for(i=0;i<now;i++)
	   ch2[i]=ch[i];
	ch2[i]=1;
	dfs(now+1,ch2,n,pt);
	ch2[i]=0;
	dfs(now+1,ch2,n,pt);
}
int main(void){
	int t,hh;
	scanf("%d",&t);
	for(hh=1;hh<=t;hh++){
		int n;
		pdd pt[20];
		int i;
		scanf("%d",&n);
		for(i=0;i<n;i++){
            scanf("%lf%lf",&pt[i].F,&pt[i].S);
        }
        int ch[20];
        for(i=0;i<n;i++)
          ans[i]=100;
        dfs(0,ch,n,pt);
        printf("Case #%d:\n",hh);
        for(i=0;i<n;i++)
          printf("%d\n",ans[i]);
	}
}
