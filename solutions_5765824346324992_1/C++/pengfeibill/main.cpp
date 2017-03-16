#include <iostream>
#include <fstream>

using namespace std;

long long t, b, n;
long long m[1000];

ifstream fin("B-large.in");
ofstream fout("test.out");

int main() {
	fin >> t;
	for (long long case_num = 1; case_num <= t; case_num++) {
		fin >> b >> n;
		for (long long i = 0; i < b; i++) fin >> m[i];
		long long p = 0, q = 100000000000000;
		while (p != q) {
			long long mid = (p + q) / 2;
			long long sum = 0;
			for (long long i = 0; i < b; i++)
				sum += mid / m[i] + 1;
			if (sum < n)
				p = mid + 1;
			else
				q = mid;
		}
		long long sum = 0;
		for (long long i = 0; i < b; i++)
			sum += p / m[i] + 1;
		long long target = sum - n;
		long long cnt = 0;
		long long res;
		for (long long i = b - 1; i >= 0; i--)
			if (p % m[i] == 0) {
				if (target == cnt) {
					res = i;
					break;
				}
				cnt++;
			}
		fout << "Case #" << case_num << ": " << res + 1 << endl;
	}
	return 0;
}