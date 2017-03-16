#include<bits/stdc++.h>
using namespace std;
int n,maxim;
int main()
{
    FILE *ptrin,*ptrout;
    ptrin=fopen("C:\\Users\\DELL\\Desktop\\in.txt","r");
    ptrout=fopen("C:\\Users\\DELL\\Desktop\\out.txt","w");
    int T;
	pair<int,int> p[27]={};
    fscanf(ptrin,"%d",&T);
	for(int t=1;t<=T;t++)
    {
        fscanf(ptrin,"%d",&n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
        	fscanf(ptrin,"%d",&p[i].first);
        	p[i].second=i;
        	sum+=p[i].first;
        }
        sort(p,p+n);
        fprintf(ptrout,"Case #%d: ",t);
        while(true)
        {
        	if(p[n-1].first==0)
        	break;
        	if(sum==3&&p[n-1].first==p[n-2].first)
        	{
        			fprintf(ptrout,"%c ",char(p[n-1].second+'A'));
        			p[n-1].first-=1;
        			sum-=1;
        	}
        	else if(p[n-1].first==p[n-2].first)
        	{
        		fprintf(ptrout,"%c%c ",char(p[n-1].second+'A'),char(p[n-2].second+'A'));
        		p[n-1].first-=1;
        		p[n-2].first-=1;
        		sum-=2;
        	}
        	else
        	{
        		if(p[n-1].first>=2)
        		{
        		fprintf(ptrout,"%c%c ",char(p[n-1].second+'A'),char(p[n-1].second+'A'));
        		p[n-1].first-=2;
        		sum-=2;
        		}
        		else
        		{
        			fprintf(ptrout,"%c ",char(p[n-1].second+'A'));
        			p[n-1].first-=1;
					sum-=1;	
        		}
        	}
        	sort(p,p+n);
        }
        fprintf(ptrout,"\n");
    }
    fclose(ptrin);
    fclose(ptrout);
    return 0;
}
