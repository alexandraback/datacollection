#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;

#define min(a,b) (((a)<(b)))?(a):(b)

int read() {
	int tmp;
	scanf("%d", &tmp);
	return tmp;
}

int n;
int p[50];
int sum;

void reset() {
	n = 0;
	for (int i = 0; i < 50; i++) {
		p[i] = 0;
	}
	sum = 0;
}

void readInput() {
	n = read();
	for (int i = 0; i < n; i++) {
		p[i] = read();
	}
}

void print(int c) {
	printf("%c", 'A' + c);
}

int maxx() {
	int m = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] > p[m]) m = i;
	}
	return m;
}

bool validate() {
	int s = 0;
	for (int i = 0; i < n; i++) s += p[i];

	int half = s / 2 + 1;
	for (int i = 0; i < n; i++) {
		if (p[i] >= half) return false;
	}
	return true;
}

int solve() {
	for (int i = 0; i < n; i++) sum += p[i];

	int t = sum;

	while (t > 0) {
		if (t != sum) printf(" ");

		int m = maxx();
		print(m);
		p[m]--;
		t--;

		if (!validate())
		{
			m = maxx();
			print(m);
			p[m]--;
			t--;
		}

		while (!validate());
	}

	return 0;
}

void printTestCaseHeader(int testIndex) {
	cout << "Case #" << testIndex << ": ";
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int __T;
	scanf("%d", &__T);

	for (int i = 1; i <= __T; i++)
	{
		reset();
		readInput();
		printTestCaseHeader(i);
		solve();
		cout << endl;
	}

	return 0;
}
