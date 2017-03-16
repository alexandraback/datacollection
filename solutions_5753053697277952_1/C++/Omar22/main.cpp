#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("C:\\Users\\Omar Mohamed\\ClionProjects\\Go\\output.txt", "w", stdout);
	freopen("C:\\Users\\Omar Mohamed\\Downloads\\A-large.in", "r", stdin);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int N, A[26];
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> A[i];

		vector<string> result;

		while (true) {
			int maximum1 = 0, maximum2 = 0, index1 = -1, index2 = -1;
			for (int i = 0; i < N; i++) {
				if (A[i] >= maximum1) {
					maximum2 = maximum1;
					index2 = index1;
					maximum1 = A[i];
					index1 = i;
				}
				else if (A[i] > maximum2) {
					maximum2 = A[i];
					index2 = i;
				}
			}
			if (maximum1 == 0)
				break;
			string go;

			if (maximum1 == maximum2) {
				for (int i = 0; i < N; i++) {
					if (i != index1 && i != index2 && A[i]) {
						go += 'A' + i;
						A[i]--;
						break;
					}
				}
			} else {
				go += 'A' + index1;
				A[index1] -= 1;
			}

			if (go.size() == 0){
				go += 'A' + index1;
				go += 'A' + index2;
				A[index1]--;
				A[index2]--;
			}

			result.push_back(go);
		}

		cout << "Case #" << t << ": ";
		for (string X : result)
			cout << X << " ";
		cout << endl;
	}

	return 0;
}




