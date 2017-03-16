#include <cstdio>
#include <iostream>
#include <map>
using namespace std;

int main(){
	FILE * fin, * fout;
	freopen_s(&fin, "A-small-attempt0.in", "r", stdin);
	freopen_s(&fout, "magic.out", "w", stdout);
	int run, row, num; map<int, int> poss; map<int, int>::iterator it;
	cin >> run;
	for (int a = 1; a <= run; ++a){
		poss.clear();
		for (int z = 0; z < 2; ++z){
			cin >> row;
			for (int y = 1; y <= 4; ++y){
				for (int x = 0; x < 4; ++x){
					cin >> num;
					if (y == row) ++poss[num];
				}
			}
		}
		num = -1;
		for (it = poss.begin(); it != poss.end(); ++it)
			if (it->second == 2)
				num = (num == -1) ? it->first : -2;
		cout << "Case #" << a << ": ";
		if (num == -2) cout << "Bad magician!" << endl;
		else if (num == -1) cout << "Volunteer cheated!" << endl;
		else cout << num << endl;
	}
	return 0;
}
