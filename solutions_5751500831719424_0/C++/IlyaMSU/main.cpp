#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>
#include<ctime>
#include<cstdio>

 
using namespace std; 
 
typedef long long ll; 
typedef unsigned int uint; 
typedef unsigned long long ull; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;

#define show(x) cerr << x
#define debug(x) show(#x << ": " << (x) << endl)

const long double PI = 3.14159265358979323846;  
const long double gammama = 0.57721566490153286060;
const long double eps = 1e-7;
const int INF = 1000 * 1000 * 1000 + 1;
const ll LINF = (ll)1000 * 1000 * 1000 * 1000 * 1000 * 1000;

const ll mod = 1000 * 1000 * 1000 + 7;


string solve() {
	int n;
	cin >> n;
	vector<string> a(n), b(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i) {
		b[i].push_back(a[i][0]);
		for (int j = 1; j < a[i].size(); ++j)
			if (a[i][j - 1] != a[i][j])
				b[i] += a[i][j];
	}
	string s = b[0];
	bool ok = true;
	for (int i = 0; i < n; ++i)
		ok = ok && (s == b[i]);
	if (!ok) 
		return "Fegla won";
	vector<vector<int> > c(n);
	for (int i = 0; i < n; ++i) {
		int cur = 1;
		for (int j = 1; j < a[i].size(); ++j) {
			if (a[i][j] == a[i][j - 1])
				++cur;
			else {
				c[i].push_back(cur);
				cur = 1;
			}
		}
		c[i].push_back(cur);
	}
	int res = 0;
	for (int i = 0; i < c[0].size(); ++i) {
		vector<int> d(n);
		for (int j = 0; j < n; ++j)
			d[j] = c[j][i];
		sort(d.begin(), d.end());
		int x = d[n / 2];
		for (int j = 0; j < n; ++j)
			res += abs(x - d[j]);
	}
	cout << res;
	return "";

	
}


int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt;
	//scanf("%d\n", &tt);
	cin >> tt;
	for (int i = 0; i < tt; ++i) {
		cout << "Case #" << i + 1 << ": ";
		cout << solve() << endl;
		std::cerr << i << endl;
	}
	return 0;
}
