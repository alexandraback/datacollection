#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 5000005
#define ll long long
#define p(t) cout<<t;
#define f(i,n) for(i=0;i<n;i++)
#define g(i,n) for(i=1;i<=n;i++)


ll a[N],b[N],r,m,n;


int main()
{
ios_base::sync_with_stdio(0);
ll k=0,t=0,x,sum=0,q=0,z=0,y=0,l=0,i,j;
k=1;
ifstream my;
  my.open ("a.txt");
  ofstream out("out.txt");
  my>>q;
 while(q--){
        out<<"Case #"<<k<<": ";
    k++;
    my>>n;
  f(i,n)my>>a[i];
  while(1)
  {z=-1;
  f(i,n){ if(z<a[i])z=a[i],l=i; }
  if(z==0)break;
  a[l]--; r=0;
  f(i,n) {
      r=r+a[i];
  }
  string s=""; char c=l+'A';
  s=s+c;
  z=-1;
  f(i,n){  if(a[i]>r/2){z=i; break;}  }
     if(z!=-1){c=z+'A';  s=s+c;
     a[z]--;
 }
 out<<s<<" ";
 }
 out<<endl;

}
  my.close();

return 0;
}
