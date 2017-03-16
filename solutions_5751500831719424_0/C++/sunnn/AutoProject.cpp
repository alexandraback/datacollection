#include <vector>
#include <string>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <functional>
#include <algorithm>
#include <numeric>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>

using namespace std;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define vs vector<string>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define vd vector<double>
#define vvd vector<vd>
#define vp vector<pii>
#define vvp vector<vp>
#define msi map<string, int>
#define mii map<int, int>

#define sqr(a) ((a) * (a))
#define two(n) (1 << (n))
#define twoLL(n) (1LL << (n))
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()

inline ll pow(int a, int b) { ll res = 1; for (int i = 1; i <= b; ++i) res *= a; return res; }
template<typename T> inline vector<T> split(string const & str, string const & delim = "") { string s = str; for (size_t i = 0; i < delim.size(); ++i) replace(s.begin(), s.end(), delim[i], ' '); vector<T> res; istringstream iss(s); T t; while (iss >> t) res.push_back(t); return res; }
template<typename R, typename T> inline R cast(T const & t) { stringstream ss; ss << t; R r; ss >> r; return r; }

template<typename T> inline bool btest(T num, int bit) { return (num & ((T)1 << bit)) != 0; }
template<typename T> inline int bcount(T num) { int res = 0; while (num != 0) { ++res; num &= num - 1; } return res; }
template<typename T> inline T bset(T num, int bit) { return num | ((T)1 << bit); }
template<typename T> inline T breset(T num, int bit) { return num & ~((T)1 << bit); }

#define inf 2100000000
#define eps 1e-9

string & flip(string & s, int mask)
{
	for (int i = 0; i < sz(s); ++i)
	{
		if (btest(mask, i))
		{
			if (s[i] == '0')
				s[i] = '1';
			else
				s[i] = '0';
		}
	}
	return s;
}

int main()
{
	string _task = "A";
	string _in = _task + "-small.in", _out = _task + "-small.out";
	//string _in = _task + "-large.in", _out = _task + "-large.out";
	ifstream fin(_in.c_str());
	ofstream fout(_out.c_str());

	string ts;
	getline(fin, ts);
	int _N = atoi(ts.c_str());

	for (int _n = 1; _n <= _N; ++_n)
	{
		getline(fin, ts);
		int n = atoi(ts.c_str());

		vs w(n);
		for (int i = 0; i < n; ++i)
		{
			getline(fin, w[i]);
		}

		vector<vs> parts(n);
		for (int i = 0; i < n; ++i)
		{
			string t(1, w[i][0]);
			for (int j = 1; j < sz(w[i]); ++j)
			{
				if (w[i][j] == w[i][j - 1])
					t += w[i][j];
				else
				{
					parts[i].push_back(t);
					t = w[i][j];
				}
			}
			parts[i].push_back(t);
		}

		vector<vs> inv(sz(parts[0]));
		for (int j = 0; j < sz(parts[0]); ++j)
			inv[j].push_back(parts[0][j]);

		bool ok = true;
		for (int i = 1; i < n; ++i)
		{
			if (sz(parts[i]) != sz(parts[0]))
			{
				ok = false;
				break;
			}
			for (int j = 0; j < sz(parts[i]); ++j)
			{
				if (parts[i][j][0] != parts[0][j][0])
				{
					ok = false;
					break;
				}
				inv[j].push_back(parts[i][j]);
			}
			if (!ok)
				break;
		}

		int res = 0;
		if (ok)
		{
			for (int i = 0; i < sz(inv); ++i)
			{
				nth_element(inv[i].begin(), inv[i].begin() + sz(inv[i]) / 2, inv[i].end());
				for (int j = 0; j < sz(inv[i]); ++j)
					res += abs(sz(inv[i][j]) - sz(inv[i][sz(inv[i]) / 2]));
			}
		}
		
		fout << "Case #" << _n << ": ";
		if (!ok)
			fout << "Fegla Won";
		else
			fout << res;
		fout << endl;
	}	

	return 0;
}
