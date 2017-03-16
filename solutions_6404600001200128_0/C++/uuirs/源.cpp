#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<fstream>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef long long LL;
LL m[1005];
int main()
{
	int i, j, k,Cas=1,T;
	LL ans1, ans2,N,v;
	ifstream cin("A-small-attempt0.in");
	ofstream cout("000.out"); 
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (i = 0; i < N; i++)
			cin >> m[i];

		ans1 = ans2 = v = 0;

		for (i = 1; i < N; i++)
			if (m[i] < m[i - 1])ans1 += m[i-1] - m[i];
		for (i = 1; i < N; i++)
			v = max(v, m[i - 1]-m[i]);
		for (i = 1; i < N; i++)
		{
			if (m[i - 1] < v)ans2 += m[i - 1];
			else ans2 += v;
		}
		cout << "Case #" << Cas++ << ": " << ans1 << " " << ans2 << endl;
	}
}