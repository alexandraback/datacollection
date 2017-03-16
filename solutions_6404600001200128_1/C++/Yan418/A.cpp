#include <fstream>

using namespace std;

int m[2000];
int main(){
	ifstream inf("A-large.in");
	ofstream outf("A-large.out");
	int T, N;
	inf >> T;
	for (int i = 1; i <= T; i++){
		inf >> N;
		int ans1 = 0, ans2 = 0, speed = 0;
		for (int j = 0; j < N; j++)
			inf >> m[j];
		for (int j = 1; j < N; j++){
			int d = m[j - 1] - m[j];
			if (d > 0) {
				ans1 += d;
				if (speed < d){
					speed = (d);
				}
			}
		}
		for (int j = 1; j < N; j++){
			if (speed > m[j - 1])
				ans2 += m[j - 1];
			else
				ans2 += speed;
		}
		outf << "Case #" << i << ": " << ans1 << " " << ans2 << endl;
	}


	return 0;
}