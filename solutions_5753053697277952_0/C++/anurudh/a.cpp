#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int t,n,q,w,e,r,y,u,i,o,p,s,d,f,g,h,j,k,l,z,x,c,v,b,m;
    cin>>t;
    int a[1000];
    int ar[1000];
    for(k=0;k<t;k++)
        {
        cin>>n;
         cout<<"Case #"<<k+1<<": ";
        for(i=0;i<n;i++)
            cin>>a[i];
        int sum=1;
        while(sum!=0)
            {
            sum=0;
        int max=a[0];
        p=0;
          for(i=0;i<n;i++)
              if(a[i]>max)
              {
                max=a[i];
              p=i;
          }
       int max2;
        if(p!=0)
            {
          max2=a[0];
        q=0;
            s=0;
        }
        else
            {
           max2=a[1];
        q=1;  
            s=1;
        }
          for(i=s;i<n;i++)
              if(a[i]>max2 && i!=p)
              {
                max2=a[i];
              q=i;
          }
        s=0;
       for(i=0;i<n;i++)
           if(i!=q)
           s=s+a[i];
       if(s-1>=a[q]) 
           {
           char tem= 65+p;
           cout<<tem<<" ";
           a[p]=a[p]-1;
       }
            else
                {
                 char tem= 65+p;
                 char tem2= 65+q;
           cout<<tem<<tem2<<" ";
           a[p]=a[p]-1;
                a[q]=a[q]-1;
            }
          for(i=0;i<n;i++)   
           sum=sum+a[i]; 
          
        }
           
        cout<<endl;
    
           
}
   
  return 0;
}

