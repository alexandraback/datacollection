#include <iostream>
#include <fstream>
#define inf 10000
using namespace std;
int main()
{
ifstream in("B-small-attempt0.in");
ofstream out("B-small-attempt0.out");
int t;
in>>t;
for(int y=1;y<=t;y++)
{
int r,c,n;
in>>r>>c>>n;
int k=r*c;
int p=1;
for(int i=0;i<k;i++)
p=p*2;
int res=inf;
for(int i=0;i<p;i++)
{
int num=i,cnt=0,m=0,val=0;
bool arr[16][16]={false};
while(num!=0)
{
if(num%2)
{
cnt++;
arr[m/c][m%c]=true;
}
num=num/2;
m++;
}
for(int i=0;i<r;i++)
{
for(int j=0;j<c;j++)
{
if(arr[i][j] && arr[i+1][j])
val++;
if(arr[i][j] && arr[i][j+1])
val++;
}
}
if(cnt==n)
res=min(res,val);
}
out<<"Case #"<<y<<": ";
out<<res<<"\n";
}
cin.get();
cin.get();
}
