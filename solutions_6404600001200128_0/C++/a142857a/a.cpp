#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 10005;
int n;
int a[MAXN];
#define cin fin
#define cout fout
ifstream fin("a.in");
ofstream fout("a.out");

int main()
{
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++)
	{
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		int s1 = 0, s2 = 0;
		for(int i = 2; i <= n; i++)
		if(a[i] < a[i - 1]) s1 += a[i - 1] - a[i];
		int m2 = 0;
		for(int i = 2; i <= n; i++)
		if(a[i - 1] - a[i] > m2) m2 = a[i - 1] - a[i];
		
		for(int i = 2; i <= n; i++)
		s2 += min(m2, a[i - 1]);
		cout << "Case #" << test << ": " << s1 << ' ' << s2 << endl;
	}
	
	return 0;
}
/*
4
4
10 5 15 5
2
100 100
8
81 81 81 81 81 81 81 0
6
23 90 40 0 100 9
*/

