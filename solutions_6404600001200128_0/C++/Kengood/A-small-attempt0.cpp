#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <complex>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <ctime>

#include<unordered_map>
#include<unordered_set>
using namespace std;



int a(int n, vector<int> in)
{
	int cur = in[0];
	int ans = 0;

	for (int i = 1; i < n; ++i)
	{
		if (cur > in[i])		
			ans += cur - in[i];			
		cur = in[i];
	}
	return ans;
}

int b(int n, vector<int> in)
{
	int maxa = 0;
	

	for (int i = 1; i < n; ++i)
	{
		maxa = max(maxa , in[i-1]-in[i]);
		
	}

	int ans = 0;
	for (int i = 0; i < n-1; ++i)
	{
		int needToEat = min(maxa,in[i]);
		
		ans += needToEat;
	}
	return ans ;
}

int main()
{	
	int Case, cases = 0;
	scanf("%d" , &Case);

	while (Case--)	
	{
		int n;
		cin >> n;
		vector<int> in(n);
		
		for (int i = 0 ; i < n; ++i)
			cin >> in[i];
		


		printf("Case #%d: %d %d\n" , ++cases, a(n,in), b(n,in));
		
	}

	return 0;
}

