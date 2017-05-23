#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int n,nq;
int a[110];
vector<int> w;

int main()
{freopen("As.in","r",stdin);
 freopen("A.out","w",stdout);

 int i,j,s,q,ma=0,sm=0;
 
 scanf("%d",&nq);
 for(q=1;q<=nq;q++)
 {	scanf("%d",&n);
 	s=0;
 	memset(a,0,sizeof(a));
	for(i=1;i<=n;i++)
	{	scanf("%d",&a[i]);
		s+=a[i];
	}
	printf("Case #%d:",q);
	while(s)
	{	ma=0;
		for(i=1;i<=n;i++) ma=max(ma,a[i]);
		sm=0;
		w.clear();
		for(i=1;i<=n;i++)
			if(a[i]==ma)
			{	sm++;
				if(w.size()<=1) w.push_back(i);
			}
		if(sm==1 || sm>2)
		{	printf(" %c",64+w[0]);
			s--;
			a[w[0]]--;
		}
		else if(sm==2)
		{	printf(" %c%c",64+w[0],64+w[1]);
			s-=2;
			a[w[0]]--;
			a[w[1]]--;
		}
	}
	printf("\n");
 }
 return 0;
}
