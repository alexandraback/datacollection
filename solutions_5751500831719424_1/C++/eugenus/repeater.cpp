#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
#include <cassert>
#include <bitset>
#include <cstring>
using namespace std;


#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define D(a) cerr << #a << "=" << a << endl;
#define pb push_back
#define mp make_pair

int main()
{
	int t, n;
	string words[110];
	int count[110];
	int ord[110];
	int initpos[110];
	map<string, vector<string> > info;
	cin >> t;
	forn(caso, t){
		cin >> n;
		info.clear();
		forn(i,n) cin >> words[i];
		
		forn(i,n){
			string cand = ""; cand += words[i][0];
			int pos = 0;
			int k = words[i].size();
			forn(j,k){
				if(words[i][j] != cand[pos]){
					cand += words[i][j];
					pos++;
				}
			}
			//cout << i << " : " << cand << endl;
			info[cand].pb(words[i]);
		}
		std::map<string, vector<string> >::iterator it;
		string selected;
		bool pos = false;
		for(it = info.begin(); (it != info.end()) and !pos; it++){
			if( (it->second).size() == n ){
				selected = (it->first);
				pos = true;
			}
		}
		cout << "Case #" << (caso+1) << ": ";
		if(pos){
			int s = selected.size();
			int res = 0;
			forn(i,n) initpos[i] = 0;

			forn(i,s){
				char act = selected[i];
				int tot = 0;
				forn(j,n){
					int ca = 0;
					int k = words[j].size();
					//cout << words[j] << endl;
					forsn(l,initpos[j],k){
						if(words[j][l] == act) ca++;
						else break;				
					}
					//cout << ca << endl;
					count[j] = ca;
					ord[j] = ca;
					initpos[j] += ca;
				}
				sort(ord, ord + n);
				int med = ord[n/2];
				forn(j,n){
					if(count[j] < med) tot += med-count[j];
					else tot += count[j] - med;
				}
				//forn(j,n) cout << count[j] << " "; cout << endl;
				//cout << selected[i] << " : " << tot << " " << med << endl;
				res += tot;
			}

			cout << res << endl;
		}
		else{
			cout << "Fegla won" << endl;
		}
	}
	return 0;
}
