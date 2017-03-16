#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void doit(int tc)
{
int n1,n2;
vector<bool> poss(17,0);
vector<vector<int> > brd(4,vector<int> (4,0));
cin>>n1;
n1--;
for(int i=0;i<4;++i)
for(int j=0;j<4;++j)
cin>>brd[i][j];
for(int i=0;i<4;++i)
poss[brd[n1][i]]=1;
cin>>n2;
n2--;
for(int i=0;i<4;++i)
for(int j=0;j<4;++j)
cin>>brd[i][j];
for(int i=0;i<4;++i)
for(int j=0;j<4;++j)
{if(i!=n2)poss[brd[i][j]]=0;
else poss[brd[i][j]]=1&poss[brd[i][j]];
}
int num,n=0;
for(int i=1;i<=16;++i)
if(poss[i])
{
num=i;n++;
}
cout<<"Case #"<<tc<<": ";
if(n==0) cout<<"Volunteer cheated!\n";
else if(n==1) cout<<num<<endl;
else cout<<"Bad magician!\n";
}
int main()
{
int t;
cin>>t;
int i=1;
while(t--)
{
doit(i++);
}
return 0;
}
