#include <iostream>
using namespace std;

int main() {

	int N;
	cin >> N;


	for(int i=0;i<N;i++) {
		int loop;
		cin >> loop;
		int m[loop];
		int r1 = 0;
		int maxEat = 0;
		int prev;
		cin >> prev;
		m[0] = prev;
		for (int j=1;j<loop;j++) {
			int current;
			cin >> current;
			m[j] = current;
			if (current<prev) {
				int eat = prev - current;
				maxEat = max(maxEat,eat);
				r1 += eat;
			}
			prev = current;
		}
		int r2 = 0;
		for (int j=0;j<loop-1;j++) {
			int currentEat = 0;
			r2+=min(maxEat,m[j]);
		}
		cout << "Case #" << i+1 << ": " << r1 << " " << r2 << endl;
	}

	return 0;
}