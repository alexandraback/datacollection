#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#define INP_FILE "input.txt"
#define OUT_FILE "output.txt"

#define rp(i,n) for(int (i)=0;(i)<(n);++(i))
#define pb push_back
#define L(s) (int)s.size()
#define mp make_pair
#define pii pair<int,int>
#define x first 
#define y second
#define inf 1000000000
#define VI vector<int>
#define ll long long
#define all(s) (s).begin(),(s).end()
#define C(u) memset((u),0,sizeof((u)))
#define ull unsigned ll
#define uint unsigned int


int main()
{
	freopen( INP_FILE , "r" , stdin );
	freopen( OUT_FILE , "w" , stdout );
	int tstCnt;
	cin>>tstCnt;

	for(int tst=1;tst<=tstCnt;tst++)
	{
        int n; cin>>n;
        string line;getline(cin, line);
        
        vector<vector<pair<char, int> > > a;
        rp(i, n) {
            getline(cin, line);
            a.pb(vector<pair<char, int> > ());
            vector<pair<char, int> > &t = a.back();
            char prev = 255;
            int sz = line.size();
            rp(j, sz) {
                if (line[j] == prev) {
                    t.back().second++;
                } else {
                    prev = line[j];
                    t.pb(mp<char, int>(prev, 1));
                }
            }
        }
        bool good = true;
        for(int (i)=1;(i)<(n);++(i)) {
            vector<pair<char, int> > &q = a[i];
            vector<pair<char, int> > &w = a[i-1];
            if (q.size() != w.size()) {
                good = false; break;
            }
            rp(j, q.size()) {
                if (q[j].first != w[j].first) {
                    good = false; break;
                }
            }
        }
        printf("Case #%d: ",tst);
        if (!good) {
            printf("Fegla Won\n");continue;
        }

        vector<int> z;
        int m = a[0].size();
        int ans = 0;
        rp(i, m) {
            z.clear();
            rp(j, n) {
                z.pb(a[j][i].second);
            }
            sort(all(z));
            int cur = 0; rp(j, n) { cur += (z[n-1] - z[j]); }
            int best = cur;
            for (int j = n-2; j>=0; --j) {
                cur += (z[j+1]-z[j])*(n-2*(j+1));
                best = min(best, cur);
            }
            ans += best;
        }
        printf("%d\n",ans);

		//
	}
	
	return 0;
}