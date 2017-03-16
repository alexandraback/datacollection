#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, b, m[100262], sumCeil[100262], sum[100262];

bool check(int x)	{
  int sum = 0;
  for(int i=0; i<b; i++)	{
    sum += (m[i] + x) / m[i];
  }
  if(sum >= n)	{
    return 1;
  } else	{
    return 0;
  }
}

void pain()	{
	cin >> b >> n;
	for(int i=0; i<b; i++)	{
		cin >> m[i];
	}
	int tlo = 0, thi = 1e16;
	while(thi - tlo > 1)	{
		int mid = (thi + tlo) / 2;
		if(not check(mid))	{
			tlo = mid + 1;
		}	else	{
			thi = mid;
		}
	}
	if(check(tlo) == 1)	{
		thi = tlo;
	}
	int counts = 0, rem;
	for(int i=0; i<b; i++)	{
		counts += (thi - 1 + m[i]) / m[i];
	}
	rem = n - counts;
	for(int i=0; i<b; i++)	{
		if(thi % m[i] == 0)	{
			rem--;
		}
		if(rem == 0)	{
			cout << i + 1 << "\n";
			return;
		}
	}
}

#undef int
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input = "bin.txt";
	string output = "bout.txt";
	freopen(input.c_str(), "r", stdin);
	freopen(output.c_str(), "w", stdout);
	int tt; cin >> tt;
	for(int iii=1; iii<=tt; iii++)	{
		cout << "Case #" << iii << ": ";
		pain();
	}
}

