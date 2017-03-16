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

// min and max time till they wholly serve N customers
void TimeLimits(const IntVec& v, int N, ull& tmin, ull& tmax) {
    double prod = 0.; // total productivity
    forall (i, v.size())
	prod += 1./v[i];
    tmin = N / prod * 0.999999;
    tmax = (N + v.size()) / prod * 1.000001;
}

// number of customers already served at time t
int NumServed(const IntVec& v, ull t) {
    int n=0;
    forall (i, v.size())
	n += t / v[i];
    return n;
}

// number of customers already served, or in service, at time t
int NumServedTot(const IntVec& v, ull t) {
    int n=0;
    forall (i, v.size())
	n += (t+v[i]-1) / v[i];
    return n;
}

// when at least N customers will be served? (N>0)
// nServed - how many customers served at this moment?
void TimeToService(const IntVec& v, int N, ull& t, int& nServed) {

    assert(N>0);

    // obtain tmin, tmax s.t. nmin<N, nmax>=N
    ull tmin, tmax;
    TimeLimits(v, N, tmin, tmax);
    if (tmin > 0)
	tmin--;
    int nmin = NumServed(v, tmin);
    int nmax = NumServed(v, tmax);

    while (true) {
	if (nmin >= N) cerr << "nmin=" << nmin << " N=" << N << endl;
	if (nmax < N) cerr << "nmax=" << nmax << " N=" << N << endl;
	assert(nmin < N);
	assert(nmax >= N);
	if (tmin + 1 == tmax) {
	    t = tmax;
	    nServed = nmax;
	    return;
	}
	const ull tmed = (tmin + tmax) / 2;
	const int nmed = NumServed(v, tmed);
	if (nmed < N) {
	    nmin = nmed;
	    tmin = tmed;
	}
	else {
	    nmax = nmed;
	    tmax = tmed;
	}
    }
}

// which barber serves N-th customer?
int Barber(const IntVec& v, int N) {
    const int B = v.size();
    if (N <= B)
	return N;
    ull t;
    int nServed;
    TimeToService(v, N-B, t, nServed);
    int nNew=0;
    forall (i, B)
	if (t % v[i] == 0)
	    nNew++;
    int nLeft = N-(nServed-nNew+B);
    assert(nLeft>0);
    forall (i, B)
	if (t % v[i] == 0) {
	    nLeft--;
	    if (nLeft == 0)
		return i+1;
	}
    cerr << "Error: no barber found" << endl;
    exit(0);
    return 0;
}


int main() {
    // cout << setprecision(10);
    int nTasks;
    cin >> nTasks;
    for (int iTask=1; iTask<=nTasks; iTask++) {
	int B, N;
	cin >> B >> N;
	IntVec v(B);
	forall (i, B)
	    cin >> v[i];
	cout << "Case #" << iTask << ": " << Barber(v, N) << '\n';
    }
}
