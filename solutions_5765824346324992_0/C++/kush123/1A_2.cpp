#include<iostream>
using namespace std;
int gcd(int a,int b)
 {
 	if(a%b==0)
 	 return b;
 	return gcd(b,a%b);
 }
int main()
{
 int t;
 cin>>t;
 for(int j=1;j<=t;j++)
  {
    int b,n;
    cin>>b>>n;
    int a[b+2],g,c[b+2],p=1,m=1000,index=1000;
    for(int i=1;i<=b;i++)
     {
     	cin>>a[i];
     	c[i]=a[i];
     	if(i>1)
     	{
     	 g=gcd(a[i],p);
     	 p=p*a[i];
     	 p=p/g;
  //   	 cout<<p<<" ";
     	}
     	else {
     	//	g=a[i];
     		p=a[i];
     	}
     }
     //p=p/g;
     //cout<<p<<" ";
     //cout<<n<<" ";
     int x=0;
     for(int i=1;i<=b;i++)
       x+=p/a[i];
//      cout<<x<<" ";
     n=n%x;
     if(n==0)
      n=x;
     int ans=0;
     if(n<=b)
      ans=n;
     else
     {
       for(int i=b+1;i<=n;i++)
         {
         	 m=a[1];
           index=1;
     	    for(int l=2;l<=b;l++)
     	     {
     	     	if(m>a[l])
     	     	 {
     	     	 	m=a[l];
     	     	 	index=l;
     	     	 }
     	     }
     	    a[index]+=c[index];
     	    ans=index;
     	   // cout<<ans<<" ";
         }
         ans=index;
     }
     
    cout<<"Case #"<<j<<": "<<ans<<"\n";
  }
  
}

