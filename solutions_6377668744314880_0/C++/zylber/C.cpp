#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <algorithm>
#define MOD 1000000007
#define forn(a, n) for(int a = 0; a<(int) (n); ++a)
#define dforn(a, n) for(int a = (n)-1; a>=0; --a)
#define forall(a, all) for(__typeof(all.begin()) a = all.begin(); a != all.end(); ++a)
#define EPS 0.000000000001
typedef long long tint;
using namespace std;

struct pto{
	tint x, y;
	tint n2(pto &p2) const{
		return (x-p2.x)*(x-p2.x)+(y-p2.y)*(y-p2.y);
	};
	pto(){};
	pto(tint xx, tint yy){ x=xx; y=yy; };
} r;

long long pcruz(tint x1, tint y1, tint x2, tint y2)
{
	return x1*y2-x2*y1;
}

long long area3(pto a, pto b, pto c)
{
	return pcruz(a.x-c.x, a.y-c.y, b.x-c.x, b.y-c.y);
}

pto p[10000];

bool men2(const pto &p1, const pto &p2)
{
	return (p1.y==p2.y)?(p1.x<p2.x):(p1.y<p2.y);
}

bool operator<(const pto &p1, const pto &p2)
{
	tint ar=area3(r, p1, p2);
	return (ar==0)?(p1.n2(r)<p2.n2(r)):ar>0;
}

typedef vector<pto> VP;
/*VP chull(VP & l)
{
	VP res=1;
	if(l.size()<3) return res;
	
	r = *(min_element(res.begin(), res.end()));
	sort(res.begin(), res.end());
	
	tint i=0;
	VP ch;
	ch.push_back(res[i++]);
	ch.push_back(res[i++]);
	
	while(i<res.size())
	{
		if(ch.size()>1 && area3(ch[ch.size()-2], ch[ch.size()-1], res[i])<0)
			ch.pop_back();
		else
			ch.push_back(res[i++]);
	}
	return ch;
}*/
int ans[10000];

int main()
{
#ifdef ACMTUYO
	freopen("C-small-attempt0(1).in","r",stdin);
	freopen("C-small-attempt0(1).out","w",stdout);
#endif

	int T;
	cin >> T;
	
	forn(tc,T)
	{
		int n;
		cin >> n;
		
		forn(i, n){ cin >> p[i].x >> p[i].y; ans[i]=n-1; }
		
		forn(i, n)
		{
			forn(j, i)
			{
				int p1=0, p2=0;
				forn(k, n)
				{
					if(area3(p[k], p[i], p[j])<=0) p1++;
					if(area3(p[k], p[i], p[j])>=0) p2++;
					
					int best=min(n-p1, n-p2);
					ans[i]=min(best, ans[i]);
					ans[j]=min(best, ans[j]);
				}
			}
		}
		
		cout << "Case #" << tc+1 << ": " << endl;
		forn(i, n) cout << ans[i] << endl;
	}
	return 0;
}
