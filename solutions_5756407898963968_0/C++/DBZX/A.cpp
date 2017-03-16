// A.cpp : Defines the entry point for the console application.
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

using namespace std;

ifstream in("A-small-attempt0.in");
ofstream out("out.txt");

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
#define metafor(c,i) for(i = c.begin();i != c.end();++i)
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}//asigna en a el minimo
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}//asigna en a el maximo

///LLONG_MAX,INT_MAX
#define INF INT_MAX

void Solve()
{
	int r1;
	in >> r1;
	set<int> valid;
	REP(i,4)
	{
		REP(j,4)
		{
			int n;
			in >> n;
			if(i+1 == r1)
				valid.insert(n);
		}	
	}	

	int r2;
	in >> r2;
	set<int> valid2;
	REP(i,4)
	{
		REP(j,4)
		{
			int n;
			in >> n;
			if(i+1 == r2 && valid.find(n) != valid.end())
			{
				valid2.insert(n);
			}
		}	
	}	
	if(valid2.size() == 0)
		out << "Volunteer cheated!";
	else if(valid2.size() == 1)
		out << *valid2.begin();
	else
		out << "Bad magician!";
}

int _tmain(int argc, _TCHAR* argv[])
{
	int ccc;
	in >> ccc;
	REP(c,ccc)
	{
		out << "Case #" << c+1 << ": ";
		Solve();
		out << endl;
	}	return 0;
}

