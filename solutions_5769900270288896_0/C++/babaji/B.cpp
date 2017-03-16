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

int row,col;

bool done[20][20];

pair<short,short> value[17][17][1<<17];

void fill_up(int mask)
{
   fill(done,0);

   int aval=0;

   for(int i=0;i<(row*col);i++)
     if( mask &(1<<i))
        {
            int r=i/col;
            int c=i%col;

            done[r][c]=true;

            aval++;
        }

    //calaute unhappy

    int ans=0;

    //up to down in evry column

    for(int c=0;c<col;c++)
      for(int r=1;r<row;r++)
        if( done[r-1][c] && done[r][c])
          ans++;

    //left to right in every row

    for(int r=0;r<row;r++)
      for(int c=1;c<col;c++)
        if( done[r][c-1] && done[r][c])
           ans++;

    value[row][col][mask]=mp(aval,ans);
}

void solve(int test)
{
   short ans=10000;

   short r,c,n,a,b;

   cin>>a>>b>>n;

   r=min(a,b);
   c=max(a,b);

   for(int i=0;i<(1<<(r*c));i++)
     if( value[r][c][i].X ==n)
       ans=min( ans , value[r][c][i].Y );

    printf("Case #%d: %d\n",test,ans);


}


int main()
{


    for(row=1;row<=16;row++)
     for(col=row;col<=16;col++)
       {
           if( row*col > 16)
            continue;

            for(int mask=0;mask<(1<<(row*col));mask++)
             fill_up(mask);
       }


      // cout<<"done";

    int test;

    cin>>test;

    for(int i=1;i<=test;i++)
    {
        solve(i);
    }

    return 0;
}
