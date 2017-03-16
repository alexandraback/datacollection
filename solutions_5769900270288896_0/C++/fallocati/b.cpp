#include <algorithm>
#include <numeric>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
#include <cassert>
#include <bitset>
#include <cstring>

using namespace std;

#define DECL(v, c)					decltype(c) v = c

// Util Constants
#define INF							(int)1e9
#define EPS							1e-9
#define PI 							3.1415926535897932384626

// Math Shortcuts
#define MAX(a,b)					((a) > (b) ? (a) : (b))
#define MIN(a,b)					((a) < (b) ? (a) : (b))
#define ABS(v)						((v) < 0 ? (-v) : (v))

// Bit Operations
#define BIT(v,b)					((v) & (1 << b)) //select the bit of position i of x
#define LOWBIT(v) 					((v) & ((v) ^ ((v) - 1))) //get the lowest bit of x

// Bound Checking
#define IN(i,l,r) 					(l < i && i < r) 
#define LINR(i,l,r) 				(l <= i && i <= r)
#define LIN(i,l,r) 					(l <= i && i < r)
#define INR(i,l,r) 					(l < i && i <= r)

// Loops
#define FOR(i,s,n)					for(int (i) = ((int)(s)); (i) < ((int)n); (i)++)
#define DFORN(i,s,n)				for(int (i) = ((int)(n)) - 1; i >= ((int)s); (i)--)

// Iterations
#define FOREACH(v, c)				for(DECL(v, (c).begin()); v != (c).end(); ++v)
#define DFOREACH(v, c)				for(DECL(v, (c).rbegin()); v != (c).rend(); ++v)

// Container Operations
#define SZ(c)						((int)(c.size()))
#define ALL(c)						(c).begin(), (c).end()
#define RALL(c)						(c).rbegin(), (c).rend()
#define ISIN(v,c)					((c).find(v) != (c).end())
#define ISIN2(v,c)					(find(ALL(c),v) != (c).end())

// Vector Operations
#define PB							push_back
#define LAST(c)						c[SZ(c) - 1]

// Pair Operations
#define MP							make_pair
#define FI							first
#define SE							second

// Debug
#define D(a)						cerr << #a << " = " << a << endl;
template<typename T1, typename T2> inline ostream& operator << (ostream& os, const pair<T1, T2>& p) {return os << "(" << p.FI << ", " << p.SE << ")";}
template<typename T> inline ostream &operator << (ostream & os,const vector<T>& v) {bool first = true; os << "[";FOR(i,0,SZ(v)){if(!first)os << ", ";os << v[i];first = false;}return os << "]";}
template<typename T> inline ostream &operator << (ostream & os,const set<T>& v) {bool first = true;os << "[";FOREACH(ii,v){if(!first)os << ", ";os << *ii;first = false;} return os << "]";}
template<typename T1, typename T2> inline ostream &operator << (ostream & os,const map<T1, T2>& v) {bool first = true;os << "[";FOREACH(ii,v){if(!first)os << ", ";os << *ii ;first = false;}return os << "]";}

typedef long long int tint;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<tint> vt;
typedef vector<vt> vvt;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<string> vs;
typedef pair<int,int> pii;

void printapt(vvb apt, int r, int c)
{
	cout << endl << endl;
	
	FOR(i, 0, r)
	{
		FOR(j, 0, c)
		{
			cout << (apt[i][j] ? 'x' : 'o') << ' ';
		}
		cout << endl;
	}
	
	cout << endl << endl;
}

int bestSolution;

void backtrack(vvb& apt, int r, int c, int n, int cost)
{
	if (n == 0)
	{
		if (cost < bestSolution)
		{
			//printapt(apt, r, c);
			bestSolution = cost;
		}
		
		return;
	}
	
	FOR(i, 0, r)
	{
		FOR(j, 0, c)
		{			
			if (!apt[i][j])
			{
				apt[i][j] = true;
				int newCost = cost;
				
				if (i > 0)
				{
					if (apt[i - 1][j])
					{
						newCost += 1;
					}
				}
				
				if (j > 0)
				{
					if (apt[i][j - 1])
					{
						newCost += 1;
					}
				}
				
				if (i < r - 1)
				{
					if (apt[i + 1][j])
					{
						newCost += 1;
					}
				}
				
				if (j < c - 1)
				{
					if (apt[i][j + 1])
					{
						newCost += 1;
					}
				}
				
				backtrack(apt, r, c, n - 1, newCost);
				
				apt[i][j] = false;
			}
		}
	}
}

int fillA(vvb& apt, int r, int c, int n)
{
	FOR(i, 0, r)
	{
		FOR(j, 0, c)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 1)
				{
					apt[i][j] = true;
					n--;
				}		
			}
			else
			{
				if (j % 2 == 0)
				{
					apt[i][j] = true;
					n--;
				}
			}
			
			if (n == 0)
			{
				return 0;
			}
		}
	}
	
	return n;
}

int fillB(vvb& apt, int r, int c, int n)
{
	FOR(i, 0, r)
	{
		FOR(j, 0, c)
		{
			if (i % 2 == 0)
			{
				if (j % 2 == 0)
				{
					apt[i][j] = true;
					n--;
				}
			}
			else
			{
				if (j % 2 == 1)
				{
					apt[i][j] = true;
					n--;
				}
			}
			
			if (n == 0)
			{
				return 0;
			}
		}
	}
	
	return n;
}

void solve()
{
	int r, c, n;
	cin >> r >> c >> n;
	
	if (n == 0)
	{
		cout << 0;
		return;
	}
	
	vvb aptA(r, vb(c, false));		
	int missingA = fillA(aptA, r, c, n);	
	bestSolution = INF;
	backtrack(aptA, r, c, missingA, 0);
	int solutionA = bestSolution;

	
	vvb aptB(r, vb(c, false));		
	int missingB = fillB(aptB, r, c, n);	
	bestSolution = INF;
	backtrack(aptB, r, c, missingB, 0);
	int solutionB = bestSolution;
		
	cout << MIN(solutionA, solutionB);
}

int main()
{
	DECL(ncas,0);
	cin >> ncas;
		
	FOR(cas,1,ncas + 1)
	{
		cout << "Case #" << cas << ": ";		
		
		solve();
		
		// End Code
		
		cout << endl;
	}

	return 0;
}