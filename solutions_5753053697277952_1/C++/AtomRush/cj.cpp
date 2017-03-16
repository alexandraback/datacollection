#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef unsigned long long llu;

#define author ayushtomar
#define rf freopen("hah.in", "r", stdin)
#define wf freopen("out.txt", "w", stdout)
#define debug(x) cerr<<#x<<" "<<x<<endl;
#define f first
#define s second
#define mp make_pair
#define pb push_back
multiset < pii > ma;
int main()
{
    rf;
    wf;
    int t,n,x;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            ma.insert(mp(x,i));
        }

        printf("Case #%d:",tt);
        while(ma.size())
        {

            multiset < pii > :: iterator it=ma.end();
            it--;
            int x=it->first;
            int y=it->second;
            char a=(char)(it->second+'A' -1);
            ma.erase(it);
            x--;
            if(x>0)
            ma.insert(mp(x,y));
            if(ma.size()==2)
            {
                int arr[3];
                int counts=0,pos=0;
                for(multiset < pii > :: iterator it=ma.begin();it!=ma.end();it++)
                {
                    if(it->first==1)
                        {
                            counts++;
                           arr[pos++]=it->second;
                        }
                }
                if(counts==2)
                {
                    printf(" %c %c%c",a,arr[0]+'A'-1,arr[1]+'A'-1);
                    ma.clear();
                    break;
                }
            }
            it=ma.end();
            it--;
            x=it->first;
            y=it->second;
            char b=(char)(it->second+'A' -1);
            ma.erase(it);
            x--;
            if(x>0)
            ma.insert(mp(x,y));
            printf(" %c%c",a,b);
        }
                    printf("\n");



    }



 return 0;
}
