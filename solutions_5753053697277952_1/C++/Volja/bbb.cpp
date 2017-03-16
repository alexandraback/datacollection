#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int main() 
{
	FILE *fin1 = fopen("point.in","r+");
	FILE *fin2 = fopen("point.out","w+");

	int t=0;
	fscanf(fin1, "%d",&t);
	int b=1;
	while(t-->0)
	{
		fprintf(fin2,"Case #%d: ", b);b++;

		int n=0;
		fscanf(fin1, "%d",&n);
		vector<pair<int,int> >p(n);
		int s=0;
		for(int i=0;i<n;i++)
		{
			fscanf(fin1, "%d",&p[i].first);
			s+=p[i].first;
			p[i].second=i;
		}
		if(n==2)
		{
			while(s>0)
			{
				s-=2;
				fprintf(fin2,"%c%c ", 'A','B');
			}
		}
		else
		{
			while(s>0)
			{
				sort(p.begin(),p.end());

				int q=p[n-3].first;
				int w=p[n-2].first;

				if(w<=s-w-2)
				{
					fprintf(fin2,"%c%c ", 'A'+p[n-1].second, 'A'+p[n-1].second);
					p[n-1].first-=2;
					s-=2;
				}
				else if(q>s-q-2)
				{
					fprintf(fin2,"%c ", 'A'+p[n-1].second);
					p[n-1].first--;
					s--;
				}
				else
				{
					fprintf(fin2,"%c%c ", 'A'+p[n-1].second, 'A'+p[n-2].second);
					p[n-1].first--;
					p[n-2].first--;
					s-=2;
				}
			}
		}
		fprintf(fin2,"\n");
	}

	return 0;
}