#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main(){
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	int n = 0; 
	int t;
	cin >> t;
	while (n++ < t){
		int N;
		int m[10000];
		cin >> N;
		for (int i =0; i < N; i++)
			cin >> m[i];
		//first
		int sum1 = 0;
		for (int i = 1; i < N; i++){
			if (m[i] < m[i-1]){
				sum1 += (m[i-1] - m[i]);
			}
		}
		//second
		int speed = -1;
		for (int i = 1; i < N; i++){
			if (m[i-1] - m[i] > speed) 
				speed = m[i-1] - m[i];
		}
		int sum2 = 0;
		for (int i = 0; i < N-1; i++){
			if (m[i] < speed)
				sum2 += m[i];
			else 
				sum2 += speed;
		}
		cout << "Case #" << n << ": "<< sum1 << " " << sum2 << endl;
	}
	return 0;
}