/*
Author:
Prob:
Link:
Tag:
Comp:
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ii pair<int,int>
#define iii pair<ii, int>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ep emplace_back
#define sz(a) (int) a.size()
#define cl(a) a.clear()

#define vi vector<int>
#define vii vector<ii>

#define FOR(x,a,b) for (int x=a;x<=b;x++)
#define FOD(x,a,b) for (int x=a;x>=b;x--)
#define REP(x,a,b) for (int x=a;x<b;x++)
#define RED(x,a,b) for (int x=a;x>b;x--)

const int MAX = 1e5 + 10;
const int MAXN = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;

int main(){
	// freopen("test.in", "rt", stdin);
	freopen("A-large.in", "rt", stdin);
	freopen("A-large.ou", "wt", stdout);
	ios::sync_with_stdio(false);

	int t, n, x;

	cin >> t;
	FOR(cs,1,t){
		priority_queue<ii> pq;
		ii fir, sec;
		int tot = 0;

		cin >> n;
		REP(i,0,n){
			cin >> x;
			pq.push(mp(x, i));
			tot += x;
		}

		cout << "Case #" << cs << ":";
		while (pq.size()){
			fir = pq.top(); pq.pop();
			sec = pq.top(); pq.pop();
			if (!pq.size()){
				if (fir.fi == 3 && sec.fi == 2){
					cout << " " << char(fir.se + 'A');
					fir.fi--;
					tot--;
				}
				else {
					if (fir.fi - sec.fi > 1){
						cout << " " << char(fir.se + 'A') << char(fir.se + 'A');
						fir.fi -= 2;
					}
					else{
						cout << " " << char(fir.se + 'A') << char(sec.se + 'A');
						fir.fi--; sec.fi--;
					}
					tot -= 2;
				}
			}
			else{
                if (pq.size() == 1 && fir.fi + sec.fi + pq.top().fi == 3){
                    cout << " " << char(fir.se + 'A');
					fir.fi--;
					tot--;
                }
                else {
                    if (sec.fi*2 > tot-2){
                        cout << " " << char(fir.se + 'A') << char(sec.se + 'A');
                        fir.fi--; sec.fi--;
                    }
                    else{
                        cout << " " << char(fir.se + 'A') << char(fir.se + 'A');
                        fir.fi -= 2;
                    }
                    tot -= 2;
                }
			}
			if (fir.fi > 0)
				pq.push(fir);
			if (sec.fi > 0)
				pq.push(sec);
		}
		cout << endl;
	}

	return 0;
}
