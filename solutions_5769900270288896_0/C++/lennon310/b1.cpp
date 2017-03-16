#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int dp[1 << 18];
int a, b, n;

int main() 
{
//	 freopen("input1.txt","r",stdin);
   freopen("B-small-attempt1.in","r",stdin);
   //freopen("A-large.in","r",stdin);
    freopen("output1.txt","w",stdout);
	int t;
	cin >> t;
	for (int ti = 1; ti <= t; ti++) {
		cout << "Case #" << ti << ": ";
		cin >> a >> b >> n;
		int best = n*4;
		for (int i = 1; i < (1 << (a * b)); i++){		
			dp[i] = dp[i -(i & -i)] + 1;
			int tmp = 0;
			for (int r = 0; r < a; r++){	
				for (int c = 0; c < b; c++){		
					tmp += (c > 0 && (i & (1 << (r * b + c))) && (i & (1 << (r * b+ c - 1))));						
					tmp += (r > 0 && (i & (1 << (r * b + c))) && (i & (1 << (r * b + c - b))));					
				}
			}
			if (dp[i] == n) best = min(best, tmp);
		}
		cout << best << "\n";
	}
}