#include <stdio.h>
struct y
{
	int number;
	int count;

};



int mod(int a)
{
	if(a>=0) return a;
	else return a*(-1);
}
typedef struct y node;
int main(void) {
	int i,t,j,k,l,n,ans,flag,p;
	char s[105];


	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		scanf("%d",&n);
		node x[n][105];
		for(j=0;j<n;j++)
		for(k=0;k<105;k++)
		{x[j][k].number=0;x[j][k].count=0;}
		for(j=0;j<n;j++)
		{
			p=0;
			scanf("%s",s);
			for(k=0;s[k]!=0;k++)
			{
				for(;;)
				{
					if(x[j][p].number==0) {x[j][p].number=(int)s[k];x[j][p].count++;break;}
					else if(x[j][p].number==(int)s[k]) {x[j][p].count++;break;}
					else p++;
				}
			}

		}


		ans=0;flag=0;
		for(j=0;j<105;j++)
		{
			if(x[0][j].number!=x[1][j].number) {ans=0;flag=1;break;}
			if(x[0][j].number==0 || x[1][j].number==0 ) {break;}
			else {ans+=mod(x[0][j].count-x[1][j].count);}
		}
		if(flag!=1)
		printf("Case #%d: %d\n",i,ans);

		else
		printf("Case #%d: Fegla Won\n",i);
	}
	return 0;
}
