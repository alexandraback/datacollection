#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
#include <bitset>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

#define e '\n'
#define INF 1023456789
#define ll long long

//#define FILE "myFile"

#ifdef FILE
ifstream f(string (string(FILE) + ".in").c_str());
ofstream g(string (string(FILE) + ".out").c_str());
#endif
#ifndef FILE
#define f cin
#define g cout
#endif

ll mul_inv(ll a, ll b)
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

string s;
long long t, n, rez, x;
int i, j, ii;
string s1, s2;
vector<pair<string, string> > datain;
map<string, int> f1, f2;

int main() {
	f >> t;

	for (int ii = 1; ii <= t; ii++) {
		f >> n;
		char currChar = 'A';
		int total = 0;
		priority_queue<pair<int, char> > pq;
		for (i = 1; i <= n; i++, currChar++) {
			f >> x;
			total += x;
			pq.push(make_pair(x, currChar));
		}

		g << "Case #" << ii << ":";

		pair<int, char> p1, p2;

		while (!pq.empty()) {

			p1 = pq.top();
			pq.pop();

			if (total == 3) {
				g << " " << p1.second;
				total--;
				if (p1.first > 1) {
					pq.push(make_pair(p1.first - 1, p1.second));
				}
				continue;
			}

			if (pq.empty()) {

				if (p1.first == 1) {
					g << " " << p1.second;
					total--;
					break;
				} else if (p1.first == 2) {
					g << " " << p1.second << p1.second;
					total-=2;
					break;
				} else {
					g << " " << p1.second << p1.second;
					pq.push(make_pair(p1.first - 2, p1.second));
					total-=2;
					continue;
				}

			}

			p2 = pq.top();
			pq.pop();
			g << " " << p1.second << p2.second;
			total -= 2;

			if (p1.first > 1) {
				pq.push(make_pair(p1.first - 1, p1.second));
			}

			if (p2.first > 1) {
				pq.push(make_pair(p2.first - 1, p2.second));
			}
		}

		g << e;
	}

}

