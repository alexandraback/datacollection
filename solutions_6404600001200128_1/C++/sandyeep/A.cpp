#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1262;
int a[N], n;

void pain()	{
	cin >> n;
	for(int i=0; i<n; i++)	{
		cin >> a[i];
	}
	int firstMethod = 0, secondMethod = 0;
	for(int i=1; i<n; i++)	{
		if(a[i] < a[i - 1])	{
			firstMethod += a[i - 1] - a[i];
		}
	}
	for(int speed10 = 0; speed10 < 20620; speed10++)	{
		bool ok = true;
		for(int i=0; i<n-1; i++)	{
			int eaten = speed10;
			if(a[i] - eaten > a[i + 1])	{
				ok = false;
				break;
			}
		}
		if(ok)	{
			for(int i=0; i<n-1; i++)	{
				secondMethod += min(a[i], speed10);
			}
			cout << firstMethod << " " << secondMethod << "\n";
			return;
		}
	}
}

#undef int
int main()	{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string input = "ain.txt";
	string output = "aout.txt";
	freopen(input.c_str(), "r", stdin);
	freopen(output.c_str(), "w", stdout);
	int tt; cin >> tt;
	for(int iii=1; iii<=tt; iii++)	{
		cout << "Case #" << iii << ": ";
		pain();
	}
}

