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

char a[150][200];
char b[150][200];
int c[150][200];
int d[150];

int main()
{
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++){
		int n;
		cin >> n;
		bool r = true;
		int result = 0;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for(int i = 0; i < n; i++){
			int length = strlen(a[i]);
			b[i][0] = a[i][0];
			int j = 1;
			int temp = 1;
			int summ = 0;
			while (j < length){
				if (a[i][j] == b[i][summ]){
					temp++;
					j++;
				}
				else{
					c[i][summ] = temp;
					temp = 1;
					summ++;
					b[i][summ] = a[i][j];
					j++;
				}
			}
			c[i][summ] = temp;
			summ++;
			d[i] = summ;
		}
		for(int i = 1; i < n; i++){
			if (d[i] != d[0]){
				r = false;
				break;
			}
		}
		if (r){
			int e[150];
			for(int i = 0; i < d[0]; i++){
				for(int j = 0; j < n; j++){
					if (b[j][i] != b[0][i]){
						r = false;
						break;
					}
					e[j] = c[j][i];
				}
				if (r == false){
					break;
				}
				sort(e, e+n);
				int mid = e[n / 2];
				for(int j = 0; j < n; j++){
					result = result + abs(mid - e[j]);
				}
			}
		}
		cout << "Case #" << tt << ": ";
		if (r){
			cout << result;
		}
		else{
			cout << "Fegla Won";
		}
		cout << endl;
	}
	return 0;
}