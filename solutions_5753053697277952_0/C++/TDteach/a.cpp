#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <string>
#include <memory.h>
using namespace std;

#include <cctype>
#include <cstdio>
#include <cstdarg>
#include <ctime>
#include <cmath>
#include <cassert>


const int INF = (1 << 30) - 1;
const float PI = (float)acos(-1.0);
const float EPS = 1e-5;
const float BASE2 = 1.0/log(2);

int cases;
int a[30];
int b[30];
int n;


bool cmp(int p, int q)
{
	return (a[p] > a[q]);
}

void deal()
{
	int i;

	while (true) {
		for (i = 1; i < n; i++) {
			if (a[b[0]] > a[b[i]]) break;
		}
		if (i&1) {
			cout << char('A'+b[i-1]) << " ";
			a[b[i-1]]--;
			--i;
		}
		for (int j = i-1; j >= 0; j -= 2) {
			cout << char('A'+b[j]) << char('A'+b[j-1]) << " ";
			a[b[j]]--;
			a[b[j-1]]--;
		}
		if (a[b[0]] == 0) break;
	}
}

int main ()
{
	scanf("%d", &cases);
	for (int k = 1; k <= cases; k++) {
		printf("Case #%d: ", k);

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = i;
		}

		sort(b,b+n, cmp);

		deal();
		cout << endl;

	}
	return 0;
}


