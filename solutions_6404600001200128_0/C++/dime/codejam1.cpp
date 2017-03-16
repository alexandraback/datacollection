#include <bits/stdc++.h>
#include<iostream>

using namespace std;

int arr[100005];

int main()
{
	 freopen("abc.txt","r",stdin);
 freopen("pqr.txt","w",stdout);

    int t,n,xe,i;
    cin>>t;
    for(xe=1;xe<=t;xe++)
    {
        cin>>n;
         int max=-1;
        for(i=0;i<n;i++)
        {
        	 scanf("%d",&arr[i]);
        	if(arr[i]>max) max=arr[i];
        }
       
             

              int cnt=0;
              for(i=1;i<n;i++)
              {
                  if(arr[i]<arr[i-1])
                    cnt+=(arr[i-1]-arr[i]);
                    

              }


        printf("Case #%d: %d ",xe,cnt);
       //  cout<<" maxis "<<max<<endl;
		int pre=0;
        int kk=0;int sum=0;
         for(int k=0;k<=max;k++)
          {
		    int f=0;
             pre=0;
              sum=0;
          	  for(int i=0;i<n-1;i++)
          	   {
          	   	  if(arr[i]<pre)
          	   	   {
          	   	   	 f=1;
          	   	   	 break;
          	   	   }
          	   	   else
          	   	    {
          	   	        if(arr[i]<k)
          	   	         
          	   	         {
          	   	         	pre=0;
          	   	         	 sum+=arr[i];
          	   	         }
          	   	         else
          	   	          {
          	   	          	   sum+=k;
          	   	          	  pre=arr[i]-k;
          	   	          }
							
          	   	    }
          	   }
          	   if(f==0 && arr[n-1]>=pre)
          	    {
          	    	  cout<<sum<<endl;
          	    	   break;
          	    }
          }
    }
}
