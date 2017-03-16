#include <iostream>

using namespace std;

void inss();

int n;
int pnum[27];
int wnum[27];

int main()
{
	int T;
	cin >> T;
	for (int z = 1; z <= T; z++) {
		cin >> n;
		int everysum = 0;

		for (int i = 1; i <= n; i++) {
			wnum[i] = i;
		}

		for (int i = 1; i <= n; i++) {
			cin >> pnum[i];
			everysum += pnum[i];
		}

		cout << "Case #" << z << ": ";

		while (everysum > 3) {
			inss();
			int l = pnum[1];
			printf("%c",wnum[1]+0x40);
			pnum[1]--;
			everysum--;
			for (int i = 2; i <= n; i++){
				if (l == pnum[i]) {
					pnum[i]--;
					everysum--;
					printf("%c", wnum[i] + 0x40);
					break;
				}
				else {
					break;
				}
			}
			printf(" ");
		}

		inss();

		if (everysum == 3) {
			printf("%c ", wnum[1] + 0x40);
			printf("%c%c", wnum[2] + 0x40, wnum[3] + 0x40);
		}
		else {
			printf("%c%c", wnum[1] + 0x40, wnum[2] + 0x40);
		}

		cout << endl;
	}
	return 0;
}

void inss(){
	for (int i = 2; i <= n; i++) {
		int key = pnum[i];
		int keyp = wnum[i];
		int j = i - 1;
		while (j > 0 && pnum[j] < key) {
			pnum[j + 1] = pnum[j];
			wnum[j + 1] = wnum[j];
			j = j - 1;
		}
		pnum[j + 1] = key;
		wnum[j + 1] = keyp;
	}
}