#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#define eps 1e-8
#define db double
#define rt return
#define cn const
#define op operator
#define N 1010
#include<queue>
using namespace std;

int d[N];

int gcd(int a,int b)
{
    return b==0? a:gcd(b,a%b);
}

struct P
{
    int t;
    int id;
   P(int a=0,int b=0):t(a),id(b){}
    bool operator < (const P& a)const{
        if(t!=a.t) return t>a.t;
        return id > a.id;
    }
};

priority_queue<P> q;

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("b.out","w",stdout);

    int T;
    scanf("%d",&T);

    for(int ca=1;ca<=T;ca++)
    {
        int n,b;
        scanf("%d%d",&b,&n);

        for(int i=0;i<b;i++)
              scanf("%d",&d[i]);

        printf("Case #%d: ",ca);

        int ans=0;

        int temp = d[0];
        for(int i=0;i<b;i++)
        {
            int w= gcd(temp,d[i]);
            temp = temp*d[i]/w;
        }

//        printf("temp = %d\n",temp);

        int cnt=0;
        for(int i=0;i<b;i++)
        {
            cnt+= temp/d[i];
        }

        n= n%cnt;
        if(n==0) n=cnt;
//printf("n= %d  cnt =%d\n",n,cnt);

        if(n<=b) printf("%d\n",n);
        else{
                while(!q.empty()) q.pop();

            for(int i=0;i<b;i++)
                 q.push(P(d[i],i+1));

            n-=b;


            while(n)
            {
                P a= q.top();q.pop();
               // printf("%d  %d----  %d\n",a.t,a.id,n);
                n--;
                if(n==0) printf("%d\n",a.id);

                a.t+= d[a.id -1];
                q.push(a);
            }
        }

    }
    return 0;
}
/*
3
3 11
4 2 1

*/
