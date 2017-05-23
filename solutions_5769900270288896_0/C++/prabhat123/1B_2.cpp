#include<bits/stdc++.h>
#define D 1000000007
#define gcd __gcd
#define getcx getchar
#define pc putchar
#define mp make_pair
#define get(x) scanf("%d",&x)
#define getl(x) scanf("%lld",&x)
#define print(x) printf("%d\n",x)
#define printl(x) printf("%lld\n",x)
#define bitcount __builtin_popcount
using namespace std;
typedef long long ll;
int main()
{
    ifstream IF;
    ofstream OF;
    int t,n,l,i,j,k,f,x,ans,r,c;
    IF.open("input.txt");
    OF.open("output.txt");
    IF >> t;
    for(i=1;i<=t;i++)
    {
        IF >> r >> c >> n;
        k=(r*c+1)/2;ans=0;
        if(n>k)
        {
            if(r==1 || c==1)
            {
                if((r*c)%2)
                    ans=(n-k)*2+1;
                else
                    ans=(n-k)*2;
            }
            else if(r==2 || c==2)
            {
                if(n==k+1)
                    ans=2;
                else if(n==k+2)
                    ans=4;
                else if(n=k+3)
                    ans=7;
                else if(n=k+4)
                    ans=10;
                else if(n=k+5)
                    ans=13;
                else if(n=k+6)
                    ans=16;
                else if(n=k+7)
                    ans=19;
                else if(n=k+8)
                    ans=22;
            }
            else if(r==3|| c==3)
            {
                 if(r==3 && c==3)
                 {
                     if(n==6)
                        ans=3;
                     else if(n==7)
                        ans=6;
                     else if(n==8)
                        ans=8;
                     else if(n==9)
                        ans=12;
                 }
                 else if(r==4 || c==4)
                 {
                     if(n==7)
                        ans=2;
                     else if(n==8)
                        ans=4;
                     else if(n==9)
                        ans=7;
                     else if(n==10)
                        ans=10;
                     else if(n==11)
                        ans=13;
                     else if(n==12)
                        ans=17;
                 }
            }
            else if(r==4 && c==4)
            {
                if(n==9)
                    ans=2;
                else if(n==10)
                    ans=4;
                else if(n==11)
                    ans=7;
                else if(n==12)
                    ans=10;
                else if(n==13)
                    ans=13;
                else if(n==14)
                    ans=16;
                else if(n==15)
                    ans=20;
                else if(n==16)
                    ans=24;
            }
        }
        OF << "Case #" << i << ": " << ans << endl;
    }
    IF.close();
    OF.close();
    return 0;
}


