#include <cstdlib>
#include <vector>
#include <cstdio>
#include <iostream>
#include <array>

using namespace std;

int main(int argc, char** argv) {
	int T;
	cin >> T;
	for (int n=0;n<T;n++) {
		int N;
		cin >> N;
		vector<int> m(N,0);
		for (int i=0;i<N;i++) {
			cin >> m[i];
		}
		int a=0;
		for (int i=1;i<N;i++) {
			if (m[i]-m[i-1] < 0) {
				a+=m[i-1]-m[i];
			}
		}
		int max=0;
		for (int i=1;i<N;i++) {
			if (m[i-1]-m[i] > max) {
				max = m[i-1]-m[i];
			}
				//cerr << max << endl;
		}
		int b=0;
		for (int i=0;i<N-1;i++) {
			b += ((max<m[i])?max:m[i]);
				//cerr << max << " " << m[i] << " " << b << endl;
		}
		printf("Case #%d: %d %d\n",n+1,a,b);
	}

	return 0;
}

