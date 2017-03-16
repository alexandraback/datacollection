#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define rep(i,m,n) for(int i=(m),_end=(n);i < _end;++i)
#define repe(i,m,n) for(int i=(m), _end =(n);i <= _end;++i)
typedef long long ll;
using namespace std;


int GCD(int a, int b)
{
	if (b == 0) return a; return GCD(b, a % b);
}
int LCM(int a, int b)
{
	return (b / GCD(a, b)) * a;
}

ll sol(ifstream& sr) {
	ll n, b;

	static ll B[1005];
	const ll v = 1023;
	sr >> b >> n;
	n;
	ll lcm = 1;
	for (int i = 0; i < b; i++)
	{
		sr >> B[i];
	}

	ll l = 0;
	ll h = (ll)100001 * (ll)1000 * (ll)1000 * (ll)1000;
	while (l < h)
	{
		ll mid = (l + h) / 2;
		ll t = 0;
		for (int i = 0; i < b; i++)
		{
			t += (mid) / B[i] + 1;
		}
		if (t >= n)
			h = mid;
		else
			l = mid + 1;
	}

	{
		ll t = 0;
		for (int i = 0; i < b; i++)
		{
			t += (l - 1) / B[i] + 1;
		}
		for (int i = 0; i < b; i++)
		{
			if (l%B[i] == 0)
			{
				t++;
				if (t == n)
					return i + 1;
			}
		}

	}




	cout << "ERRRRRORRRR";
	return 0;

	//std::priority_queue<ll, std::vector<int>, std::greater<int> > q;
	//for (int i = 0; i < b; i++)
	//{
	//	ll g = i;
	//	q.push(g);
	//	sr >> B[i];
	//	B[i] <<= 11;
	//}

	//for (int i = 1; i < n; i++)
	//{
	//	ll g = q.top();
	//	q.pop();
	//	g += B[(g&v)];
	//	q.push(g);
	//}
}

int main(){

	ifstream sr = ifstream("D:\\in.in");
	ofstream sw = ofstream("D:\\out.out");

	int T;
	sr >> T;
	for (int i = 0; i < T; i++)
	{
		sw << "Case #" << i + 1 << ": " << sol(sr) << endl;
		cout << i << endl;
	}
	sr.close();
	sw.close();
	cout << "FINISHED type a number and enter to exit";
	cin >> T;

	return 0;
}
