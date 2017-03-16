#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<cassert>
#include<set>
#include<queue>
#include<map>

using namespace std;

#define vi vector < int >
#define pb push_back
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 2000000000
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define all(x) x.begin(),x.end()

int a[4][4],b[4][4];

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int t,tc=1,i,j;
    scanf("%d",&t);
    while(t--)
    {
              int r1,r2;
              scanf("%d",&r1);
              for(i=0;i<4;i++)
              {
                 for(j=0;j<4;j++)
                 {
                     scanf("%d",&a[i][j]);
                 }
              }
              scanf("%d",&r2);
              for(i=0;i<4;i++)
              {
                 for(j=0;j<4;j++)
                 {
                     scanf("%d",&b[i][j]);
                 }
              }
              r1--,r2--;
              
              int cnt[17]={0};
              
              for(i=0;i<4;i++)
              cnt[a[r1][i]]++;
              
              for(i=0;i<4;i++)
              cnt[b[r2][i]]++;
              
              int ans = -1;
              
              int f = 0;
              
              for(i=1;i<=16;i++)
              {
                 if(cnt[i]==2)
                 {
                    ans = i;
                    f++;
                 }
              }
              
              printf("Case #%d: ",tc++);
              if(f==0)
              {
                  printf("Volunteer cheated!\n");
              }
              else if(f==1)
              {
                  printf("%d\n",ans);
              }
              else
              {
                  printf("Bad magician!\n");
              }
    }
    //system("pause");
    return 0;
}
