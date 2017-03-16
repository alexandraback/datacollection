#include<bits/stdc++.h>

#define gcd __gcd
#define bitcount __builtin_popcountll
#define getcx getchar
#define rep(i,j,n) for(i=j;i<n;i++)
#define tr(it,c) for(auto it=(c).begin();it!=(c).end();it++)
#define pb push_back
#define mp make_pair
#define hell 1000000007
#define uset unordered_set
#define umap unordered_map

using namespace std;

typedef pair<int,int> pi;
typedef long long ll;

const int MAXN = 16;
static int poss[1<<MAXN];
static int siz=0;
const int INF = hell;

void generatePoss(int N, int K,int bitno)
{
    if(bitcount(N)<K)
        return;
    if(bitcount(N)==K)
    {
        poss[siz++]=N;
        return;
    }
    if(bitno<0||K<0)
        return;
    //Check if state can occur.
    int temp = (1<<bitno) - 1;
    temp = temp&N;
    if(bitcount(N-temp)>K)
        return;
    if(bitcount(N-temp)==K)
    {
        poss[siz++]=(N-temp);
        return;
    }
    generatePoss((~(1<<(bitno-1)))&N,K,bitno-1);
    generatePoss(N,K,bitno-1);
}
int c[16+1][16+1];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out_B.txt","w",stdout);

   int T,i,res,R,C,N,M,j,k;
   cin>>T;

   for(int tt=1;tt<=T;tt++)
   {
       siz = 0;
       cout<<"Case #"<<tt<<": ";
       cin>>R>>C>>N;
       M = R*C;
       res = INF;
       generatePoss((1<<M)-1,N,M);
       rep(i,0,siz)
       {
           int n = poss[i];
           int z = 1<<(M-1);
           rep(j,0,R)
            rep(k,0,C)
            {
                c[j][k]=n&z;
                z>>=1;
            }
            int cost = 0;
           rep(j,0,R)
           {
               rep(k,0,C)
               {if(c[j][k+1]&&c[j][k]&&k+1<C)
                    cost++;
               if(c[j+1][k]&&c[j][k]&&j+1<R)
                cost++;
               }
           }
           res = min(res,cost);
       }
       cout<<res<<endl;
   }
}
