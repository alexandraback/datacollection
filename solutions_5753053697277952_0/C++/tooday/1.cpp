//Author: Jaydeep
//https://code.google.com/codejam/contest/4314486/dashboard
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007
#define vec vector<ll>
#define matrix vector<vector<ll> >
#define pritnf printf
#define pb push_back



int main()
{
	ll a[200005],t,i=0,j,k,x,y,z,count=0,p,flag=0,ans=0,sum=0,l,n,t1,m,max;
	
	char s[200005];
	
	scanf("%lld",&t);
	
	t1=t;
	
	while(t--)
	{
	    scanf("%lld",&n);
	    
	    for(i=0;i<n;i++)
	    {
	        scanf("%lld",&a[i]);
	        sum+=a[i];
	        
	    }
	    
	    
	    
	    pritnf("Case #%lld: ",t1-t);
	    
	    
	    
	    
	    while(1)
	    {
	        
	        max=0;
	        
	        for(i=1;i<n;i++)
	        {
	            if(a[i]>a[max])
	                max=i;
	            
	            
	        }
	        
	        a[max]--;
	        sum--;
	        
	      //  printf("%d",max);
	        printf("%c",max+'A');
	        
	        max=0;
	        
	        for(i=1;i<n;i++)
	        {
	            if(a[i]>a[max])
	                max=i;
	            
	            
	        }
	        
	        
	        a[max]--;
	        sum--;
	        
	        
	        
	        flag=0;
	        for(i=0;i<n;i++)
	        {
	            
	            if(a[i]>sum/2)
	            {
	                flag=1;
	                break;
	                
	            }
	            
	            
	            
	        }
	        
	        if(flag==0)
	        {
	            
	            printf("%c",max+'A');
	            
	            
	        }
	        else
	        {
	            a[max]++;
	        sum++;
	            
	        }
	        
	        
	        printf(" ");
	        
	        if(sum<=0)
	        {
	            
	            break;
	            
	        }
	        
	    }
	    
	    
	    
	    printf("\n");
	    
	    
	    
	    
	    
	    
	    
		
		
	}
	
	
	return 0;
}
