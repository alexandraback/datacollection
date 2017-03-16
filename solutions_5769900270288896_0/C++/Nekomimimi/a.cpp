#include <iostream>
using namespace std;

int bits(long bits)
{
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
    return (bits & 0x0000ffff) + (bits >>16 & 0x0000ffff);
}

int main() {
	int T;
	cin >> T;

	for (int t=0;t<T;t++) {
		int R,C,N;
		cin >> R >> C >> N;
		if (N==0) {
			cout << "Case #"<< t+1 << ": " << 0 << endl;
			continue;
		}
		int cellNum = R*C;		

		int bit  = 1;
		for (int i= 0; i<cellNum;i++) {
			bit *= 2;
		}
		int ans = 99999999;


		for (int i=0; i< bit;i++) {

			if (bits(i) == N) {

				int count = 0;
				for (int j=0;j<R;j++) {
					for (int k=0;k<C-1;k++) {
						int first = R*k + j;
						int second = R*(k+1) + j;
						if ((i>>first) & 1 && (i>>second) & 1) {
							count ++;
						}
						
					}
				}
				for (int k=0;k<C;k++) {
					for (int j=0;j<R-1;j++) {
						int first = R*k + j;
						int second = R*k + j + 1;
						if ((i>>first) & 1 && (i>>second) & 1) {
							count ++;
						}
					}
				}
				ans = min(ans,count);
			}
		}
		cout << "Case #"<< t+1 << ": " << ans << endl;

	}






	return 0;
}