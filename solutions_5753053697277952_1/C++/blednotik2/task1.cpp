#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cassert>
#include <cstdlib>
#include <cstdio>

using namespace std;

#define forall(i,n) for(int i=0; i<(int)(n); i++)

typedef vector<int> IntVec;
typedef long long ll;
typedef unsigned long long ull;

template<class T, class T1, class T2> inline bool Within(T x, T1 xMin, T2 xMax)
    {return (x >= xMin && x <= xMax);}
template<class T, class T1> inline bool Within(T x, T1 xMax)
    {return (x >= 0 && x < xMax);}

template<class T> void PrintVec(const vector<T>& v, const char* s=NULL) {
    if (s)
	cout << s << ' ';
    forall (i, v.size())
	cout << v[i] << ' ';
    cout << endl;
}

template<class T> void PrintVec(const char* s, const vector<T>& v) {
    PrintVec(v, s);
}

typedef pair<int, char> Party;

int main() {
    // cout << setprecision(10);
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	int nSen;
	cin >> nSen;
	vector<Party> vp;
	forall (i, nSen) {
	    int n;
	    cin >> n;
	    vp.push_back(make_pair(n, 'A'+i));
	}
	if (vp.size() < 3)
	    vp.push_back(make_pair(0, '+'));
	if (vp.size() < 4)
	    vp.push_back(make_pair(0, '-'));
	assert(vp.size() >= 4);
	cout << "Case #" << iTask << ": ";
	bool bFirst = true;
	while (true) {
	    sort(vp.rbegin(), vp.rend());
	    int& i0=vp[0].first;
	    int& i1=vp[1].first;
	    const int i2=vp[2].first, i3=vp[3].first;
	    const char c0=vp[0].second, c1=vp[1].second;
	    // DEBUG!!!
	    // cout << i0 << c0 << ' ' << i1 << c1 << ' ' << i2 << ' ' << i3 << endl;

	    if (i0 == 0) {
		cout << '\n';
		break;
	    }
	    if (!bFirst)
		cout << ' ';
	    bFirst = false;
	    if (i0 > i1 && i0 > 1) {
		cout << c0 << c0;
		i0 -= 2;
	    }
	    else if (i0 == 1 && i1 == 0) {
		cout << c0;
		i0--;
	    }
	    else {
		assert(i0 == i1);
		if (i1 > i2 || i0 > 1 || i3 > 0) {
		    cout << c0 << c1;
		    i0--;
		    i1--;
		} else {
		    assert(i0 == 1 && i1 == 1 && i2 == 1 && i3 == 0);
		    cout << c0;
		    i0--;
		}
	    }
	}
    }
}
