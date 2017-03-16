#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
#include<map>
#include<list>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>




#define FOREACH(it,c) for(auto it=(c).begin();it!=(c).end();++it)
#define all(s) s.begin(),s.end()
#define pb push_back
#define mp make_pair
#define sd(x) scanf("%d",&x)
#define sl(x) scanf("%I64d",&x)
#define pd(x) printf("%d",x)
#define ll long long
const int mod = ((1E9)+7);
const int intmax = ((1E9)+7);




#ifndef ONLINE_JUDGE
#define TRACE
#endif
#ifdef TRACE
    #define trace(x)            cerr<<x<<endl;
    #define trace1(x)           cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<endl;
    #define trace2(x,y)         cerr<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<endl;
    #define trace3(x,y,z)       cout<<__FUNCTION__<<":"<<__LINE__<<": "#x" = "<<x<<" | "#y" = "<<y<<" | "#z" = "<<z<<endl;
#else
    #define trace(x)
    #define trace1(x)
    #define trace2(x,y)
    #define trace3(x,y,z)
#endif

using namespace std;




int mat[10][10];





int x,r,c,N;




int unhappy()
{
    int sum=0;



    for(int i=0;i<r;i++)
    for(int j=0;j<c-1;j++)
    {
        if(mat[i][j]==1&&mat[i][j+1]==1)
            sum+=1;

    }


    for(int j=0;j<c;j++)
     for(int i=0;i<r-1;i++)
    {

        if(mat[i][j]==1&&mat[i+1][j]==1) sum+=1;
    }

    return sum;
}





int rec(int a,int b,int sum)
{

    if(sum==N) return unhappy();

    if(sum>=N) return intmax;

    if(a>=r) return intmax;



    for(int i=0;i<c;i++)
    {
        mat[a][i]=0;
    }


    for(int k=0;k<5;k++)
    {

        if(b&(1<<k))
        {

            mat[a][k]=1;
            sum=sum+1;
            if(sum==N)
            {
                return  unhappy();
            }
        }
    }


    int min_=intmax;

    for(int i=0;i<x;i++)
    {

        min_=min(min_,rec(a+1,i,sum));
    }

    return  min_;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int test,a,b;



    sd(test);
    int t=1;

    while(test--)
    {
        sd(r);
        sd(c);
        sd(N);
        int d=c;

        x=(1<<d);

        memset(mat,0,sizeof(mat));

        int min_=intmax;

        for(int i=0;i<x;i++)
        {

            min_=min(min_,rec(0,i,0));
        }

        cout<<"Case #"<<t<<": "<<min_<<endl;
        t++;

    }

    return 0;


}
