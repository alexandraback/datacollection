//darkstallion's template

#include<bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define popb pop_back
#define del erase
#define sz size
#define ins insert
#define FOR(a,b,c) for(int a = b; a < c; a++)
#define FORS(a,b,c) for(int a = b; a <= c; a++)
#define FORN(a,b) for(int a = 0; a < b; a++)
#define FORD(a,b,c) for (int a = b; a >= c; a--)
#define RES(a,b) memset(a,b,sizeof(a))
#define LL long long
#define PII pair<int,int>
#define PLL pair<long long,long long>
#define PDD pair<double,double>
#define PCC pair<char,char>
#define PSS pair<string,string>
#define PI acos(-1)
#define eps 1e-9
using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  FORN(i,t)
  {
    int b,n;
    scanf("%d%d",&b,&n);
    n--;
    int arr[b], z = 1;
    FORN(j,b)
    {
      scanf("%d",&arr[j]);
      z = z*arr[j]/__gcd(z,arr[j]);
    }
    vector<int> order;
    priority_queue<PII, vector<PII>, greater<PII> > pq;
    FORN(j,b)
      pq.push(mp(0,j));
    while (pq.sz())
    {
      PII tmp = pq.top();
      pq.pop();
      if (tmp.fi == z)
        break;
      order.pb(tmp.se+1);
      pq.push(mp(tmp.fi+arr[tmp.se],tmp.se));
    }
    n %= (int)order.sz();
    printf("Case #%d: %d\n",i+1,order[n]);
  }
}