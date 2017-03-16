#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int cutDown[3000];
int x[3000], y[3000];
int n;
int result[3000][3000];
void calc(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int zero = 0;
			int temp = 0;
			int x1 = x[j] - x[i];
			int y1 = y[j] - y[i];
			for(int k = 0; k < n; k++){
				int x2 = x[k] - x[i];
				int y2 = y[k] - y[i];
				if (x1 * y2 - x2 * y1 < 0)
					temp++;
				else if (x1 * y2 - x2 * y1 == 0)
					zero++;
			}
			if (temp > n - zero - temp)
				result[i][j] = n - zero - temp;
			else
				result[i][j] = temp;
		}
	}
	return ;
}

int main()
{
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		cin >> n;
		for(int i = 0; i < n;i++){
			cin >> x[i] >> y[i];
		}
		if (n <= 3){
			cout << "Case #" << tt << ":" << endl;
			for(int i = 0; i < n; i++)
				cout << 0 << endl;
			continue;
		}
		calc();
		for(int i = 0; i < n; i++){
			cutDown[i] = n;
			for(int j = 0; j < n; j++){
				if (i == j)
					continue;
				if (result[i][j] < cutDown[i]){
					cutDown[i] = result[i][j];
				}
			}
		}
		cout << "Case #" << tt << ":" << endl;
		for(int i = 0; i < n; i++){
			cout << cutDown[i] << endl;
		}
	}
	return 0;
}