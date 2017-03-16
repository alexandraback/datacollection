#include <string>
#include <map>
#include <math.h>
#include <sstream>
#include <time.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

#define fx first
#define sx second

typedef pair<int,int> ii;
typedef vector<int> vec;
typedef vector<ii> vecp;
typedef long long int lli;
typedef unsigned long long int ulli;

void Print(int* v, int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout<<v[i]<<" ";
	}
}

int minInd(int* l, int n)
{
	int _min = 1e9;
	int minInd;
	for (int i = 0; i < n; ++i)
	{
		if(l[i]<_min) 
		{
			_min = l[i];
			minInd = i;
		}
	}
	return minInd;
}

ulli gcd(ulli x, ulli y)
{
  if(x<y) return gcd(y,x);
  if(y==1) return 1;
  if(x%y==0) return y;
  return gcd(y,x%y);
}

int func(int* m, int b, int n)
{
	ulli totTime = 1;
	for (int i = 0; i < b; ++i)
	{
		totTime*=(m[i]/gcd(m[i],totTime));
	}

	ulli tot = 0;
	for (int i = 0; i < b; ++i)
	{
		tot+=totTime/m[i];
	}
	
	n%=tot;
	if(n==0) n+=tot;
	int* times = new int[b]();
	cout<<n<<endl;

	int ind;
	while(n>0)
	{
		--n;
		ind = minInd(times,b);
		cout<<ind+1<<" ";
		times[ind]+=m[ind];
		//Print(times,b);
	}
	cout<<endl;
	return ind+1;
}

int main()
{
	ifstream input;
	input.open("b-small0.in",ios::in);
	ofstream out;
	out.open("b.out",ios::out);

	int count;
	input>>count;

	for (int i = 1; i <= count; ++i)
	{
		int b,n;
		input>>b>>n;
		int* m = new int[b];
		for (int i = 0; i < b; ++i)
		{
			input>>m[i];
		}

		//printing the output
		out<<"Case #"<<i<<": ";
		out<<func(m,b,n);
	
		if(i<count) out<<endl;
	}

	return 0;
}
