#include <iostream>
#include <algorithm>
using namespace std;

#define loop(i, n) for (int i = 0; i < n; i++)

const int MAX = 1000;
int data[MAX];

int main() {
	int ts;
	cin >> ts;
	loop(ti, ts) {
		int n;
		cin >> n;
		loop(i, n) cin >> data[i];
		int solnA = 0;
		loop(i, n - 1) {
			solnA += max(0, data[i] - data[i+1]);
		}
		int rate = 0;
		loop(i, n - 1) {
			rate = max(rate, data[i] - data[i+1]);
		}
		int solnB = 0;
		loop(i, n - 1) {
			solnB += min(rate, data[i]);
		}
		cout << "Case #" << (ti+1) << ": " << solnA << " " << solnB << "\n";
	}
}
