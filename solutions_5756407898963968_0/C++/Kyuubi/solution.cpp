#include <iostream>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

#define MOD 1000000007
#define SWAP(a,b) {a=(a)^(b);b = (a)^(b);a= (a)^(b);}

using namespace std;
inline long long minOf(long long x, long long y){return (x<y?x:y);}
inline long long maxOf(long long x, long long y){return (x>y?x:y);}
inline long long mabs(long long x){return (x<0?-x:x);}

int main()
{
	ios_base::sync_with_stdio(false);
	int t,a[2];
	int grid[3][17][17];
	int cc[18],ac,ans;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		memset(cc, 0, sizeof(cc));
		ac=0;
		for(int k = 0;k<2;k++){
			cin >> a[k];
			for(int i = 0;i<4;i++)
				for(int j = 0;j <4;j++){
					cin >> grid[k][i][j];
					if(i == a[k]-1)
						cc[grid[k][i][j]]++;
				}
		}
		for(int i =1; i<=16;i++){
			//			cout << "In List :" << i << " " << cc[i] << endl;
			if(cc[i] >= 2){
				ac++;
				ans = i;
			}
		}
		if(ac < 1)
			cout << "Case #" << tt << ": " << "Volunteer cheated!" << endl;
		else if(ac > 1)
			cout << "Case #" << tt << ": " << "Bad magician!" << endl;
		else
			cout << "Case #" << tt << ": " << ans << endl;
		
	}
	return 0;
}