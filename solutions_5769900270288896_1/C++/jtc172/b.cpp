#include<cstdio>
#include<cstring>

int R,C,Ans,N,N1,N2,M,Ans1,Ans2;

int main()
{
	int TestCase,Case,i,j,k,bl;
//	freopen("b.in","rb",stdin);
//	freopen("b.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d%d%d",&R,&C,&N);
		if(N<=(R*C+1)/2)
			Ans=0;
		else
		{
			N1=N-(R*C+1)/2;
			if((R*C+1)/2*2==N)M=2;
				else M=0;
			if(N1<=M)
				Ans1=N1*2;
			else
			{
				Ans1=M*2;
				N1-=M;
				M=-M;
				if((R&1)||!(C&1))M+=C;else M+=C-1;
				if((C&1)||!(R&1))M+=R;else M+=R-1;
				if(N1<=M)
					Ans1+=N1*3;
				else
					Ans1+=M*3+(N1-M)*4;
			}
			N2=N-(R*C)/2;
			if((R*C+1)/2*2==N)M=2;
				else M=4;
			if(N2<=M)
				Ans2=N2*2;
			else
			{
				Ans2=M*2;
				N2-=M;
				M=-M;
				if((R&1)||!(C&1))M+=C;else M+=C+1;
				if((C&1)||!(R&1))M+=R;else M+=R+1;
				if(N2<=M)
					Ans2+=N2*3;
				else
					Ans2+=M*3+(N2-M)*4;
			}
			Ans=Ans1<Ans2?Ans1:Ans2;
		}
		printf("Case #%d: %d\n",Case,Ans);
	}
	return 0;
}
