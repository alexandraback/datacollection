#include<cstdio>
#include<algorithm>
using namespace std;
int T,n,i,l1,l2,j,ans[30010],k;
struct mjj{long long x,y;}a[3010],b[3010];
bool cmp(mjj x,mjj y){return x.x*y.y<y.x*x.y;}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	for(int tec=1;tec<=T;tec++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%lld%lld",&a[i].x,&a[i].y);
		for(i=1;i<=n;i++)
		{
			l1=0;l2=n;
			for(j=1;j<=n;j++)if(j!=i)
			{
				if(a[j].y>a[i].y||(a[j].y==a[i].y&&a[j].x<a[i].x))
					b[++l1].x=a[j].x-a[i].x,b[l1].y=a[j].y-a[i].y;
				else b[--l2].x=a[j].x-a[i].x,b[l2].y=a[j].y-a[i].y;
			}sort(b+1,b+l1+1,cmp);sort(b+l1+1,b+n,cmp);k=l1+1;
			ans[i]=min(l1,n-l1-1);
			for(j=1;j<=l1;j++)
			{
				for(;k<n&&(-b[k].x)*b[j].y<b[j].x*(-b[k].y);k++);
				if(k-j-1<ans[i])ans[i]=k-j-1;if(n-k+j-1<ans[i])ans[i]=n-k+j-1;
				for(;k<n&&(-b[k].x)*b[j].y<=b[j].x*(-b[k].y);k++);
				if(k-j-1<ans[i])ans[i]=k-j-1;if(n-k+j-1<ans[i])ans[i]=n-k+j-1;
			}for(j=l1+1,k=1;j<n;j++)
			{
				for(;k<=l1&&(-b[k].x)*b[j].y<b[j].x*(-b[k].y);k++);
				if(j-k<ans[i])ans[i]=j-k;if(n-j+k-2<ans[i])ans[i]=n-j+k-2;
				for(;k<=l1&&(-b[k].x)*b[j].y<=b[j].x*(-b[k].y);k++);
				if(j-k<ans[i])ans[i]=j-k;if(n-j+k-2<ans[i])ans[i]=n-j+k-2;
			}
		}printf("Case #%d:\n",tec);
		for(i=1;i<=n;i++)printf("%d\n",ans[i]);
	}
}
