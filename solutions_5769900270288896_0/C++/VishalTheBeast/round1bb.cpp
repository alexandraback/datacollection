#include <bits/stdc++.h>
using namespace std;
int save[1000010];
int bitcou(int a)
{
	if(a<1000005&&save[a]>0)
		return save[a];
	int ret=0;
	while(a>0)
	{
		if(a%2==1)
			ret++;
		a/=2;
	}
	if(a<1000005)
		save[a]=ret;
	return ret;
}
int main()
{
	
    int t,i,j,k,l;
    int m,n,o,p,q,r,s;
    int v,w,ans;
    cin>>t;
    for(i=0;i<t;i++)
    {
    	cin>>j>>k>>l;
    	int mem[j][k];
    	m=j*k;
    	if(l==0)
    	ans=0;
    	else
    		ans=100000;
    	n=1<<m;
    	for(o=1;o<n;o++)
    	{
    		p=0;
    		q=0;
    		for(v=0;v<j;v++)
    		{
    			for(w=0;w<k;w++)
    			{
    				if(o&(1<<p))
    					mem[v][w]=1;
    				else
    					mem[v][w]=0;
    				p++;
    			}
    		}
    		if(j==1)
    		{
    			for(v=0;v<k-1;v++)
    			{
    				if(mem[0][v]==1&&mem[0][v+1]==1)
    					q++;
    			}
    		}
    		else if(k==1)
    		{
    			for(v=0;v<j-1;v++)
    			{
    				if(mem[v][0]==1&&mem[v+1][0]==1)
    					q++;
    			}
    		}
    		else
    		{
    			for(v=0;v<j;v++)
	    		{
	    			for(w=0;w<k-1;w++)
	    			{
	    				if(mem[v][w]==1&&mem[v][w+1]==1)
	    					q++;
	    			}
	    		}
	    		for(v=0;v<k;v++)
	    		{
	    			for(w=0;w<j-1;w++)
	    			{
	    				if(mem[w][v]==1&&mem[w+1][v]==1)
	    					q++;
	    			}
	    		}	
    		}
    	//	cout<<o<<" "<<q<<endl;
    		if(bitcou(o)==l)
    		ans=min(ans,q);
    	}
    	cout<<"Case #"<<i+1<<": "<<ans<<endl;
    }
	return 0;
}