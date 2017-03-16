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

#define inf 2100000000
#define eps 1e-9

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
		// don't forget to clear all global objects!

		getline(fin, ts);
		int r1 = atoi(ts.c_str()) - 1;

		vvi b1(4);
		for (int i = 0; i < sz(b1); ++i)
		{
			getline(fin, ts);
			b1[i] = split<int>(ts);
			sort(all(b1[i]));
			assert(b1.size() == 4);
		}

		getline(fin, ts);
		int r2 = atoi(ts.c_str()) - 1;

		vvi b2(4);
		for (int i = 0; i < sz(b2); ++i)
		{
			getline(fin, ts);
			b2[i] = split<int>(ts);
			sort(all(b2[i]));
			assert(b2.size() == 4);
		}

		vi res;
		for (int i = 0; i < sz(b1[r1]); ++i)
		{
			if (binary_search(all(b2[r2]), b1[r1][i]))
				res.push_back(b1[r1][i]);
		}
		
		fout << "Case #" << _n << ": ";
		if (res.empty())
		{
			fout << "Volunteer cheated!";
		}
		else if (res.size() == 1)
		{
			fout << res[0];
		}
		else
		{
			fout << "Bad magician!";
		}
		fout << endl;
	}	

	return 0;
}
