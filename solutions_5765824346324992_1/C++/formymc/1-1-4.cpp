#include<stdio.h>
#include<iostream>

using namespace std;

const int MAX = 1010;

int main(){
	int t;
	int number;
	int b;
	int n;
	long long m[MAX];
	long long left;
	long long right;
	long long mid;
	long long max;
	long long sum;
	long long cur[MAX];
	long long pre[MAX];
	long long min;
	int pre_begin;
	int counter;
	int answer;

	freopen("B-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	number = 0;
	cin >> t;

	while (t--){
		number++;
		max = 0;
		cin >> b >> n;
		for (int i = 0; i < b; i++){
			cin >> m[i];
			if (max < m[i]){
				max = m[i];
			}
		}
		left = 0;
		right = max * n + 1;
		do{
			pre_begin = sum = 0;
			mid = (left + right) / 2;
			for (int i = 0; i < b; i++){
				cur[i] = mid / m[i];
				pre[i] = (mid - 1) / m[i];
				if (cur[i] * m[i] != mid){
					cur[i] += 1;
				}
				if (pre[i] * m[i] != mid - 1){
					pre[i] += 1;
				}
				sum += cur[i];
				if (cur[i] - pre[i] == 1){
					pre[i] = 1;
					pre_begin++;
				}
				else{
					pre[i] = 0;
				}
			}
			if (sum - pre_begin >= n){
				right = mid - 1;
			}
			else if (sum < n){
				left = mid + 1;
			}
			else{
				if (pre_begin == 0){
					min = 100000;
					for (int i = b - 1; i >= 0; i--){
						if ( (mid / m[i]) * m[i] == mid && min > m[i]){
							min = m[i];
							answer = i + 1;
						}
						else if (min > mid - (cur[i] - 1)* m[i]){
							min = mid - (cur[i] - 1)* m[i];
							answer = i + 1;
						}
					}
				}
				else{
					counter = 0;
					for (int i = 0; i < b; i++){
						if (pre[i] == 1){
							counter++;
							if (sum - pre_begin + counter == n){
								answer = i + 1;
							}
						}
					}
				}

				break;
			}
		} while (left <= right);

		printf("Case #%d: %d\n", number, answer);
	}


	return 0;

}



