#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <utility>
#include <iterator>
#include <fstream>
#include <cstdio>
#include <functional>

using namespace std;

template<class T>
string tostring(T a){ stringstream ss; ss << a; return ss.str(); }

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> II;
#define SZ(a) int((a).size()) 
#define PB push_back 
#define ALL(c) (c).begin(),(c).end() 
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOOP(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(a,b) make_pair((a),(b))
#define LAST(t) (t[SZ(t)-1])

int main(){
	ifstream be("A-large.in");
	ofstream ki("ki.txt");
	int T;
	be >> T;
	FOR(tt, T){
		int n; be >> n;
		vector<vector<pair<int,char>>> vs;
		{string s;  getline(be, s); }
		FOR(i, n){
			string s;  getline(be, s);
			vector<pair<int, char>> v;
			FOR(j, SZ(s)){
				int k = 0;
				while(j < SZ(s) && s[j] == s[j + 1]){
					j++;
					k++;
				}
				v.push_back(make_pair(k + 1, s[j]));
			}
			vs.push_back(v);
		}
		int l = SZ(vs[0]);
		bool ok = true;
		FOR(i,n)
			if(SZ(vs[i])!=l)
				goto nem;

		int s = 0;
		FOR(j, l){
			char c = vs[0][j].second;
			FOR(i, n){
				if(vs[i][j].second != c)
					goto nem;
			}
			VI ms;
			FOR(i, n)
				ms.push_back(vs[i][j].first);
			nth_element(ms.begin(), ms.begin() + n / 2, ms.end());
			int med = ms[n / 2];
			int cs = 0;
			FOR(i, n){
				cs += abs(vs[i][j].first - med);
			}
			s += cs;
		}
		ki << "Case #" << tt + 1 << ": " << s << endl;
		continue;
	nem:
		ki << "Case #" << tt + 1 << ": Fegla Won\n";
	}


	ki.close();
	return 0;
}