#include <cstdlib>
#include <cmath>
#include <map>
#include <utility>
#include <set>
#include <sstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <numeric>
using namespace std;

#define	mp						make_pair
#define	pb						push_back
#define	bg						begin
#define	ed						end
#define	fs						first
#define	sc						second
#define	sz(x)					((int)((x).size()))
#define	For(i,a,b)				for(int i=(a);i<(b);++i)
#define	rep(i,n)				For(i,0,(n))
#define	rFor(i,a,b)				for(int i=(a);i>=(b);--i)
#define	rrep(i,n)				rFor(i,(n),0)
#define	all(v)					(v).begin(),(v).end()
#define	ITER(type)				type::iterator
#define	EACH(type,cont,it)		for(ITER(type) it=(cont).bg,s___=(cont).ed;it!=s___;++it)

typedef	long long				LL;
typedef	vector<int>				VI;
typedef	vector<LL>				VLL;
typedef	vector<vector<int> >	VVI;
typedef	vector<bool>			VB;
typedef	vector<string>			VS;
typedef	list<int>				LI;
typedef	list<LL>				LLL;
typedef	list<string>			LS;
typedef	pair<int,int>			PII;


PII solve()
{
	int N;

	cin >> N;

	vector<int> mi(N);
	rep(i, N)
		cin >> mi[i];

	PII res(0, 0);
	// first method
	For(i, 1, N) {
		if(mi[i-1] > mi[i])
			res.first += (mi[i-1] - mi[i]);
	}

	// second method
	int conrate = 0;
	For(i, 1, N) {
		if(conrate < mi[i-1] - mi[i])
			conrate = mi[i-1] - mi[i];
	}
	rep(i, N - 1) {
		if(conrate > mi[i])
			res.second += mi[i];
		else
			res.second += conrate;
	}

	return res;
}

int main()
{
	int T;
	cin >> T;
	rep(i, T) {
		cout << "Case #" << (i + 1) << ": ";
		PII r = solve();
		cout << r.first << " " << r.second << endl;
	}
}
