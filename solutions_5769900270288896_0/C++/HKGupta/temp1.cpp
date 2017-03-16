#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int r,c,n;
		cin>>r>>c>>n;
		int ans=0;
		if((r*c+1)/2>=n)
			ans=0;
		else
		{
			n-=(r*c+1)/2;
			int c1=r+c-2;
			int c2=(r-2)*(c-2)/2;
			if(r==3 && c==3)
			{
				n++;

				for(int i=0;i<c1 && n>0 ;i++)
				{	ans+=2;
					n--;
						
				}
				while(n>0 && c2>0)
				{	ans+=4;
					n--;
					c2--;	
				}
			}	
			else if(r%2==0 || c%2==0)
			{	
				for(int i=0;i<2 && n>0 ;i++)
				{	ans+=2;
					n--;
					c1--;	
				}
			while(n>0 && c1>0)
				{	ans+=3;
					n--;
					c1--;	
				}
			while(n>0 && c2>0)
				{	ans+=4;
					n--;
					c2--;	
				}			
			}
			else
			{
				while(n>0 && c1>0)
				{	ans+=3;
					n--;
					c1--;	
				}
				while(n>0 && c2>0)
				{	ans+=4;
					n--;
					c2--;	
				}
			}	

		
		}

		cout<<"Case #"<<i+1<<": "<<ans<<"\n";	
	}


	return 0;
}