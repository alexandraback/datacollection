#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <set>
#include <limits.h>

#define inp(x) scanf("%d",&x)
#define inp_l(x) scanf("%lld",&x)
#define inp_d(x) scanf("%lf",&x)
#define MOD 1000000007

using namespace std;

typedef long long int ll;
typedef vector <int> VI;
typedef vector <long long int> VLL;
typedef pair<int,int> PI;
typedef pair<ll,ll> PLL;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T, z, i,n,mx, x;
	float per;
	string str;
	cin >> T;
	for(int z = 1; z <= T; z++)
	{
		cin >> n;
		VI arr;
		int t = 0;
		for(i = 0; i < n; i++)
		{
			cin >> x;
			arr.push_back(x);
			t += x;
		}
		str = "";
		//cout << t << endl;
		while(true)
		{
			mx = 0;
			for(i = 0; i < n; i++)
			{
				if(arr[i] > arr[mx])
					mx = i;
			}
			if(arr[mx] == 0)
				break;
			str = str + (char)(mx + 'A');
			arr[mx]--;
			t--;
			for(i = 0; i < n; i++)
			{
				per = arr[i] / (float)t;
				per = per * 100;
				//cout << per << " " << t << endl;
				if(per > 50)
				{
					str = str + (char)(i + 'A');
					t--;
					arr[i]--;
					break;
				}
			}
			str = str + " ";
			if(t == 0)
				break;
		}
		cout << "Case #" << z << ": " << str << endl;
	}
	return 0;
}

