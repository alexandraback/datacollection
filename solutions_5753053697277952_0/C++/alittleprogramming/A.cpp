//OUM HARI OUM, OUM TATSAT
// OUM NAMA VAGABATE BASUDEBAY
// OUM NAMA MA SWARASATI OUM NAMA

#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<sstream>
#include<stack>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

#define cl(vctr) vctr.clear()
#define ms(v, ar) memset(ar, v, sizeof(ar))

const double pi=(double)(2.0 * acos( 0.0 ));
const int inf=1 << 30;
const double eps=1E-9;
const double e = exp(1.0);
const int sz=100000 + 5;
const int mod=1000000000 + 7;

using namespace std;
typedef long long int ll;

int a[27];
typedef pair<int,int>pii;
pii ar[sz],tmp,tmp1;

int main()
{
    freopen("Ain.in","r",stdin);
    freopen("Aout.in","w",stdout);
    int t,T,i,j,k,n,tt,e,f,g,h;
    scanf("%d",&t);T=t;
    while(t--)
    {
        scanf("%d",&n);
        tt=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            tt+=a[i];
        }
        priority_queue<pii> Q;
        for(i=0;i<n;i++)
        {
            Q.push(make_pair(a[i],i));
        }
        k=0;
        while(!Q.empty())
        {
            tmp=Q.top();
            Q.pop();
            e=tmp.first;
            f=tmp.second;
            tmp1=Q.top();
            Q.pop();
            g=tmp1.first;
            h=tmp1.second;
            if(e-g==0)
            {
                if(tt>3||tt==2)
                {
                    ar[k++]=make_pair(f,h);
                    e--;tt--;
                    g--;tt--;
                }
                else
                {
                    ar[k++]=make_pair(f,-1);
                    e--;tt--;
                }
            }
            else
            {
                if(tt>3)
                {
                    ar[k++]=make_pair(f,f);
                    e--;tt--;
                    e--;tt--;
                }
                else
                {
                    ar[k++]=make_pair(f,-1);
                    e--;tt--;
                }
            }
            if(e>0) Q.push(make_pair(e,f));
            if(g>0) Q.push(make_pair(g,h));
        }
        printf("Case #%d:",T-t);
        for(i=0;i<k;i++)
        {
            printf(" %c",'A'+ar[i].first);
            if(ar[i].second!=-1)
                printf("%c",'A'+ar[i].second);
        }
        printf("\n");
    }

    return 0;
}
