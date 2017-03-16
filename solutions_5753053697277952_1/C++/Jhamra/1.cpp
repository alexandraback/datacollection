#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pair<int,int> >
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define SIZE 10000002
using namespace std;

inline ll getnum()
{
    char c = getchar();
    ll num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}

int A[103];
multiset<int> Set;

int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);

    int tests=getnum();

    for(int cases=1;cases<=tests;cases++)
    {
        int n=getnum(),mx=0;

        for(int i=1;i<=n;i++)
        {
            A[i]=getnum();
            mx=max(mx,A[i]);
            Set.insert(A[i]);
            if(Set.size()>2)Set.erase(Set.begin());
        }
        printf("Case #%d:",cases);

        int x,y;

        for(int i=1;i<=n;i++)
        {
            if(A[i]==mx){x=i;break;}
        }

        mx=*Set.begin();
        Set.clear();

        while(A[x]>mx)putchar(' '),putchar(x+'A'-1),A[x]--;

        for(int i=1;i<=n;i++)
        {
            if(x==i)continue;
            if(mx==A[i]){y=i;break;}
        }

        for(int i=1;i<=n;i++)
        {
            if(x==i||y==i)continue;

            while(A[i]>0)putchar(' '),putchar(i+'A'-1),A[i]--;
        }

        while(A[x]>0)putchar(' '),putchar(x+'A'-1),putchar(y+'A'-1),A[x]--;

        puts("");
    }
}
