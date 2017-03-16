//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 1000000007
#define INF 2147483647
#define PI 3.1415926535897932384626433832795
#define all(cont) cont.begin(),cont.end()
#define init(a,val) memset(a,val,sizeof(a))
#define F first
#define S second
#define mp make_pair
//GLOBAL

int main()
{
    //freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

    int test,i,j,r,k,flag,num,tt;
    bool h[20];
    cin>>test;
    for(tt=1;tt<=test;tt++)
    {
        init(h,false);
        cin>>r;
        for(i=1;i<=4;i++)for(j=1;j<=4;j++)
        {
            cin>>k;
            if(i==r)h[k]=true;
        }
        cin>>r;
        flag=0;
        for(i=1;i<=4;i++)for(j=1;j<=4;j++)
        {
            cin>>k;
            if(i==r && h[k]){flag++;num=k;};
        }
        if(flag>1)printf("Case #%d: Bad magician!\n",tt);
        else if(flag)printf("Case #%d: %d\n",tt,num);
        else printf("Case #%d: Volunteer cheated!\n",tt);
    }

return 0;
}
