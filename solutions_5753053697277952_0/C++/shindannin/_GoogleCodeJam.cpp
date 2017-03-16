// topcoder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <unordered_map>
#include "assert.h"

using namespace std;

static const double EPS = 1e-9;
template<class T> bool INRANGE(T x,T a,T b){return a<=x&&x<=b;}
template<class T> void amin(T &a,T v){if(a>v) a=v;}
template<class T> void amax(T &a,T v){if(a<v) a=v;}
int ROUND(double x) { return (int)(x+0.5); }
bool ISINT(double x) { return fabs(ROUND(x)-x)<=EPS; }
bool ISEQUAL(double x,double y) { return fabs(x-y)<=EPS*max(1.0,max(fabs(x),fabs(y))); }
double SQSUM(double x,double y) { return x*x+y*y; }
#define PI  (acos(-1))
#define ARRAY_NUM(a) (sizeof(a)/sizeof(a[0])) 
#define NG (-1)
#define BIG ((int)1e9)
#define BIGLL ((ll)4e18)
#define SZ(a) ((int)(a).size())
#define SQ(a) ((a)*(a))
typedef unsigned long long ull;
typedef long long ll;

#define PRINTF(fmt,...) fprintf(stderr,fmt,__VA_ARGS__); printf(fmt,__VA_ARGS__);

int main(){

	freopen("../_google_code_jam_input.txt","r",stdin);
	freopen("../_google_code_jam_output.txt","w",stdout);

	int T;
	scanf("%d ",&T);

	for (int testcase = 0; testcase < T; ++testcase)
	{
		int N;
		cin >> N;
		
		vector <pair <int, int> > vi(N);
		for(int i=0;i<N;++i)
		{
			int tmp;
			cin >> tmp;
			vi[i].first = tmp;
			vi[i].second = i;
		}
		
		vector <string> eva;
		while(1)
		{
			sort(vi.rbegin(),vi.rend());
			if(vi[0].first==0)
			{
				break;
			}
			
			string s;
			s += string(1, 'A'+vi[0].second);
			vi[0].first--;

			sort(vi.rbegin(),vi.rend());
			if(vi[0].first==0)
			{
				eva.push_back(s);
				break;
			}
			
			int sum = 0;
			for(int i=0;i<N;++i)
			{
				sum += vi[i].first;
			}
			
			
			if(vi[0].first*2>sum)
			{
				s += string(1, 'A'+vi[0].second);
				vi[0].first--;
			}
			eva.push_back(s);
		}
		
		
		
		PRINTF("Case #%d:",testcase+1);
		
		for(int i=0;i<SZ(eva);++i)
		{
			if(i==SZ(eva)-1)
			{
				PRINTF(" %s\n",eva[i].c_str());
			}
			else
			{
				PRINTF(" %s",eva[i].c_str());
			}
		}

	}

	return 0;
}
