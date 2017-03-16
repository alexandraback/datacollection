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

int main() {
    // cout << setprecision(10);
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	int N;
	cin >> N;
	IntVec v(N);
	forall (i, N)
	    cin >> v[i];
	int m1 = 0;
	for (int i=1; i<N; i++)
	    m1 += max(v[i-1]-v[i], 0);
	int speed = 0;
	for (int i=1; i<N; i++)
	    speed = max(speed, v[i-1]-v[i]);
	int m2 = 0;
	for (int i=1; i<N; i++)
	    m2 += min(speed, v[i-1]);
	cout << "Case #" << iTask << ": " << m1 << ' ' << m2 << '\n';
    }
}
