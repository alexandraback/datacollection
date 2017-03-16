#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>
#include <unordered_map>
#include <string>
#include <iomanip>
#include <vector>
#include <memory.h>
#include <queue>
#include <set>
#include <unordered_set>
#include <stack> 
#include <algorithm>
#include <math.h>
#include <sstream>
#include <functional>
#include <bitset>
#pragma comment (linker, "/STACK:167177216")
using namespace std;
#define mems(A, val) memset(A, val, sizeof(A))
#define mp(a, b) make_pair(a, b)
#define all(B) (B).begin(), (B).end()
#define forn(it, from, to) for(int it = from; it < to; ++it)
#define forit (it, coll) for(auto it = coll.begin(); it != coll.end(); ++it)
#define sz(a) (int)a.size()
#define pb push_back
const int MAXN = 2 * 1000 * 1000 + 500;
const double EPS = 1e-9;
typedef long long LL;

bool used[2 * 100 * 1000 + 500][55];
double D[2 * 100 * 1000 + 500][55];
int n, k;

vector<int> t;


double rec(int pos, int need){
	if (need == 0){
		if (pos == n) return 0.0;
		return 1e100;
	}
	if (pos == n){
		return 1e100;
	}

	double result = 1e200;
	double cur = 0.0;
	LL sum = 0;
	bool chaged = false;

	for (int i = pos; i < n; ++i){
		sum += t[i];
		if (i == pos){
			cur += 1.0;
		}
		else{
			double q = (double)t[i] / ((double)(sum));
			double q2 = (1 - q);
			cur += ((1) / (q2 - 1) / (q2 - 1))*q;
		}

		if (!used[i + 1][need - 1]){
			used[i + 1][need - 1] = true;
			D[i + 1][need - 1] = rec(i + 1, need - 1);
		}
		
		if (result < 1e90 && abs((cur + D[i + 1][need - 1]) - result) < 1e-6){
			return D[pos][need] = result;
		}
		else{
			chaged = true;
			result = min(result, cur + D[i + 1][need - 1]);
		}
		//result = min(result, cur + D[i + 1][need - 1]);
	}

	return D[pos][need]=result;
}

int main(int argc, char* argv[]) {

#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("numbers.in", "r", stdin); freopen("numbers.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	int tc;
	cin >> tc;
	forn(tcn, 0, tc)
	{
		int n;
		cin >> n;
		vector<int> a(n);
		vector<pair<int,int> > d;
		forn(i, 0, n){
			cin >> a[i];
			d.push_back(mp(a[i], i));
		}

		vector<string> ans;
		sort(all(d));
		if (n == 2){
			while (d[1].first > d[0].first){
				string str = "" ;
				str.push_back((char)('A' + d[1].second));
				ans.push_back(str);
				d[1].first--;
			}

			while (d[0].first > 0){
				string str = "";
				str.push_back((char)('A' + d[1].second));
				str.push_back((char)('A' + d[0].second));
				ans.push_back(str);
				d[0].first--;
				d[1].first--;
			}
		}
		else{
			while (d[n - 1].first > d[n - 2].first){
				string str = "";
				str.push_back((char)('A' + d[n-1].second));
				ans.push_back(str);
				d[n-1].first--;
			}

			for (int i = 0; i < n - 2; ++i){
				for (int j = 0; j < d[i].first; ++j){
					string str = "";
					str.push_back((char)('A' + d[i].second));
					ans.push_back(str);
				}

			}

			while (d[n - 1].first > 0){
				string str = "";
				str.push_back((char)('A' + d[n - 1].second));
				str.push_back((char)('A' + d[n - 2].second));
				ans.push_back(str);
				d[n - 1].first--;
				d[n - 2].first--;
			}
		}


		cout << "Case #" << tcn + 1 << ": ";
		forn(i, 0, ans.size()){
			cout << ans[i] << " ";
		}
		cout << endl;

	}


	return 0;
}