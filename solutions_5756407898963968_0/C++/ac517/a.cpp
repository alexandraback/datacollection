#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cmath>
#include <map>
#include <set>
#include <algorithm>
#include <time.h>
#include <string.h>
#include <limits.h>
#include <stdio.h>

using namespace std;

#define FOR(i,a,b)  for(int i = (a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define S           size()
#define PB          push_back
#define ALL(a)      a.begin(),a.end()
#define MP          make_pair
#define V           vector
#define VI          V < int > 
#define VVI         V < VI >
#define VVVI		V < VVI >
#define VL			V < long long > 
#define VVL			V < VL >
#define VD          V < double >
#define VF          V < float >
#define VS			V < string >


string check(int g1, int g2, VVI c1, VVI c2)
{
	VI r1 = c1[g1-1];
	VI r2 = c2[g2-1];
	
	int cnt=0,num=-1;
	REP(i,4)
	{
		REP(j,4)
		{
			if(r1[i]==r2[j])
			{
				++cnt;
				num=r1[i];
			}
		}
	}
	
	if(cnt>1)
		return "Bad Magician!";
		
	if(cnt==0)
		return "Volunteer cheated!";
		
	stringstream ss;
	ss << num;
	return ss.str();
}


int main(int argc, char** argv)
{
	int n;
	++argv;
	ifstream in(*argv);
	
	in >> n;
	VS res;
	int g1,g2,tmp;
	REP(i,n)
	{
		in >> g1;
		VVI c1,c2;
		REP(j,4)
		{
			VI r;
			REP(k,4)
			{
				in >> tmp;
				r.PB(tmp);
			}
			c1.PB(r);
		}
		
		in >> g2;
		REP(j,4)
		{
			VI r;
			REP(k,4)
			{
				in >> tmp;
				r.PB(tmp);
			}
			c2.PB(r);
		}
		
		res.PB(check(g1,g2,c1,c2));
	}
				
	
	stringstream ss;
	REP(i,res.S)
	{
		ss << "Case #" << i+1 << ": " << res[i] << endl;
	}
	
	cout << ss.str();




}


