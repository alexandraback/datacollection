#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main()
{
	FILE *fr=fopen("b-large.in","r");
	FILE *fw=fopen("outl.txt","w");
	int data;
	fscanf(fr,"%d",&data);
	for(int p=0;p<data;p++)
	{
		int num;
		ll kai;
		fscanf(fr,"%d%lld",&num,&kai);
		vector<ll>vec;
		for(int i=0;i<num;i++)
		{
			ll zan;
			fscanf(fr,"%lld",&zan);
			vec.push_back(zan);
		}
		ll beg=0,end=1000000000000000000LL;
		for(;;)
		{
			ll med=(beg+end)/2+1;
			ll cnt=0;
			for(int i=0;i<vec.size();i++)
			{
				cnt+=(med+vec[i]-1)/vec[i];
			}
			if(cnt>kai-1)
			{
				end=med-1;
			}
			else
			{
				beg=med;
			}
			if(beg==end)
			{
				ll c=kai;
				for(int i=0;i<vec.size();i++)
				{
					c-=(beg+vec[i]-1)/vec[i];
				}
				for(int i=0;i<vec.size();i++)
				{
					if(beg%vec[i]==0)
					{
						c--;
						if(c==0)
						{
							fprintf(fw,"Case #%d: %d\n",p+1,i+1);
							break;
						}
					}
				}
				break;
			}
		}
	}
}