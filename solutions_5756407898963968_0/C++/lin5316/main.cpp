//#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int main(){
	int T;
	int a, b, x[17], y[17], tmp, ans;
	cin >> T;
	for (int t = 1; t <= T; t++){
		cin >> a;
		for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++){
			cin >> tmp;
			x[tmp] = i + 1;
		}
		cin >> b;
		for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++){
			cin >> tmp;
			y[tmp] = i + 1;
		}
		ans = 0;
		for (int k = 1; k <= 16; k++)
			if (x[k] == a && y[k] == b)
				if (ans > 0){
					ans = -1;
					break;
				}
				else
					ans = k;
		if (ans == -1)
			cout << "Case #" << t << ": Bad magician!" << endl;
		else if (ans == 0)
			cout << "Case #" << t << ": Volunteer cheated!" << endl;
		else
			cout << "Case #" << t << ": " << ans << endl;
	}
}