#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1005;
int m, n;
long long a[MAXN];
#define cin fin
#define cout fout
ifstream fin("a.in");
ofstream fout("a.out");

bool chk(long long t)
{
	long long tmp = 0;
	for(int i = 1; i <= m; i++)
	{
		tmp += (t + (a[i] - 1)) / a[i];
	}
	return tmp >= n;
}

int main()
{
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++)
	{
		cin >> m >> n;
		for(int i = 1; i <= m; i++) cin >> a[i];
		long long l = 0, r = (n - 1) * 100000ll;
		while(l < r)
		{
			long long mid = (l + r) / 2;
			if(chk(mid)) r = mid;
			else l = mid + 1;
		}
	//	cout << chk(l) << ' ' << chk(l - 1) << endl;
		for(int i = 1; i <= m; i++)
		{
			n -= (l - 2 + a[i]) / a[i];
		}
		int ans = 0;
	//	cout<<"::::"<<l<<' '<<n<<endl;
		for(int i = 1; i <= m; i++)
		{
			if((l - 1) % a[i] == 0)
				n--;
			if(n == 0)
			{
				ans = i;
				break;
			}
		}
		
		cout << "Case #" << test << ": " << ans << endl;
	}
	
	return 0;
}
/*
10
5 915742169
18 7 21 11 25
*/

