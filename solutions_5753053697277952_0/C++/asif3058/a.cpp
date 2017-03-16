#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

#define mx 10000000
#define ip freopen("a.txt","r",stdin)
#define op freopen("out.txt","w",stdout)

#define sint1(a) scanf("%d",&a)
#define sint2(a,b) scanf("%d %d",&a,&b)
#define sint3(a,b,c) scanf("%d %d %d",&a,&b,&c)


#define sch1(a) scanf("%c",&a)
#define sch2(a,b) scanf("%c %c",&a,&b)
#define sch3(a,b,c) scanf("%c %c %c",&a,&b,&c)


#define sll1(a) scanf("%lld",&a)
#define sll2(a,b) scanf("%lld %lld",&a,&b)
#define sll3(a,b,c) scanf("%lld %lld %lld",&a,&b,&c)

#define ll long long int

#define lpi0(a,b) for(int a=0;a<b;a++)
#define lpd0(a,b) for(int a=b-1;a>=0;a--)

#define lpi1(a,b) for(int a=1;a<=b;a++)
#define lpd1(a,b) for(int a=b;a>0;a--)

#define vi vector<int>
#define pii pair<int,int>
#define mp make_pair

#define pi acos(-1)

#define mm(a,b) memset(a,b,sizeof(a))

struct node{
    int x;
    char ch;
    bool operator <(const node &b) const
    {
        return x<b.x;
    }
};

int main()
{
//    ip;
//    op;
    int t;
    int cs=1;

    sint1(t);

    while(t--)
    {
        int n;

        int s=0;

        sint1(n);
        node p[100];

        for(int i=0;i<n;i++)
        {
            p[i].ch=i+'A';
            sint1(p[i].x);

            s+=p[i].x;

            //cout<<p[i].ch<<" "<<p[i].x<<endl;
        }

        printf("Case #%d:",cs++);
        while(s)
        {
//            cout<<"yes"<<endl;
            sort(p,p+n);
//            cout<<p[0].x<<" "<<n<<endl;

//            for(int i=0;i<n;i++)
//            {
//                cout<<"A "<<p[i].ch<<" "<<p[i].x<<endl;
//            }

//            break;


            if(p[n-1].x==p[n-2].x)
            {
                if(s==3)
                {
                    printf(" %c",p[n-1].ch);
                    s-=1;
                    p[n-1].x-=1;
                    continue;
                }
                printf(" %c%c",p[n-1].ch,p[n-2].ch);
                s-=2;
                p[n-1].x-=1;
                p[n-2].x-=1;
            }
            else
            {
                printf(" %c",p[n-1].ch);
                s-=1;
                p[n-1].x-=1;

            }

        }
        cout<<endl;

    }


}
