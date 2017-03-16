#include <iostream>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int caso = 1 ; caso <=T; caso++){
		int R, C, N;
		cin >> R >> C >> N;

		int needEmpty = R*C-N;
		int nOfWalls = (R-1)*C + (C-1)*R;
		//cout << ((R+1)/2)*((C+1)/2) + (R/2)*(C/2) << endl;
		cout << "Case #" << caso << ": ";
		if(R==1){
			if(N <= (C+1)/2){
				cout << 0 << endl;
				continue;
			}
			int n2 = ((C-1)/2);
			int n0 = (n2+1)/2;
			if(needEmpty <= n2){
				cout << nOfWalls - needEmpty*2 << endl;
				continue;
			}
			if(needEmpty <= n2 + n0){
				cout << nOfWalls - needEmpty*2 << endl;
				continue;
			}
			cout << nOfWalls - n2*2 - (needEmpty-n2-n0) << endl;
			continue;

		}
		if(C==1){
			if(N <= (R+1)/2){
				cout << 0 << endl;
				continue;
			}
			int n2 = ((R-1)/2);
			int n0 = (n2+1)/2;
			if(needEmpty <= n2){
				cout << nOfWalls - needEmpty*2 << endl;
				continue;
			}
			if(needEmpty <= n2 + n0){
				cout << nOfWalls - needEmpty*2 << endl;
				continue;
			}
			cout << nOfWalls - n2*2 - (needEmpty-n2-n0) << endl;
			continue;
		}
		if (N <= ((R+1)/2)*((C+1)/2) + (R/2)*(C/2)){
			cout << 0 << endl;
			continue;
		}
		



		int r = R-2, c = C-2;
		int n41 = ((r+1)/2)*((c+1)/2) + (r/2)*(c/2);
		int n42 = ((r+1)/2)*(c/2) + (r/2)*((c+1)/2);

		//cout << endl << "n41=" << n41 << ", n42=" << n42 << endl;
		if(needEmpty <= n41){
			cout << (nOfWalls - needEmpty*4) << endl;
			continue;
		}
		int n31 = 0, n32 = 0;
		int n21, n22;
		n21 = n22 = R*2 + C*2 - 4;
		if(c%2 == 0){
			n31 += r;
			n21 -= r; 
			n32 += r;
			n22 -= r;
		}else{
			n31 += (r/2)*2;
			n21 -= (r/2)*2;
			n32 += ((r+1)/2)*2;
			n22 -= ((r+1)/2)*2;
		}
		if(r%2 == 0){
			n31 += c;
			n21 -= c;
			n32 += c;
			n22 -= c;
		}else{
			n31 += (c/2)*2;
			n21 -= (c/2)*2;
			n32 += ((c+1)/2)*2;
			n22 -= ((c+1)/2)*2;
		}

		//cout << "n31=" << n31 << ", n32=" << n32 << endl;
		//cout << "n21=" << n21 << ", n22=" << n22 << endl;
		if(needEmpty <= n41 + n31 && needEmpty <= n42 + n32){
			int op1 = n41*4 + (needEmpty - n41)*3;
			int op2 = n42*4 + (needEmpty - n42)*3;
			if(op1 > op2){
				cout << nOfWalls - op1 << endl;
				continue;
			}else{
				cout << nOfWalls - op2 << endl;
				continue;
			}
		}
		if(needEmpty <= n41 + n31){
			cout << nOfWalls - (n41*4 + (needEmpty - n41)*3) << endl;
			continue;
		}
		if(needEmpty <= n42 + n32){
			cout << nOfWalls - (n42*4 + (needEmpty - n42)*3) << endl;
			continue;
		}

		int op1 = n41*4 + n31*3 + (needEmpty - n41 - n31)*2;
		int op2 = n42*4 + n32*3 + (needEmpty - n42 - n32)*2;

		if(op1 > op2){
			cout << nOfWalls - op1 << endl;
			continue;
		}else{
			cout << nOfWalls - op2 << endl;
			continue;
		}

		cout << "agh" << endl;


	}
}