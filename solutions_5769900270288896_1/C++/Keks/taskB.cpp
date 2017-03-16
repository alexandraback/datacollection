#include <iostream> 
#include <fstream> 
#include <cmath> 
#include <algorithm> 
#include <cassert> 
#include <string> 
#include <cstdlib> 
#include <cstdio> 
#include <vector> 
#include <map> 
#include <set> 
#include <stack> 
#include <iomanip> 
#include <queue> 

#define pb push_back 
#define mp make_pair 
#define ll long long 
#define abracadabra next 
#define pii pair<int, int> 

using namespace std; 
int nulls, twos, threes;
int ans;
int a, b, n;

int update()
{
	int t = n - nulls;
	if (t <= 0)
		ans = 0;
	else {
	if (twos >= t) {
		ans = min(ans, (t) * 2);
	} else {
		if (twos + threes >= t) {
			ans = min(ans, twos * 2 + (t - twos) * 3);
		} else {
			t -= twos + threes;
			ans = min(ans, twos * 2 + threes  * 3 + t*4);
		}
	}
	}
}

int main(){ 
	ios_base::sync_with_stdio(false); 
	int T;
	cin >> T;
	for(int test = 1; test <= T; test++)
	{
		cin >> a>> b >> n;
		if (a > b)
			swap(a, b);
			
		ans = a * (b - 1) + b * (a - 1);
		if (a == 1)
		{
			if (b & 1)
			{
				ans = min(ans, max(0, n - (b + 1) / 2) * 2);
			} else {
				if (n - b / 2 > 0)
					ans = min(ans, (n - b / 2 - 1) * 2 + 1);
				else
					ans = 0;
			}
		} else {
		
			if (a % 2 == 0 || b % 2 == 0)
			{
				nulls = a*b/2;
				twos = 2;
				threes = a + b - 4;
				update();
			} else {
				nulls = a * b / 2 + 1;
				twos = 0;
				threes = a + b - 2;
				update();
				nulls = a * b / 2;
				twos = 4;
				threes = a + b - 6;
				update();
			}
		
		}
	
	
		cout << "Case #" << test << ": " << ans << endl;
	}
	
	
	return 0; 
} 
