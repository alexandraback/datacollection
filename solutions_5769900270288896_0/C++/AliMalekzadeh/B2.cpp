#include<iostream>
using namespace std;

int tt, r, c, n, JJ;
int a[100][100];

void bt(int x, int y){
	if (x==r){
		int J = 0;
		int T = 0;
		for (int i=0 ; i<r ; i++)
			for (int j=0 ; j<c ; j++)
				if (a[i][j]){
					T++;
					if (i>0  ) if (a[i-1][j]) J++;
					if (i<r-1) if (a[i+1][j]) J++;
					if (j>0  ) if (a[i][j-1]) J++;
					if (j<c-1) if (a[i][j+1]) J++;
				}
		if (JJ > J/2 && T==n) JJ = J/2;		
		return;
	}
	if (y==c){
		bt(x+1, 0);
		return;
	}
	a[x][y] = 0;
	bt(x, y+1);
	a[x][y] = 1;
	bt(x, y+1);
}

int main(){
	ios::sync_with_stdio(0);
	cin >> tt;
	for (int ti=0 ; ti<tt ; ti++){
		cin >> r >> c >> n;
		JJ = 4 * n;
		bt(0, 0);
		cout << "Case #" << ti+1 << ": " << JJ << endl;
	}
}
