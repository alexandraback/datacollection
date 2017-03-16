// B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <map>
#include <set>
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cassert>
#include <math.h>
//http://www.ttmath.org/
#include "ttmath\ttmath.h"

using namespace std;

ifstream in("B-small-attempt1.in");
ofstream out("out.txt");
///LLONG_MAX,INT_MA
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define REP(i,n) FOR(i,0,(n)-1)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define sz size()
template<class T> inline int size(const T& c) { return c.sz; }
#define FORA(i,c) REP(i,size(c))

#define itype(c) __typeof((c).begin())
#define FORE(e,c) for(itype(c) e=(c).begin();e!=(c).end();e++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SORT(x) sort(all(x))
#define REVERSE(x) reverse(all(x))
#define CLEAR(x,c) memset(x,c,sizeof(x)) 
#define amfor(Iterator, Container) 	for ( auto Iterator = begin(Container); (Iterator) != end(Container); ++(Iterator) )
#define ramfor(Iterator, Container) for ( auto Iterator = Container.rbegin(); (Iterator) != Container.rend(); ++(Iterator) )
template<class C, class E> inline bool contains(const C& container, const E& element){	return container.find(element) != container.end() ;}

template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//asigna en a el minimo
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//asigna en a el maximo
///typedef ttmath::Int<10> ii;

#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))

///typedef ttmath::Int<10> II;///640 bits
typedef __int64 II;
//typedef ttmath::Big<1,10> DD;/// 64 exp ,640bits mant
typedef double DD;
#define INF 200000

int B,N;

int FindMin(vector<int> &d)
{
	int minVal = INF;
	REP(i,B)
	{
		if(d[i] == 0)
			return i;
		checkmin(minVal,d[i]);
	}
	return minVal;
}

void Resto(vector<int> &d,int val)
{
	REP(i,B)
		d[i] -= val;
}

void Solve()
{
	__int64 mcm;
	in >> B >> N;
	vector<int> speed(B);
	vector<int> times(B);
	mcm = 1;
	REP(i,B)
	{
		in >> speed[i];
		mcm *= speed[i];
		times[i] = 0;
	}

	__int64 atendidosPorTanda = 0;
	REP(i,B)
		atendidosPorTanda += mcm/speed[i];
	N = N % atendidosPorTanda;

	if(N == 0)
	{
	/*	out << 1;
		return;*/
	  N = atendidosPorTanda;
	}
	while(N > 0)
	{
		int minVal = FindMin(times);
		if(minVal != 0)
			Resto(times,minVal);

		REP(i,B)
		{
			if(times[i] == 0)
			{
				--N;
				if(N == 0)
				{
					out << (i+1);
					return;
				}
				times[i] = speed[i];
			}
		}
	}

	//	out << n;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int ccc;
	in >> ccc;
	cout << ccc << endl;
	out << std::setprecision(15);
	out << std::fixed;

	REP(c,ccc)
	{
		cout << c << endl;
		out << "Case #" << c+1 << ": ";
		Solve();
		out << endl;
	}	return 0;
}

