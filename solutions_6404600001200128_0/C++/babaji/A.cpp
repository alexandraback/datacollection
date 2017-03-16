#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;

#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
#define sz(s) ((int)(s.size()))

vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}


/*Solution code starts here */

ll in[10009];

void solve(int test)
{
  ll n;

  cin>>n;

  for(int i=1;i<=n;i++)
    cin>>in[i];

  //By opt 1
  ll op1 =0 ;
  for(int i=1;i<n;i++)
   op1+=max( 0LL , in[i]-in[i+1]);

  //By op2
   ll op2 =0;

   ll mx = 0;

   for(int i=1;i<n;i++)
     mx = max( mx , in[i]-in[i+1]);

   for(int i=1;i<n;i++)
     {
         ll aval = min( mx ,in[i] );

         op2+=aval;
     }

    printf("Case #%d: %lld %lld\n",test,op1,op2);

}


int main()
{

    int test;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        solve(i);
    }

    return 0;
}
