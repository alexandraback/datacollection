#include <cstdio>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <memory.h>
#include <sstream>
#include <ctime>
#include <bitset>
using namespace std;

#pragma comment(linker, "/stack:64000000")

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

typedef vector<int> vi;
typedef vector<pair<int, int > > vii;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<ld> vld;

typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
typedef vector<vs> vvs;

typedef map<int, int> mpii;
typedef map<int, string> mpis;
typedef map<string, int> mpsi;
typedef map<string, string> mpss;

#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define sz(a) (int)((a).size())
#define len(a) (int)((a).length())

#define forr(i,n) for (int i = 0; i < (n); ++i)
#define fori(n) forr(i,n)
#define forj(n) forr(j,n)
#define fork(n) forr(k,n)
#define forin fori(n)
#define forjn forj(n)
#define forjm forj(m)
#define forkm fork(m)
#define foria(a) fori(sz(a))
#define foriv foria(v)
#define foris fori(len(s))
#define forja(a) forj(sz(a))
#define forjv forj(v)
#define forjs forj(len(s))

#define read cin>>
#define write cout<<
#define writeln write endl

#define readt int aaa; read aaa;
#define gett (bbb+1)
#define fort forr(bbb,aaa)

#define issa(a,s) istringstream a(s);
#define iss(s) issa(ss,s);

ld dis(ld x, ld y) {return sqrt(x*x+y*y);}
const ld PI = acos(ld(0.0))*2;

ll gcd(ll a, ll b){return b ? gcd(b,a%b) : a;}

template<class T>
struct makev
{
    vector<T> v;
    makev& operator << (const T& x)
    {
        v.push_back(x);
        return *this;
    }
    operator vector<T>& ()
    {
        return v;
    }
};

void assert(bool b)
{
    if (!b)
        throw 0;
}

template <int n>
struct nbest
{
    vector<pair<ll, int> > p;
    nbest():p(n+1)
    {
        foria(p) p[i].first = p[i].second = -1;
    }
    void add(ll value, int key)
    {
        p[n] = make_pair(value, key);
        sort(rall(p));
    }
    ll getValue(int pos, int exceptKey = -2)
    {
        if (exceptKey == -1)
            exceptKey = -2;
        if (p[pos].second == exceptKey)
            ++pos;
        return p[pos].first;
    }
    int getKey(int pos, int exceptKey = -2)
    {
        if (exceptKey == -1)
            exceptKey = -2;
        if (p[pos].second == exceptKey)
            ++pos;
        return p[pos].second;
    }
    bool has(int pos, int exceptKey = -2)
    {
        if (exceptKey == -1)
            exceptKey = -2;
        if (p[pos].second == exceptKey)
            ++pos;
        return p[pos].second != -1;
    }
};


struct angle
{
	double a;
	angle(double a_):a(a_)
	{
	}
	angle(int x, int y)
	{
		ll d = gcd(abs(x), abs(y));
		if (x == 0)
			d = abs(y);
		if (y == 0)
			d = abs(x);
		x /= d;
		y /= d;
		a = atan2((double)y, (double)x);
	}
	bool operator < (const angle &other) const
	{
		if (fabs(a - other.a) < 1e-12)
		{
			if (fabs(a - other.a) > 1e-14)
				throw 0;
			return false;
		}
		return a < other.a;
	}
	bool operator == (const angle &other) const
	{
		if (fabs(a - other.a) < 1e-12)
		{
			if (fabs(a - other.a) > 1e-14)
				throw 0;
			return true;
		}
		return false;
	}
	angle movePi()
	{
		angle result(a + PI);
		return result;
	}
};

vi solve(vi x, vi y)
{
	vi result(sz(x), 0);

	foria(result)
	{
		vector<angle> v;
		forja(result) if (i != j) v.push_back(angle(x[j] - x[i], y[j] - y[i]));

		sort(all(v));
		
		vector<angle> v3;
		forja(v) v3.push_back(v[j]);
		forja(v) v3.push_back(v[j].movePi());
		sort(all(v3));

		vector<angle> v2;
		forja(v) v2.push_back(v[j]);
		forja(v) v2.push_back(v[j].movePi().movePi());
		forja(v) v2.push_back(v[j].movePi().movePi().movePi().movePi());

		int n = sz(v);
		int ans = n;
		int lpos = 0;
		int rpos = 0;
		forja(v3)
		{
			angle from = v3[j], to = v3[j].movePi();
			while (lpos < sz(v2) && (v2[lpos] < from  || v2[lpos] == from))
				++lpos;
			while (rpos < sz(v2) && (v2[rpos] < to))
				++rpos;
			if (lpos == sz(v2)) throw 0;
			if (rpos == sz(v2)) throw 0;
			int dc = 0;
			if (rpos < sz(v2) && v2[rpos] == to)
				dc = 1;
			ans = min(ans, rpos - lpos - dc + 1);
		}
		result[i] = ans;
	}
	return result;
}


int main()
{
	ios::sync_with_stdio(false);
#ifdef _MSC_VER
	ifstream cin("input.txt");
	ofstream cout("output.txt");
#else
//	ifstream cin("input.txt");
//	ofstream cout("output.txt");
#endif

	readt;
	fort
	{
		int n;
		read n;
		vi x(n), y(n);
		forin read x[i] >> y[i];
		vi result = solve(x, y);
		cout << "Case #" << gett << ":" << endl;
		foria(result) cout << result[i] << endl;
	}

	return 0;
}