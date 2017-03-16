#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <bitset>
#include <utility>
#include <functional>
#include <string>
#include <algorithm>

#include <cstring>
#include <cstdio>
#include <memory.h>
#include <ctime>
#include <cassert>
#include <cmath>

using namespace std;

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define ford(i,n) for(int i = int(n) - 1; i >= 0; i--)
#define fore(i,a,b) for(int i = int(a); i <= int(b); i++)
#define foreach(it,a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)

#define sz(a) int((a).size())
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ft first
#define sc second

template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pr;
typedef pair<ld, ld> ptd;

#define PI 3.14159265
#define EPS 1E-4

void solveA()
{
	int T;
	cin >> T;
	forn(t, T)
	{
		int mx1[4][4], mx2[4][4];
		int a1, a2;
		cin >> a1;
		forn(i, 4)
			forn(j, 4)
			cin >> mx1[i][j];

		cin >> a2;
		forn(i, 4)
			forn(j, 4)
			cin >> mx2[i][j];

		set<int> s1, s2, inter;
		forn(i, 4)
			s1.insert(mx1[a1-1][i]);
		forn(i, 4)
			s2.insert(mx2[a2-1][i]);
		set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(inter, inter.begin()));

		cout << "Case #" << t + 1 << ": ";
		if (inter.size() == 1)
			cout << *inter.begin() << endl;
		else if (inter.size() < 1)
			cout << "Volunteer cheated!" << endl;
		else
			cout << "Bad magician!" << endl;
	}
}

int main() {
#ifdef diametralis
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	solveA();
#ifdef diametralis
	cerr << "Time == " << clock() << endl;
#endif
}