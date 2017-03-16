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

void Print(vec v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		cout<<v[i]<<" ";
	}
}

int func1(int* m, int n)
{
	int tot = 0;
	for (int i = 1; i < n; ++i)
	{
		if(m[i]<m[i-1]) tot+=m[i-1]-m[i];
	}
	return tot;
}

int func2(int* m, int n)
{
	int maxDiff = 0;
	for (int i = 1; i < n; ++i)
	{
		if(m[i-1]-m[i] > maxDiff) maxDiff = m[i-1]-m[i];
	}
	cout<<maxDiff<<endl;
	int res = 0;
	for (int i = 0; i < n-1; ++i)
	{
		res+=min(maxDiff,m[i]);
	}
	return res;
}

int main()
{
	ifstream input;
	input.open("a-large.in",ios::in);
	ofstream out;
	out.open("a.out",ios::out);

	int count;
	input>>count;

	for (int i = 1; i <= count; ++i)
	{
		int n;
		input>>n;
		int* m = new int[n];
		for (int i = 0; i < n; ++i)
		{
			input>>m[i];
		}




		//printing the output
		out<<"Case #"<<i<<": ";
		out<<func1(m,n)<<" "<<func2(m,n);
	
		if(i<count) out<<endl;
	}

	return 0;
}
