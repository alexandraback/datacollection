#include<bits/stdc++.h>
#include<string>
using namespace std;


typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define s(n)                        scanf("%d",&n)
#define s2(q,w)                        scanf("%d %d",&q,&w)
#define s3(q,w,e)                        scanf("%d %d %d",&q,&w,&e)
#define pb(x)            push_back(x)

#define INF                         (int)1e9
#define EPS                         1e-9

#define checkbit(n,b)                ( (n >> b) & 1)

int mod = 10000007;

long long pwr(long long a,long long b,long long mod)
{
  if(b==0)
    return 1;
  long long temp=pwr(a,b/2,mod);
  temp=(temp*temp)%mod;
  if(b&1)
    temp=(temp*a)%mod;
  return temp;
}
long long pwr(long long a,long long b)
{
  if(b==0)
    return 1;
  long long temp=pwr(a,b/2);
  temp=(temp*temp);
  if(b&1)
    temp=(temp*a);
  return temp;
}
bool* isPrime;
void generatePrimeSieve(const int lim)
{
  isPrime=(bool *)malloc(lim+1);
  memset(isPrime,true,lim+1);
  isPrime[0]=false;
  isPrime[1]=false;
  for(int i=2;i<=lim;++i)
    if(isPrime[i])
      for(int j=i+i;j<=lim;j+=i)
        isPrime[j]=false;
}
#define matrix vector<vector<int> >
matrix identityMatrix;
matrix mul(const matrix &a,const matrix &b)
{
  int n=a.size();
  matrix ans(n,vector<int> (n) );
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      for (int k = 0; k < n; ++k)
      {
        ans[i][j]+= ((long long)a[i][k]*b[k][j])%mod;
        ans[i][j]%=mod;
      }
    }
  }
  return ans;
} 
matrix pwr(const matrix &a,long long n)
{
    if(n==0)
    {
      /*define identity */
      assert(false);
      return identityMatrix;
    }
    if(n==1)
     return a;
    matrix tmp=pwr(a,n/2);
    tmp=mul(tmp,tmp);
    if(n&1)
      tmp=mul(a,tmp);
    return tmp;
}
long long gcd(long long a,long long b)
{
  return b==0?a:gcd(b,a%b);
}
long long lcm(long long a,long long b)
{  
  return (a/gcd(a,b))*b;
}
long long modularInverse(long long a,long long m)
{
      return pwr(a,m-2,m);
}
int arr[20][20];
int n,m,x;

int isValid(int x,int y)
{
  if(x>=0 && x<n && y>=0 && y<m)
    return 1;
  return 0;
}

int find(int mask)
{

  // cout<<mask<<endl;

  int k=1;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      // cout<<mask<<" "<<k<<" "<<(mask&(k))<<endl;
      if((mask&(k))>0)
          arr[i][j]=1;
      else
        arr[i][j]=0;

      k=k*2;
    }
  }
  int ans = 0;
  // cout<<n<<" "<<m<<endl;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      // cout<<arr[i][j]<<"-"<<ans<<" ";
      if(arr[i][j])
      {

      if(isValid(i-1,j) && arr[i-1][j])
        ans++;

      if(isValid(i+1,j) && arr[i+1][j])
        ans++;
      if(isValid(i,j-1) && arr[i][j-1])
        ans++;
      if(isValid(i,j+1) && arr[i][j+1])
        ans++;

      arr[i][j]=0;
    }
    }
    // cout<<endl;
  }
  return ans;


}

int anss = INF;
int dp[(1<<16) +5][17];

  
int func(int mask,int index)
{
  if(index > n*m)
    return 0;
  if(dp[mask][index] != -1)
    return 0;
  if(index==n*m)
  {
  int c = __builtin_popcount(mask);
  if(c==x)
    anss = min(anss,find(mask));
  }

  func(mask,index+1);
  func(mask+(1<<(index)),index+1);
  dp[mask][index] = 1;
}



int main()
{
  freopen("B-small-attempt0.in","r",stdin);
  freopen("B-small-attempt0.out","w",stdout);


  int t;
  s(t);
  int ans = 0;

  int h=1;
  while(t--)
  {

    s3(n,m,x);
    anss = INF;
    memset(dp,-1,sizeof dp);
    func(0,0);
    printf("Case #%d: %d\n",h,anss);
    h++;

  }
    

}

