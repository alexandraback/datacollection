#include<cstdio>

int i,j,k,l,a[10][10],b[10][10],Fir,Sec,TestCase,Case;

int main()
{
	//freopen("a.in","rb",stdin);
	//freopen("a.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d",&Fir);Fir--;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				scanf("%d",a[i]+j);
		scanf("%d",&Sec);Sec--;
		for(i=0;i<4;i++)
			for(j=0;j<4;j++)
				scanf("%d",b[i]+j);
		for(i=k=l=0;i<4;i++)
			for(j=0;j<4;j++)
				if(a[Fir][i]==b[Sec][j])
				{
					k=a[Fir][i];
					l++;
				}
		if(l==1)
			printf("Case #%d: %d\n",Case,k);
		else if(!l)
			printf("Case #%d: Volunteer cheated!\n",Case);
		else
			printf("Case #%d: Bad magician!\n",Case);
	}
	return 0;
}
