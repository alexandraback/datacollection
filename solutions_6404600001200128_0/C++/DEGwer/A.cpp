#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	FILE *fr=fopen("a-small-attempt0.in","r");
	FILE *fw=fopen("outs.txt","w");
	int data;
	fscanf(fr,"%d",&data);
	for(int p=0;p<data;p++)
	{
		int num;
		fscanf(fr,"%d",&num);
		vector<int>vec;
		for(int i=0;i<num;i++)
		{
			int zan;
			fscanf(fr,"%d",&zan);
			vec.push_back(zan);
		}
		int cnt=0,maxi=0;
		for(int i=0;i<num-1;i++)
		{
			if(vec[i]>vec[i+1])
			{
				cnt+=vec[i]-vec[i+1];
				maxi=max(maxi,vec[i]-vec[i+1]);
			}
		}
		int c=0;
		for(int i=0;i<num-1;i++)
		{
			c+=min(vec[i],maxi);
		}
		fprintf(fw,"Case #%d: %d %d\n",p+1,cnt,c);
	}
}