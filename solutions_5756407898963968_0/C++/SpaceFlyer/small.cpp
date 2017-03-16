#include <iostream>
#include <cstring>
using namespace std;

int arrange1[4][4];
int arrange2[4][4];
int r1, r2;

void readArrange(int arrange[4][4]){
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			cin >> arrange[i][j];
}

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		cin >> r1;
		r1--;
		readArrange(arrange1);
		cin >> r2;
		r2--;
		readArrange(arrange2);
		int cnt[17];
		memset(cnt, 0, sizeof(cnt));
		for(int i=0; i<4; i++){
			cnt[arrange1[r1][i]]++;
			cnt[arrange2[r2][i]]++;
		}
		int ans = -1;
		for(int i=1; i<=16; i++)
			if (cnt[i] == 2){
				if (ans == -1)
					ans = i;
				else{
					ans = -2;
					break;
				}
			}
		cout << "Case #" << t+1 << ": ";
		if (ans == -1)
			cout << "Volunteer cheated!" << endl;
		else if (ans == -2)
			cout << "Bad magician!" << endl;
		else
			cout << ans << endl;
	}
}

