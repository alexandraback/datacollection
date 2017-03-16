#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <limits>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,int> pci;
const int INF = numeric_limits<int>::max();

const int nmax = 105;
string a[nmax];
vector<char> b[nmax];
vector<int> c[nmax];
int n;

int go()
{
	for(int i=1;i<n;i++)
	{
		if(b[i].size() != b[0].size())
			return -1;
		for(int j=0;j<b[i].size();j++)
			if(b[i][j] != b[0][j])
				return -1;
	}
	int moves = 0;
	for(int j=0;j<b[0].size();j++)
	{
		vector<int> counts;
		for(int i=0;i<n;i++)
			counts.push_back(c[i][j]);
		sort(counts.begin(), counts.end());
		int m = counts[n/2];
		for(int i=0;i<n;i++)
			moves += abs(counts[i] - m);
	}
	return moves;
}

int main(int argc,char* argv[])
{
	int num_test_cases;
	scanf("%d",&num_test_cases);
	for(int test_case=1; test_case<=num_test_cases; test_case++)
	{
		for(int i=0;i<nmax;i++)
		{
			b[i].clear();
			c[i].clear();
		}
		
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> a[i];
		for(int i=0;i<n;i++)
		{
			char ch = 0;
			for(int j=0;j<a[i].size();j++)
				if(a[i][j] != ch)
				{
					ch = a[i][j];
					b[i].push_back(ch);
					c[i].push_back(1);
				}
				else
					c[i].back()++;
		}
		/*
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<b[i].size();j++)
				printf("(%c %d) ", b[i][j], c[i][j]);
			printf("\n");
		}
		*/

		printf("Case #%d: ", test_case);
		int moves = go();
		if(moves == -1)
			printf("Fegla Won\n");
		else
			printf("%d\n", moves);
	}
	return 0;
}
