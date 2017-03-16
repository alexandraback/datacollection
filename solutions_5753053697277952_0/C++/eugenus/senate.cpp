#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <vector>
#include <cstring>
#include <set>

#define forn(i,n) for(int i = 0; i < (n); i++)
#define forsn(i,s,n) for(int i = (s); i < (n); i++)
#define all(v) ((v).begin, (v).end)
#define pb push_back
#define x first
#define y second
#define mp make_pair

using namespace std;

typedef pair<int,int> par;
typedef long long int tint;


int main()
{
	freopen("test.txt","r",stdin);
	freopen("testout.txt","w",stdout);
	
	int t,n;

	cin >> t;

	forsn(caso,1,t+1)
	{
		cin >> n;
		set<par, std::greater<par> > p; int c;
		int tot = 0;
		forn(i,n)
		{
			cin >> c;
			tot += c;
			p.insert(mp(c,i));
		}

		vector<string> ans;

		while(tot)
		{
			int sen = p.size();
			par f = *p.begin();
			p.erase(f);
			par s = *p.begin();
			int c = f.x;
			int d = s.x;
			string a = "";
			if(c > 1)
			{
				if( (tot - 2) >= 2 * (c - 2) and (tot - 2) >= 2 * d )
				{
					tot -= 2;
					f.x = c - 2;
					if(f.x > 0) p.insert(f);
					forn(i,2) a += (char)('A'+f.y);
					ans.pb(a);
				}
				else
				{
					if( (tot - 2) >= 2 * (c - 1))
					{
						tot -= 2;
						f.x = c - 1;
						p.erase(s);
						s.x--;
						if(f.x) p.insert(f);
						if(s.x) p.insert(s);
						a += (char)('A'+f.y);
						a += (char)('A'+s.y);
						ans.pb(a);
					}
					else
					{
						f.x = c - 1;
						tot -= 1;
						if(f.x) p.insert(f);
						a += (char)('A'+f.y);
						ans.pb(a);
					}
				}
			}
			else
			{
				if(sen & 1)
				{
					tot--;
					a += (char)('A'+f.y);
					ans.pb(a);
				}
				else
				{
					tot -= 2;
					a += (char)('A'+f.y);
					a += (char)('A'+s.y);
					ans.pb(a);
				}
			}

			//cout << a << endl;
		}

		int m = ans.size();

		cout << "Case #" << caso << ":";
		forn(i, m) cout << " " << ans[i];
		cout << endl;
	}

	return 0;
}