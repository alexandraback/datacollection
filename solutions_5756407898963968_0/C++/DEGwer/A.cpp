#include<stdio.h>
#include "stdafx.h"
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int data;
	FILE *fr=fopen("A-small-attempt0.in","r");
	FILE *fw=fopen("out.txt","w");
	fscanf(fr,"%d",&data);
	for(int p=0;p<data;p++)
	{
		fprintf(fw,"Case #%d: ",p+1);
		int m1,m2;
		vector<int>v1,v2;
		fscanf(fr,"%d",&m1);
		for(int i=0;i<16;i++)
		{
			int zan;
			fscanf(fr,"%d",&zan);
			if((m1-1)*4<=i&&i<m1*4)
			{
				v1.push_back(zan);
			}
		}
		fscanf(fr,"%d",&m2);
		for(int i=0;i<16;i++)
		{
			int zan;
			fscanf(fr,"%d",&zan);
			if((m2-1)*4<=i&&i<m2*4)
			{
				v2.push_back(zan);
			}
		}
		int ko=0,rr;
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				if(v1[i]==v2[j])
				{
					ko++;
					rr=v1[i];
				}
			}
		}
		if(ko==0)
		{
			fprintf(fw,"Volunteer cheated!\n");
		}
		if(ko>=2)
		{
			fprintf(fw,"Bad magician!\n");
		}
		if(ko==1)
		{
			fprintf(fw,"%d\n",rr);
		}
	}
}