#pragma comment(linker, "/STACK:134217728")
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <numeric>
#include <complex>
#include <functional>
#include <cmath>
#include <time.h>

using namespace std;

typedef long long LL;

int a[33];
int n;
bool check() {
	for (int i = 0; i < n; i++) {
		if (a[i] != 0) {
			int cnt = a[i];
			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;
				cnt -= a[j];
			}
			if (cnt > 0)
				return false;
		}
	}

	return true;
}
int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out", "w", stdout);
	int t;
	scanf("%d",&t);
	int number = 1;
	while (t--> 0) {	
		cin >> n;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		printf("Case #%d: ", number++);
		while (sum != 0) {

			for (int i = 0; i < n; i++) {
				a[i]--;
				if (a[i] >= 0 && check()) {
					char a = 'A' + i;
					cout << a << ' ';
					sum -= 1;
					break;
				}
				else {
					a[i]++;
				}
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					a[i]--;
					a[j]--;
					if (a[i] >= 0 && a[j] >= 0 && check()) {
						sum -= 2;
						char a = 'A' + i;
						char b = 'A' + j;
						cout << a<< b << ' ';
						break;
					}
					else {
						a[i]++;
						a[j]++;
					}
				}
			}
		}
		cout << endl;
	}
	return 0;
}