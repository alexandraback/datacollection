#include<cstdlib>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N_MAX = 1010;

int arr[N_MAX];

int main(){
	freopen("A-large.in", "r", stdin);
	freopen("pA_large.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for(int cnt = 1; cnt <= t; cnt ++){
		int n;
		scanf("%d", &n);
		int A = 0, B = 0;
		int gap = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
			if(!i)
				continue;
			if(arr[i] < arr[i - 1]){
				A += (arr[i - 1] - arr[i]);
				gap = max(gap, arr[i - 1] - arr[i]);
			}
		}
		B = 0;
		for(int i = 1; i < n; i++){
			if(arr[i - 1] < gap)
				B += arr[i - 1];
			else
				B += gap;
		}
		printf("Case #%d: %d %d\n", cnt, A, B);
	}
	return 0;
}
