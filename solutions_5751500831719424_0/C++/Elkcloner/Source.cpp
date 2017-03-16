//IN THE NAME OF GOD
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <fstream>
#include <utility>
#include <sstream>
#include <list>
#include <iomanip>
#include <functional>
#include <deque>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <complex>
#include <climits>
#include <cctype>
#include <cassert>
#include <bitset>
#include <limits>
#include <numeric>

//#pragma comment(linker, "/STACK:1024000000,1024000000")

using namespace std;

#define timestamp(x) printf("Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define INF 1000000000
#define pii pair < int , int >
#define MP make_pair
#define MOD 1000000007
#define EPS 1e-9
#define LL long long
#define MAXN 300000+10
#define bug cout<<"!!!!!!!!!!!!!!!!!";

int main()
{
	ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("output.out", "w", stdout);
#endif
	int tc , n , tcc = 1 ;
	vector < vector < pair < char, int > > > vc;
	vector < pair < char, int > > tmpvc ;
	string a;
	cin >> tc;
	while (tc--){
		vc.clear();
		cout << "Case #" << tcc++ << ": ";
		cin >> n;
		while (n--){
			cin >> a;
			char ch = a[0];
			int cnt = 1;
			tmpvc.clear();
			for (int i = 1; i < a.size(); i++){
				if (a[i] == ch) cnt++;
				else{
					tmpvc.push_back(MP( ch, cnt));
					cnt = 1;
					ch = a[i];
				}
			}
			tmpvc.push_back(MP(ch, cnt));
			vc.push_back(tmpvc);
		}
		bool f = 0 ;
		for (int i = 0; i < vc[0].size(); i++){
			for (int j = 0; j < vc.size(); j++){
				if (vc[j].size() != vc[0].size()){
					f = 1;
					break;
				}
				if (vc[j][i].first == vc[0][i].first) continue;
				f = 1;
				break;
			}
			if (f) break;
		}
		if (f){
			cout << "Fegla Won" << endl;
			continue;
		}
		int ans = 0 , res , tmpres ;
		for (int i = 0; i < vc[0].size(); i++){
			tmpres = INF;
			for (int j = 0; j < vc.size(); j++){
				res = 0;
				for (int t = 0; t < vc.size(); t++){
					if (t == j) continue;
					res += abs(vc[t][i].second - vc[j][i].second);
				}
				tmpres = min(res, tmpres);
			}
			ans += tmpres;
		}
		cout << ans << endl;
	}
	return 0;
}