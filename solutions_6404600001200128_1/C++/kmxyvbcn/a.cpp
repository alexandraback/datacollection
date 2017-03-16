#include<cstdio>

int Rate,n,a[1100],Ans1,Ans2;

int main()
{
	int i,Case,TestCase;
	//freopen("a.in","rb",stdin);
	//freopen("a.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d",a+i);
		Ans1=Ans2=0;
		for(i=0;i+1<n;i++)
			if(a[i]>a[i+1])
				Ans1+=a[i]-a[i+1];
		Rate=0;
		for(i=0;i+1<n;i++)
			if(a[i]>a[i+1]&&Rate<a[i]-a[i+1])
				Rate=a[i]-a[i+1];
		for(i=0;i+1<n;i++)
			if(a[i]>=Rate)
				Ans2+=Rate;
			else Ans2+=a[i];
		printf("Case #%d: %d %d\n",Case,Ans1,Ans2);
	}
	return 0;
}
