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
ll bc ,my;

inline ll cont( ll tm)
{
    ll ans =0 ;

    for(int i=1;i<=bc;i++)
     ans+=tm/in[i];

     return ans;
}

void solve(int test)
{

    scanf("%lld%lld",&bc,&my);

    for(int i=1;i<=bc;i++)
    {
         scanf("%lld",&in[i]);
    }

    ll lo =0 , hi = (1LL<<61);

    while( lo < hi)
    {
        ll mid = (lo+hi)/2LL;

        if( cont(mid) + bc >= my)//true condn
          hi=mid;
        else
          lo=mid+1;
    }

   //print(lo);

    ll done = cont(lo);//itna to bhai kat chuka hai

    //print(done);

    int ans = -1;

     //inka kat raha hai
    for(int i=1;i<=bc;i++)
      if( (lo % in[i])!=0)
        {
          done++;
        }

    // print(done);
      assert( done < my);

    //abhi jo ready, hai unme my ka numer
     for(int i=1;i<=bc;i++)
      if( (lo % in[i])==0)
        {
            //can serve to
            done++;
            if( done==my)
             ans=i;
        }

    assert(ans!=-1);

    printf("Case #%d: %d\n",test,ans);

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
