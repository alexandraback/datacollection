#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <unordered_set>
#include <unordered_map>
#include <cstring>
#include <string>
#include <set>
#include <bitset>

using namespace std;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int,int> pi;
#define MOD 1000000007
#define MAX 1000000000
#define For(i,n) for(int i=0;i<n;i++) 
int ans[1000][100][100];
int mat[20][20];
int func(int r,int c,int n,int cur)
{
 if(cur>r*c) return MAX;
 if(n==0)
 {
  int ans=0;
  for(int i=0;i<=max(r,c);i++)
  {
   for(int j=0;j<=max(r,c);j++)
    {
     if(mat[i][j]==1&&mat[i+1][j]==1)
       ans++;
     if(mat[i][j]==1&&mat[i][j+1]==1)
       ans++;
   }
  }
  return ans;
 }
   mat[cur/c][cur%c]=1;
   int val=func(r,c,n-1,cur+1);
   mat[cur/c][cur%c]=0;
  int val1= func(r,c,n,cur+1);
 return min(val,val1);
}

int main()
{

for(int i=0;i<=16;i++)
{
 for(int j=0;j<=16;j++)
{
  if(i*j<=16)
  {
   for(int k=0;k<=i*j;k++)
   {
     memset(mat,0,sizeof(mat));
     ans[i][j][k]=func(i,j,k,0);
   }
  }
}
}

int _t;
cin>>_t;
for(int _i=1;_i<=_t;_i++)
{
int a,b,c;
 cin>>a>>b>>c;
cout<<"Case #"<<_i<<": "<<ans[a][b][c]<<endl;
}
}    


