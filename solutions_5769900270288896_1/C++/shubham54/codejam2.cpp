#include <iostream>
#include<stdio.h>
using namespace std;

long long int shubham[1 << 18];
long long int jj, Cot, N;

long long int fum(long long int iii)
{
	long long int rrr,w,answer=0;
	for (rrr=0;rrr<jj;rrr++)
	{
		for (w=0;w<Cot;w++)
		{
			if (w>0 && (iii&(1<<(rrr*Cot+w))) && (iii&(1<<(rrr*Cot+w-1))))
				answer++;
			if (rrr>0 && (iii&(1<<(rrr*Cot+w))) && (iii&(1<<(rrr*Cot+w-Cot))))
				answer++;
		}
	}
	return answer;
}

int main()
{
    freopen("file.in","r",stdin);
    freopen("shubham.txt","w",stdout);
	long long int t,g=0,i,bbb;
	cin>>t;
	while(t--)
	{
		cin>>jj>>Cot>>N;
		bbb=jj*Cot*N*100;
		for (i=1;i<(1<<(jj*Cot));i++)
		{
			shubham[i]=shubham[i-(i&-i)]+1;
			if(shubham[i] == N)
            {
                bbb = min(bbb, fum(i));
            }
		}
		printf("Case #%lld: %lld\n", ++g, bbb);
	}
}

