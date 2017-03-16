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

ifstream in("B-large.in");
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

template<class T> inline T gcd(T a,T b)//NOTES:gcd(
{if(a<0)return gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b)//NOTES:lcm(
{if(a<0)return lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}

///typedef ttmath::Int<10> ii;

#define max(a,b)            (((a) > (b)) ? (a) : (b))
#define min(a,b)            (((a) < (b)) ? (a) : (b))

//typedef ttmath::Int<10> II;///640 bits
typedef __int64 II;
//typedef ttmath::Big<1,10> DD;/// 64 exp ,640bits mant
typedef double DD;
#define INF 200000
vector<int> speed;
int theCase;
int B,N;
int slower;

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

II Consume(II puestos,vector<int> &d)
{
	II puestosPorBarbero = puestos/II(B);
	II tiempoToCut = puestosPorBarbero*slower;
	II estima = puestos;
	tiempoToCut *= 2;
	while(estima >= puestos)
	{
		estima = 0;
		tiempoToCut /=2;
		REP(i,B)
		{
			II tiempoToCutThis = tiempoToCut;//+d[i];
	//		if(d[i] != 0)
			{
				int ii = d[i];
				if(tiempoToCutThis < d[i])
					out << "OOOOOOOOOOOOPA";
				assert(tiempoToCutThis >= d[i]);
				tiempoToCutThis -= d[i];
				++estima;
			}
			estima += tiempoToCutThis/speed[i];
		}
	}
	II res = 0;
	REP(i,B)
	{
		II tiempoToCutThis = tiempoToCut;
		tiempoToCutThis -=d[i];
		d[i] = 0;
		res++;
		res +=tiempoToCutThis/speed[i];
		tiempoToCutThis %= speed[i];
		d[i] = speed[i] - tiempoToCutThis;
	}
	assert(res == estima);
	return res;

}
void Solve()
{
	II mcm;
	in >> B >> N;
	
	vector<int> times(B);
	speed = vector<int> (B);
//	mcm = 1;
	slower = 0;
	REP(i,B)
	{
		in >> speed[i];
	//	mcm *= speed[i];
		times[i] = 0;
		checkmax(slower,speed[i]);

	}

	/*speed.resize(1000);
	times.resize(1000);
//	mcm = 1;
	slower = 0;
	REP(i,B)
	{
		speed[i] = abs((rand()*100000)/RAND_MAX);
		assert(speed[i] <= 100000);
		times[i] = 0;
//		mcm = lcm(mcm,II(speed[i]));
		checkmax(slower,speed[i]);
	}*/
	
	
	/*II atendidosPorTanda = 0;
	REP(i,B)
	{
		II tmp = mcm/II(speed[i]);
		cout << "OPA  " << mcm << " " << II(speed[i]);
		assert(tmp>0);
		atendidosPorTanda += mcm/II(speed[i]);
		assert(atendidosPorTanda > 0);
		if(atendidosPorTanda  < 0)
		{
			int a = 0;
		}
		string s;
//		atendidosPorTanda.ToString(s);
		cout << i << " " << atendidosPorTanda << " " << s << endl;
	}
	II NN(N);
	NN = NN % atendidosPorTanda;*/
	II NN = N;
	//cout << mcm << " " << atendidosPorTanda <<endl;
	
	/*if(NN == 0)
	{
	  NN = atendidosPorTanda;
	}*/
	cout << "NN " << NN <<endl;
	if(theCase == 7)
	{
		int a = 0;
	}
	while(NN > 0)
	{
		if(NN > 1000000)
			NN -= Consume(NN/2,times);
		else
		{
			int minVal = FindMin(times);
			if(minVal != 0)
				Resto(times,minVal);

			REP(i,B)
			{
				if(times[i] == 0)
				{
					--NN;
					if(NN == 0)
					{
						out << (i+1);
						return;
					}
					times[i] = speed[i];
				}
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
		theCase = c;
		cout << c << endl;
		out << "Case #" << c+1 << ": ";
		Solve();
		out << endl;
	}	return 0;
}

