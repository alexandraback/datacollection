#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fore(i,n) for(int i = 0; i< n ; i++ )
#define lop(i,n) for(int i = 1 ; i<=n ; i++ )
#define ops(i,n) for(int  i = n-1 ; i>=0 ; i-- )
#define	forall( it,g )	for(typeof(g.begin()) it=g.begin();it!=g.end();it++ )
#define PI  3.141592653589793
#define mod  1000000007
#define inf 10000000000
#define INF -100000000000
#define modulo 1073741824
#define MH 1234533333333337
#define MM 1793723455573331
//ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
using namespace std;
typedef vector <int > vi;
typedef vector <vector <int> > vv;
typedef vector <pair <int,int > >vp;
typedef vector <vector <pair <int ,int > > > vvp;
typedef vector <pair <int ,pair <int ,int > > > vpp;
typedef pair<int,int> pp;
typedef  long long ll;
bool visit[18][18];
int n ,r,c ;
int check(){
  int x = 0;
  fore(j , r)
    fore(i , c-1)
      if(visit[j][i] == visit[j][i+1] && visit[j][i])
        x++;
  fore(j , c)
    fore(i , r-1)
      if(visit[i][j] == visit[i+1][j]&& visit[i][j])
        x++;
  return x;
}
vp index;
int ways(int ind,int s){
  if(s == 0)return check();
  if(ind==index.size())return 1000000;
  int x = index[ind].first , y = index[ind].second;
  visit[x][y] = true;
  int a = ways(ind+1,s-1);
  visit[x][y] = false;
  int b = ways(ind+1,s);
  return min(a,b);
}
int main()
{
  ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
  freopen("B-small-attempt0.in","r",stdin);
  freopen("out.txt","w",stdout);
  int test ,x = 0;
  cin >> test;
  while(test--){
    x++;
    cin >> r >> c >> n ;
    fore(i , r)
      fore(j , c)
        index.pb(mp(i,j));
    memset(visit,false,sizeof visit);
    cout << "Case #" << x << ": "<<ways(0,n)<<endl;
    index.clear();
  }
  return 0;
}

