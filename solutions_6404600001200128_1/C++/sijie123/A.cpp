#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("A-large.in","r", stdin);
	freopen("myfile.txt","w", stdout);
	int T;
	cin >> T;
	for (int x = 1; x <= T; x++)	{
		int N, arr[10005];
		cin >> N;
		for (int i = 0; i < N; i++ ) {
			int temp = 0;
			scanf("%d", &temp);
			arr[i] = temp;
		}
		int a = 0;
		for (int i = 1; i < N; i++) {
			a += max(0,arr[i-1] - arr[i]);
		}
		int b = 0, minrate = 0;
		for (int i = 1; i < N; i++) {
			//Determine min rate
			minrate = max(minrate, arr[i-1] - arr[i]);
		}
		for (int i = 0; i < N-1; i++) {
			b += min(minrate, arr[i]);
		}
		
		
		
		
		printf("Case #%d: %d %d\n", x,a,b);
	}
}
