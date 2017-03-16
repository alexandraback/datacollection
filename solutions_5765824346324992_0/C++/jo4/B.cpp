#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

int M[10000],B,N;

ll count(ll t) // count the number of customers with started cut(include)
{
	if(t<0)
		return 0ll;
	ll re=0;
	for(int i=1;i<=B;i++)
		re+=t/M[i]+1;
	return re;
}

int main()
{
	int NumberOfTestcases;
	scanf("%d",&NumberOfTestcases);
	for(int CaseNumber=1;CaseNumber<=NumberOfTestcases;CaseNumber++)
	{
		scanf("%d%d",&B,&N);
		for(int i=1;i<=B;i++)
			scanf("%d",M+i);
		ll l=0,r=(ll)1e15,m;
		//printf("%lld\n",r*1000);
		while(l<=r)
		{
			m=(l+r)/2;
			if(count(m)<N)
				l=m+1;
			else
				r=m-1;
		}
		// target start cut at time "l"
//printf("(%d)\n",l);
		printf("Case #%d: ",CaseNumber);
		int tmp=count(l-1);
		for(int i=1;i<=B;i++)
		{
			if(l%M[i]==0)
			{
				tmp++;
				if(tmp==N)
				{
					printf("%d\n",i);
					break;
				}
			}
		}
	}
	return 0;
}
