#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <string>
#include <queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define MAXN 1005
#define INF 1000000
#define S 0
#define T m+n+1
using namespace std;
int t,tc=0,r1,r2,a[5][5],b[5][5];
int main(){
	scanf("%d",&t);
	while (t--){
		printf("Case #%d: ",++tc);
		scanf("%d",&r1); r1--;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				scanf("%d",&a[i][j]);
		scanf("%d",&r2);r2--;
		for (int i = 0; i < 4; ++i)
			for (int j = 0; j < 4; ++j)
				scanf("%d",&b[i][j]);
		int ans  = 0;
		for (int i = 0; i < 4; ++i){
			for (int j =0; j < 4; ++j){
			//	cout << r1 << " "<< i << " ~ " << r2 <<" " << j << endl;
			//	cout << a[r1][i] << " "<< b[r2][j] << endl;
				if (a[r1][i] == b[r2][j]){
					if (ans == 0)
						ans = a[r1][i];
					else ans = -1;
				}
			}
		}
		if (ans >0){
		 	cout << ans << endl;
		 	continue;
		}
		if (ans == 0)
			puts("Volunteer cheated!");
		else
			puts("Bad magician!");
	}
}