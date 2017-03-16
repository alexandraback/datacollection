#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define FI(I,L,U) for (int I=L;I<U;I++)

using namespace std;

int main(int argc, char* argv[])
{
	FILE *fin,*fout;
	fin = fopen("in.txt","r");
	fout  = fopen("out.txt","w");
	int cas=0,icas=0;
	fscanf(fin,"%d",&cas);
	FI(icas,1,cas+1)
	{
		string str[10005];
		int n;
		fscanf(fin,"%d",&n);
		for(int i=0;i<n;++i)
		{
			char c[10005]={0};
			fscanf(fin,"%s",c);
			str[i]=c;
		}
		bool flg = true;
		char tmpc = str[0][0];
		int posi[10005];
		memset(posi,0,sizeof(posi));
		int num[10005];
		int minsum=0;
		while(true)
		{
			bool overf=false;
			int num[10005];
			memset(num,0,sizeof(num));
			for(int i=0;i<n;++i)
			{
				if(str[i].length()<=posi[i])
				{
					overf = true;
					if(i!=0)
					 flg = false;
					
					break;
				}
				if(i==0)
				{
					tmpc = str[i][posi[i]];
				}
				
				if(str[i][posi[i]]!=tmpc)
				{
					overf = true;
					flg = false;
					break;
				}
				int j=posi[i];
				for(;j<str[i].length();++j)
				{
					if(tmpc==str[i][j])
					{
						num[i]++;
					}
					else 
					 {
					break;	
					}
				}
				posi[i]=j;
			}
			int minrt=1000000;
			for(int k=0;k<=100;++k)
			{
				int tmp = 0;
				for(int j=0;j<n;++j)
				{
					//printf("%d,%c,%d\n",k,tmpc,num[j]);
					tmp+=abs(num[j]-k);
				}
				if(minrt>tmp)
				minrt = tmp;
			}
			minsum+=minrt;
			
			if(overf)
			  break;
		}
		
		if(flg)
		{
			for(int j=0;j<n;++j)
			{
				if(str[j].length()>posi[j])
				{
					flg = false;
					break;
				}
			}
		}
		if(flg)
		{
			fprintf(fout,"Case #%d: %d\n",icas,minsum);
		}
		else 
	    {
			fprintf(fout,"Case #%d: Fegla Won\n",icas);
		}
		
	}
	
	
	if(fin)fclose(fin);
	if(fout)fclose(fout);
    return 0;
}
