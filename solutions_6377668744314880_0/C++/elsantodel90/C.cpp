#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <cstdio>
#include <cstdlib>
#include <numeric>
#include <functional>
#include <algorithm>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s);i--)

#define forall(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define dforall(i,c) for(typeof((c).rbegin()) i = (c).rbegin(); i != (c).rend(); i++)
#define all(c) (c).begin(),(c).end()

#define esta(x,c) ((c).find(x) != (c).end())
#define zMem(c) memset((c),0,sizeof(c))

typedef long long tint;
typedef long double tdbl;

typedef pair<int,int> pint;
typedef pair<tint,tint> ptint;

typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;

typedef tint tipo;
#define sqr(x) ((x)*(x))
tipo pcruz(tipo x1,tipo y1,tipo x2,tipo y2){return x1*y2-x2*y1;}
struct pto {
  tipo x,y;
  tipo n2(pto &p2)const{
    return sqr(x-p2.x)+sqr(y-p2.y);
  }
} r;
tipo area3(pto a, pto b, pto c){
  return pcruz(b.x-a.x,b.y-a.y,c.x-a.x,c.y-a.y);
}
bool men2(const pto &p1, const pto &p2){
  return (p1.y==p2.y)?(p1.x<p2.x):(p1.y<p2.y);
}
bool operator<(const pto &p1,const pto &p2){
  tipo ar = area3(r,p1,p2);
  return(ar==0)?(p1.n2(r)<p2.n2(r)):ar>0;
  //< clockwise, >counterclockwise
}
typedef vector<pto> VP;
VP chull(VP & l){
  VP res = l;  if(l.size()<3) return res;
  r = *(min_element(res.begin(),res.end(),men2));
  sort(res.begin(),res.end());
  int kk = res.size() - 1;
  if (area3(r, res[kk], res[1]) == 0)
    return res;
  while (area3(r, res[kk], res[kk-1]) == 0) kk--;
  reverse(res.begin() + kk, res.end());
  tint i=0;VP ch;ch.push_back(res[i++]);ch.push_back(res[i++]);
  while(i<(int)res.size())  // area3 > clockwise, < counterclockwise
    if(ch.size()>1 && area3(ch[ch.size()-2],ch[ch.size()-1],res[i])<0)
      ch.pop_back();
    else
      ch.push_back(res[i++]);
  return ch;
}

VP v;

struct normalcomp
{
    bool operator ()(const pto &a, const pto &b)
    {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    }
};

int main()
{
	int totalCasos;
	cin >> totalCasos;
	forn(caso,totalCasos)
	{
        int n; cin >> n;
        v.resize(n);
        forn(i,n) cin >> v[i].x >> v[i].y;
        int cost[16];
        const int INF = 1000000000;
        forn(i,n) cost[i] = INF;
        map<pto, int, normalcomp> pid;
        forn(i,n) pid[v[i]] = i;
        forsn(mask,1, (1<<n))
        {
            int dist = n - __builtin_popcount(mask);
            VP cv;
            forn(i,n) if (mask & (1<<i)) cv.push_back(v[i]);
            VP chu = chull(cv);
            for(pto x : chu)
                cost[pid[x]] = min(cost[pid[x]], dist);
        }
		cout << "Case #" << caso + 1 << ":" << endl;
        forn(i,n) cout << cost[i] << endl;
	}
	return 0;
}
