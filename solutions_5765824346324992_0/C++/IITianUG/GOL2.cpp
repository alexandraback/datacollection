#include<bits/stdc++.h>
using namespace std;
int vis[10000010];
int gcd(int a, int b)
   {
       if(b==0)
       return a;
    else
       return gcd(b,a%b);
   }
   int check(int a[],int n,int key)
   {   int flag=0;
       for(int i=0;i<n;i++)
       {
           if(a[i]!=key)
           {
               flag=1; break;
           }
       }
       if(flag==0)
        return 1;
       else return 0;
   }
 int main()
 {
     ifstream IF;
     ofstream OF;
     int t,trm,b,n,i,gcdx,temp,tim,minx,yy,minindex,ans,p,gg[1010],hr[1010];
     IF.open("input.txt");
     OF.open("output.txt");
IF>>t;
for(trm=1;trm<=t;trm++)
{
    IF>>b>>n;
    if(b>=2){
    IF>>hr[0]>>hr[1];
    p=hr[0]*hr[1];
    gg[0]=hr[0];
    gg[1]=hr[1];
    vis[0]=1;
    vis[1]=2;
    yy=(hr[0]*hr[1])/gcd(hr[0],hr[1]);
    for(i=2;i<b;i++)
    {    vis[i]=i+1;
        IF>>hr[i];
        gg[i]=hr[i];
        p*=hr[i];
        yy = (yy*hr[i])/gcd(yy,hr[i]);
    }}
    else{
            IF>>hr[0];
    p=hr[0];
    gg[0]=hr[0];
    vis[0]=1;
    yy=hr[0];
    }
    temp=b;
    tim=0;

    while(check(gg,b,yy)!=1){
    minx = gg[0]; minindex = 0;
    for(i=1;i<b;i++)
    {
        if(gg[i]<minx)
        {minx = gg[i];  minindex = i;}
    }
    gg[minindex]+=hr[minindex];
    vis[temp++]=minindex+1;
    }
    if(n%temp==0)
    {
        ans = vis[temp-1];
    }
    else
    {
        ans = vis[n%temp-1];
    }
      OF<<"Case #"<<trm<<": "<<ans<<endl;

}

IF.close();
OF.close();
return 0;
 }
