#include <iostream>
#include <vector>
using namespace std;


int main() {
	//cout.precision(10);

	int N;
	int r[2];
	int d[2][4][4];

	vector<pair<int,int> > mID;

	cin >> N;

	int n;
	for (n=1; n<=N; n++) {

		for (int k=0; k<2; k++) {
			cin >> r[k];
			r[k]--;
			for (int i=0; i<4; i++) {
				for (int j=0; j<4; j++) {
					cin >> d[k][i][j];
				}
			}
		}

		int id=0, count=0;
		for (int i=0; i<4; i++) {
			for (int j=0; j<4; j++) {
				if (d[0][r[0]][i] == d[1][r[1]][j]) {
					count++;
					id = d[0][r[0]][i];
				}
			}
		}
		mID.push_back(make_pair(count, id));
	}

	vector<pair<int, int> >::iterator iter;
	n=1;
	for(iter=mID.begin(); iter!=mID.end(); iter++)
	{
		cout << "Case #" << n++ << ": ";

		int c = (*iter).first;

		if (c==0) cout << "Volunteer cheated!";
		else if (c>1) cout << "Bad magician!";
		else cout << (*iter).second;

		cout << endl;
	}

	return 0;
}

