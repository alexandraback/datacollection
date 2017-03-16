#include <iostream>
#include <vector>

using namespace std;

void print(int x) {
	cout << char('A' + x);
}

int main()
{
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	for (int x = 0; x < t; x++) {
		int n;
		cin >> n;
		vector<int> p(n);
		for (int i = 0; i < n; i++) cin >> p[i];
		cout << "Case #" << x + 1 << ": ";
		while (true)
		{
			int max1 = 0;
			int max2 = 0;
			int indmax1 = 0;
			int indmax2 = 0;
			for (int i = 0; i < n; i++) {
				if (p[i] >= max1) {
					max2 = max1;
					indmax2 = indmax1;
					max1 = p[i];
					indmax1 = i;
				}
				else if (p[i] >= max2) {
					max2 = p[i];
					indmax2 = i;
				}
			}
			if (max1 == 1 && max2 == 1) break;
			if (max1 > max2) {
				print(indmax1);
				cout << " ";
				p[indmax1]--;
			}
			else if (max1 == max2) {
				print(indmax1);
				print(indmax2);
				cout << " ";
				p[indmax1]--;
				p[indmax2]--;
			}
		}
		int cnt_1 = 0;
		vector<int> inds_1;
		for (int i = 0; i < n; i++) {
			if (p[i] == 1) {
				cnt_1++;
				inds_1.push_back(i);
			}
		}
		if (cnt_1 % 2 == 0) {
			for (int i = 0; i < cnt_1; i += 2) {
				print(inds_1[i]);
				print(inds_1[i + 1]);
				cout << " ";
			}
		}
		else {
			print(inds_1[0]);
			cout << " ";
			for (int i = 1; i < cnt_1; i += 2) {
				print(inds_1[i]);
				print(inds_1[i + 1]);
				cout << " ";
			}
		}
		cout << endl;
	}
    return 0;
}

