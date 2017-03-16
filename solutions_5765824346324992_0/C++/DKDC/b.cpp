#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	int T, n = 0;
	long N;
	int B;

	cin >> T;
	while (n < T) {
		cout << "Case #" << ++n << ": ";
		cin >> B >> N;
		int M[B];
		long rM[B];
		vector <int> BSeq;
		for (long i = 0; i < B; i++) {
			cin >> M[i];
			rM[i] = 0;
		}
		bool allSame = false;
		while (!allSame) {
			long minB = rM[0];
			int minBIdx = 0;
			for (int j = 1; j < B; j++) {
				if (minB > rM[j]) {
					minB = rM[j];
					minBIdx = j;
				}
			}
			rM[minBIdx] += M[minBIdx];
			BSeq.push_back(minBIdx);
			allSame = true;
			for (int i = 1; i < B; i++) {
				if (rM[i] != rM[0]) {
					allSame = false;
					break;
				}
			}
		}
		if (N % BSeq.size()) {
			cout << BSeq[N % BSeq.size() - 1] + 1 << endl;
		} else {
			cout << BSeq[BSeq.size() - 1] + 1 << endl;
		}
	}
	return 0;
}
